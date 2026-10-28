# 8-bit CPU in Verilog
 
A custom 8-bit CPU designed from scratch in Verilog: my own instruction set, a 4-register file, a small RAM, an ALU, and a multi-cycle finite-state-machine control unit, all sharing a single data bus.
 
**Website:** https://hiitsmike1.github.io/michaelcrandall.github.io/
 
![Simulation waveform of a program running](docs/waveform.png)
 
## Overview
 
I built this CPU to understand how a processor works at the register-transfer level: how instructions are fetched and decoded, how a control unit sequences the datapath, and how several blocks share one bus without fighting over it.
 
- **8-bit datapath** with a shared data bus
- **4-register file**
- **RAM** addressed through a 5-bit memory address register (MAR), giving **32 addressable words** 
- **ALU** supporting ADD, SUB, AND, OR, XOR, SHL, and SHR *(currently only ADD is reachable from an instruction; see Status)*
- **Multi-cycle control unit** (module `iu`) built as a finite-state machine
- **Custom instruction set:** LOAD, STORE, ADD
## Architecture
 
| Block | Module | Role |
|-------|--------|------|
| Register file | [`regfile`] | Four 8-bit registers |
| RAM | [`ram`] | Program and data storage, addressed through MAR |
| ALU | `alu` | Arithmetic and logic |
| Control unit | `iu` | FSM that holds PC, IR, and IR2 and generates every enable and load signal |
| Top level | [`cpu`] | Connects everything to the shared bus |
 

 
![Datapath block diagram](docs/block_diagram.png)
 
### Shared data bus
 
All blocks put their data on one 8-bit bus. Instead of true tri-state drivers, the bus is arbitrated by a priority mux driven by four enable signals from the control unit: `en_alu`, `en_ram`, `en_reg`, and `en_iu`. Only one block drives the bus in a given cycle. Separate `set_*` signals tell a block to latch whatever is on the bus.
 
## Instruction Set
 
| Instruction | Opcode `IR[7:5]` | Length | Effect |
|-------------|------------------|--------|--------|
| `LOAD Rn, [addr]`  | `001` | 2 bytes | `Rn = mem[addr]` |
| `ADD Ra, Rb`       | `010` | 1 byte  | `Ra = Ra + Rb` |
| `STORE Rn, [addr]` | `011` | 2 bytes | `mem[addr] = Rn` |
 
**ADD (1 byte):**
 
| Bits | Field |
|------|-------|
| `[7:5]` | opcode (`010`) |
| `[4:3]` | `reg_a`: first operand and destination |
| `[2:1]` | `reg_b`: second operand |
| `[0]` | unused |
 
**LOAD and STORE (2 bytes):**
 
| Byte | Bits | Field |
|------|------|-------|
| 1 | `[7:5]` | opcode (`001` LOAD, `011` STORE) |
| 1 | `[4:0]` | 5-bit memory address |
| 2 | `[1:0]` | register to load into or store from |
| 2 | `[7:2]` | unused |
 
## Control Unit
 
The FSM fetches one instruction byte at a time, then runs a path that depends on the opcode. The PC increments after each byte fetched.
 
| State | What happens |
|-------|--------------|
| FETCH1 | PC goes onto the bus and into MAR |
| FETCH2 | RAM drives the bus, IR latches the byte, PC increments |
| DECODE | ADD goes to ADD1; any other opcode goes to FETCH3 |
| ADD1 | `reg_a` goes onto the bus and into the ALU's first operand |
| ADD2 | `reg_b` goes onto the bus and the ALU computes |
| ADD3 | ALU result goes onto the bus and is written back to `reg_a` |
| FETCH3 | PC goes onto the bus and into MAR (second byte) |
| FETCH4 | RAM drives the bus, IR2 latches the byte, PC increments |
| EXEC1 | The address in `IR[4:0]` goes onto the bus and into MAR |
| EXEC2 | LOAD: RAM to register. STORE: register to RAM |
 
- **ADD takes 6 cycles** (FETCH1, FETCH2, DECODE, ADD1, ADD2, ADD3).
- **LOAD and STORE take 7 cycles** (FETCH1, FETCH2, DECODE, FETCH3, FETCH4, EXEC1, EXEC2).
![Control FSM state diagram](docs/fsm.png)
 
## Example Program
 
This program loads 25 and 10 from memory, adds them, and stores the result.
 
**Source and machine code**
 
| Address | Bytes | Instruction | Effect |
|---------|-------|-------------|--------|
| 0, 1 | `3E 00` | `LOAD R0, [30]` | R0 = 25 |
| 2, 3 | `3F 01` | `LOAD R1, [31]` | R1 = 10 |
| 4 | `42` | `ADD R0, R1` | R0 = 35 (`0x23`) |
| 5, 6 | `7D 00` | `STORE R0, [29]` | mem[29] = 35 |
 
**Data memory:** address 30 holds `0x19` and address 31 holds `0x0A`.
 
**How the bytes are built**
- `LOAD R0, [30]`: opcode `001`, address 30 = `11110`, so byte 1 = `0011 1110` = `3E`. Byte 2 selects register 0, so it is `00`.
- `LOAD R1, [31]`: `001` and `11111` give `3F`; register 1 gives `01`.
- `ADD R0, R1`: `010`, `reg_a` = `00`, `reg_b` = `01`, unused bit `0` give `0100 0010` = `42`.
- `STORE R0, [29]`: `011` and `11101` give `7D`; register 0 gives `00`.
**Expected result:** after the ADD finishes (20 cycles in), R0 = `0x23`. After the STORE (27 cycles in), memory address 29 also holds `0x23`.
 
Execution continues past the end of the program through zero bytes. Opcode `000` falls into the LOAD/STORE path and does nothing in EXEC2, so zeros act as harmless two-byte no-ops.
 
## Simulation
 

 
## Design Challenges
 
**Bus contention and timing hazards.** Early versions had overlapping datapath signals, so two blocks drove the shared bus at the same time and values were captured in the wrong cycle. [Describe how you found it in the waveform and how you fixed it, for example with the priority mux and by sequencing enables and loads in separate states.]
 
**Instruction encoding.** 
 
## Status and Next Steps
 
- **Working:**
- **Next:** moving the ALU operation into a second instruction byte, so every instruction is two bytes and the other ALU operations (SUB, AND, OR, XOR, SHL, SHR) can be used from programs
- **Idea:** porting the design to an FPGA board *(only keep this if you still plan to)*
## Repository Structure
 
 

 
## Related Projects
 
- [4-bit ALU from discrete transistors (RTL)](https://github.com/hiitsmike1/alu_rtl)
- [ALU in Verilog with Verilator](https://github.com/hiitsmike1/alu_verilator)
## Author
 
Michael Crandall, B.S. Electrical Engineering, University of Maryland (expected December 2028)
[LinkedIn](https://linkedin.com/in/crandall0327) · [Portfolio](https://hiitsmike1.github.io/michaelcrandall.github.io/)