module ram(
    input wire clk,
    input wire [7:0] bus_in,
    input wire set_addr,
    input wire set_data,

    output reg [7:0] bus_out
);

    reg [7:0] mem [0:255];

    reg [4:0] MAR; 

    always @(posedge clk) begin
        if (set_addr) begin
            MAR <= bus_in[4:0];
        end
    end

    always @(posedge clk) begin
        if (set_data) begin
            mem[MAR] <= bus_in;
        end
    end

    always @(*) begin
        bus_out = mem[MAR];
    end
endmodule
