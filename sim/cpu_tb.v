`timescale 1ns / 1ps

module cpu_tb;

    reg clk;
    reg rst;

    // Instantiate the CPU
    top dut (
        .clk(clk),
        .rst(rst)
    );

    // Generate a 10 ns clock (100 MHz)
    always #5 clk = ~clk;

    initial begin
        // Initialize clock and reset
        clk = 0;
        rst = 1;

        // Program: LOAD R0, [30]
        dut.ram0.mem[0] = 8'h20;
        dut.ram0.mem[1] = 8'h1E;

        // Program: LOAD R1, [31]
        dut.ram0.mem[2] = 8'h28;
        dut.ram0.mem[3] = 8'h1F;

        // Program: ADD R0, R1
        dut.ram0.mem[4] = 8'h42;
        dut.ram0.mem[5] = 8'h00;

        // Program: STORE R0, [29]
        dut.ram0.mem[6] = 8'h60;
        dut.ram0.mem[7] = 8'h1D;

        // Initialize data
        dut.ram0.mem[8'h1E] = 8'h10;
        dut.ram0.mem[8'h1F] = 8'h13;

        // Hold reset briefly
        #20;
        rst = 0;

        // Let the CPU execute
        #300;

        // Display results
        $display("R0 = %h", dut.reg0.registers[0]);
        $display("R1 = %h", dut.reg0.registers[1]);
        $display("RAM[29] = %h", dut.ram0.mem[8'h1D]);

        $finish;
    end

endmodule