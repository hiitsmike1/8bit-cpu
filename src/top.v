module top(
    input  wire clk,
    input  wire rst
);
    wire [7:0] data_bus;

    wire [7:0] alu_out;
    wire [7:0] ram_out;
    wire [7:0] reg_out;
    wire [7:0] iu_out;

    wire [1:0] reg_sel;

    wire [2:0] op;
    wire compute;
    wire carry_in;

    wire en_alu, set_alu;
    wire en_ram, set_ram_addr, set_ram_data;
    wire en_reg, set_reg;
    wire en_iu;

    assign data_bus = (en_alu) ? alu_out
                    : (en_ram) ? ram_out
                    : (en_reg) ? reg_out
                    : (en_iu) ? iu_out : 8'h00;


    alu alu0(
        .clk(clk),
        .bus_in(data_bus),
        .set(set_alu),
        .bus_out(alu_out),
        .op(op),
        .c_in(carry_in),
        .compute(compute),
        .rst(rst)
    );

    iu iu0(
        .clk(clk),
        .rst(rst),
        .bus_in(data_bus),
        .op(op),
        .bus_out(iu_out),
        .en_alu(en_alu), .set_alu(set_alu),
        .en_ram(en_ram), .set_ram_addr(set_ram_addr), .set_ram_data(set_ram_data),
        .en_iu(en_iu),
        .en_reg(en_reg), .set_reg(set_reg),
        .compute(compute),
        .reg_sel(reg_sel),
        .c_in(carry_in)
    );

    ram ram0(
        .clk(clk),
        .bus_in(data_bus),
        .set_addr(set_ram_addr),
        .set_data(set_ram_data),
        .bus_out(ram_out)
    );

    reg_file reg0(
        .clk(clk),
        .rst(rst),
        .bus_in(data_bus),
        .set_reg(set_reg),
        .bus_out(reg_out),
        .reg_sel(reg_sel)
    );

endmodule
