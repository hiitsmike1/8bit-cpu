module ram(
    input wire clk,
    input wire [7:0] bus_in,
    input wire set_addr,
    input wire set_data,

    output wire [7:0] bus_out
);

    reg [7:0] mem [0:255];

    reg [7:0] MAR; 

    always @(posedge clk) begin
        if (set_addr) begin
            MAR <= bus_in;
        end

        if (set_data) begin
            mem[MAR] <= bus_in;
        end
    end

    assign bus_out = mem[MAR];
endmodule
