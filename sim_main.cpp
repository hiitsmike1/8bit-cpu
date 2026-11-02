#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <cstdint>
#include <vector>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate top-level module (CPU + RAM + ALU)
    Vtop* top = new Vtop;

    // Waveform dump
    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("cpu_full_test.vcd");

    // Initialize clock and reset
    top->clk = 0;
    top->rst = 1;

    // C++ RAM (256 bytes)
    uint8_t mem[256] = {0};

    // --- Test program ---
    // Format: opcode, operand (if needed)
    // We'll load values into A/B, perform ALU ops, store result, then HALT
    std::vector<uint8_t> prog;

    // Initialize test values
    uint8_t testA = 5;
    uint8_t testB = 3;

    // 1. Load A
    prog.push_back(0x10); // load A
    prog.push_back(testA);

    // 2. Load B
    prog.push_back(0x20); // load B
    prog.push_back(testB);

    // 3. ALU operations (example: opcodes 0x5 to 0xB in your CPU)
    for(uint8_t op = 0x5; op <= 0xB; op++) {
        prog.push_back(op);
    }

    // 4. Store result in memory
    prog.push_back(0x40); // store A to address in OP
    prog.push_back(0x80); // example address 0x80

    // 5. HALT
    prog.push_back(0xF0);

    // Load program into memory
    for(size_t i = 0; i < prog.size(); i++)
        mem[i] = prog[i];

    // Simulation parameters
    const uint64_t max_cycles = 200;
    for(uint64_t sim_time = 0; sim_time < max_cycles; sim_time++) {
        // Toggle clock
        top->clk = !top->clk;

        // Deassert reset after 2 cycles
        if(sim_time == 2) top->rst = 0;

        // Drive RAM interface
        if(top->mem_we) mem[top->addr] = top->wdata;
        top->rdata = mem[top->addr];

        // Evaluate CPU + RAM
        top->eval();

        // Dump waveform
        tfp->dump(sim_time);

        // Optional: print CPU registers & memory
        std::cout << "Cycle " << sim_time
                  << " addr=" << (int)top->addr
                  << " we=" << top->mem_we
                  << " wdata=" << (int)top->wdata
                  << " rdata=" << (int)top->rdata
                  << " halted=" << top->halted
                  << std::endl;

        // Stop simulation if CPU halts
        if(top->halted) {
            std::cout << "CPU halted at cycle " << sim_time << std::endl;

            // Self-check: verify result in memory
            uint8_t expected = 0; // replace with expected ALU result if needed
            uint8_t actual = mem[0x80]; // stored result
            if(actual == (testA + testB)) {
                std::cout << "ALU ADD test passed: " << (int)actual << std::endl;
            } else {
                std::cout << "ALU ADD test FAILED! got=" << (int)actual
                          << " expected=" << (int)(testA + testB) << std::endl;
            }
            break;
        }
    }

    // Cleanup
    top->final();
    tfp->close();
    delete tfp;
    delete top;

    std::cout << "Full CPU testbench simulation finished!" << std::endl;
    return 0;
}
