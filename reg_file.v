module reg_file(
    input wire clk,
    input wire rst,

    input wire set_reg,
    input wire [1:0] reg_sel,

    input wire [7:0] bus_in,
    output reg [7:0] bus_out
);

    reg [7:0] R0;
    reg [7:0] R1;
    reg [7:0] R2;
    reg [7:0] R3;

    always @(posedge clk or posedge rst) begin
        if (rst) begin 
            R0 <= 8'h00;
            R1 <= 8'h00;
            R2 <= 8'h00;
            R3 <= 8'h00;
        end else if (set_reg) begin
            case(reg_sel)
                2'b00: R0 <= bus_in;
                2'b01: R1 <= bus_in;
                2'b10: R2 <= bus_in;
                2'b11: R3 <= bus_in;
            endcase
        end
    end

    always @(*) begin
        case(reg_sel)
            2'b00: bus_out = R0;
            2'b01: bus_out = R1;
            2'b10: bus_out = R2;
            2'b11: bus_out = R3;
        endcase
    end
endmodule