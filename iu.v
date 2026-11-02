module iu(
    input  wire clk,
    input  wire rst,
    input  wire [7:0] bus_in,

    output reg [7:0] bus_out,
    output wire [2:0] op,
    output reg en_alu, output reg set_alu,
    output reg en_reg, output reg set_reg,
    output reg [1:0] reg_sel,
    output reg en_ram, output reg set_ram_addr, output reg set_ram_data,
    output reg en_iu,
    output reg compute

);

    reg [7:0] PC;
    reg [7:0] IR;
    reg [7:0] IR2;   // second instruction byte: register select for LOAD/STORE

    assign op = IR2[7:5];          //ALU operation
    wire [2:0] opcode = IR[7:5];   //Chooses CPU operation (LOAD, STORE, ALU)

    wire [1:0] reg_a = IR2[4:3];   //Register A for operation
    wire [1:0] reg_b = IR2[2:1];   //Register B for operation
    wire [1:0] mem_reg = IR2[1:0]; // LOAD/STORE register 

    localparam FETCH1  = 4'b0000;
    localparam FETCH2  = 4'b0001;
    localparam DECODE  = 4'b0010;
    localparam ADD1    = 4'b0011;
    localparam ADD2    = 4'b0100;
    localparam ADD3    = 4'b0101;
    localparam FETCH3  = 4'b0110;  
    localparam FETCH4  = 4'b0111;  
    localparam EXEC1   = 4'b1000;  
    localparam EXEC2   = 4'b1001;  
    reg [3:0] current_state, next_state;

    localparam OP_LOAD  = 3'b001;
    localparam OP_ALU   = 3'b010;
    localparam OP_STORE = 3'b011;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            current_state <= FETCH1;
            PC <= 8'h00;
            IR <= 8'h00;
            IR2 <= 8'h00;
        end
        else begin
            current_state <= next_state;

            if (current_state == FETCH2) begin
                IR <= bus_in;
                PC <= PC + 1;
            end

            if (current_state == FETCH4) begin
                IR2 <= bus_in;
                PC <= PC + 1;
            end
        end
    end

    always @(*) begin 
        case (current_state)
            FETCH1:  next_state = FETCH2;
            FETCH2:  next_state = FETCH3;
            FETCH3:  next_state = FETCH4;
            FETCH4:  next_state = (opcode == OP_ALU) ? ALU1 : EXEC1; //Chooses which
            ALU1:    next_state = ALU2;
            ALU2:    next_state = ALU3;
            ALU3:    next_state = FETCH1;
            
            EXEC1:   next_state = EXEC2;
            EXEC2:   next_state = FETCH1;
            default: next_state = FETCH1;
        endcase
    end

    always @(*) begin

        en_alu = 1'b0; set_alu = 1'b0;
        en_ram = 1'b0; set_ram_addr = 1'b0; set_ram_data = 1'b0;
        en_reg = 1'b0; set_reg = 1'b0;
        en_iu = 1'b0;
        compute = 1'b0;
        reg_sel = 2'b00;
        bus_out = 8'h00;

        case (current_state)
            FETCH1: begin
                //Goes to RAM address based on PC
                bus_out = PC;
                en_iu = 1'b1;
                set_ram_addr = 1'b1;
            end

            FETCH2: begin
                //Grabs the first byte at address PC and stores it in IR
                en_ram = 1'b1;
            end

            FETCH3: begin
                //Goes to RAM address to grab second byte
                bus_out = PC;
                en_iu = 1'b1;
                set_ram_addr = 1'b1;
            end

            FETCH4: begin
                // same pattern as FETCH2, but stores into IR2
                en_ram = 1'b1;
            end

            ALU1: begin
                //Stores first number in temp reg in ALU
                reg_sel = reg_a;
                en_reg = 1'b1;
                set_alu = 1'b1;
            end

            ALU2: begin
                //Sets second number to bus and ALU stores answer
                reg_sel = reg_b;
                en_reg = 1'b1;
                compute = 1'b1;
            end

            ALU3: begin
                //Stores the answer back into the first register given.
                reg_sel = reg_a;
                en_alu = 1'b1;
                set_reg = 1'b1;
            end

            
            EXEC1: begin
                // address phase for LOAD/STORE: put operand address on bus
                bus_out = {3'b000, IR[4:0]};
                en_iu = 1'b1;
                set_ram_addr = 1'b1;
            end

            EXEC2: begin
                // operation phase for LOAD/STORE, register comes from IR2
                reg_sel = mem_reg;
                case (opcode)
                    OP_LOAD: begin
                        en_ram = 1'b1;
                        set_reg = 1'b1;
                    end

                    OP_STORE: begin
                        en_reg = 1'b1;
                        set_ram_data = 1'b1;
                    end

                    default: begin
                    end
                endcase
            end

            default: begin
            end
        endcase
    end
endmodule