module alu(
    input wire [7:0] bus_in,
    input wire [2:0] op,
    input wire c_in,
    input wire set,
    input wire compute,
    input wire clk, 

    output wire [7:0] bus_out,
    output reg z,
    output reg c_out
);

    reg [7:0] temp_reg;
    reg [7:0] result_reg;

    always @(posedge clk) begin
        if (set) begin
            temp_reg <= bus_in;
        end

        if (compute) begin
            case (op)
                3'b000: {c_out, result_reg} <= temp_reg + bus_in + c_in;
                3'b001: {c_out, result_reg} <= {1'b0, temp_reg} - {1'b0, bus_in};
                3'b010: begin result_reg <= temp_reg & bus_in; c_out <= 1'b0; end
                3'b011: begin result_reg <= temp_reg | bus_in; c_out <= 1'b0; end
                3'b100: begin result_reg <= temp_reg ^ bus_in; c_out <= 1'b0; end
                3'b101: {c_out, result_reg} <= temp_reg << 1;
                3'b110: begin
                    c_out <= temp_reg[0];
                    result_reg <= temp_reg >> 1;
                end
                default: begin result_reg <= bus_in; c_out <= 1'b0; end
            endcase
        end
    end

    assign bus_out = result_reg;

    always @* begin
        z = (result_reg == 8'h00);
    end
endmodule