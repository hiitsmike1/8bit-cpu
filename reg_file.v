module reg_file(
    input wire clk,
    input wire rst,

    input wire set_reg,
    input wire [1:0] reg_sel,

    input wire [7:0] bus_in,
    output reg [7:0] bus_out
);
    //Four 8-bit registers
    reg [7:0] registers [0:3];

    //Sequential Logic for writing to register values
    always @(posedge clk or posedge rst) begin
        if (rst) begin 
            registers[0] <= 8'h00;
            registers[1] <= 8'h00;
            registers[2] <= 8'h00;
            registers[3] <= 8'h00;
        end 
        else if (set_reg) begin
            registers[reg_sel] <= bus_in;
        end
    end

    //Combinational Logic for Reading Registers
    always @(*) begin
        bus_out = registers[reg_sel];
    end
endmodule