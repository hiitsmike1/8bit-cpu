// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(halted,0,0);
    VL_OUT8(addr,7,0);
    VL_OUT8(wdata,7,0);
    VL_OUT8(mem_we,0,0);
    VL_OUT8(rdata,7,0);
    CData/*7:0*/ top__DOT__addr_int;
    CData/*7:0*/ top__DOT__wdata_int;
    CData/*7:0*/ top__DOT__rdata_int;
    CData/*0:0*/ top__DOT__mem_we_int;
    CData/*7:0*/ top__DOT__cpu0__DOT__A;
    CData/*7:0*/ top__DOT__cpu0__DOT__B;
    CData/*7:0*/ top__DOT__cpu0__DOT__PC;
    CData/*7:0*/ top__DOT__cpu0__DOT__IR;
    CData/*7:0*/ top__DOT__cpu0__DOT__OP;
    CData/*0:0*/ top__DOT__cpu0__DOT__Z;
    CData/*0:0*/ top__DOT__cpu0__DOT__C;
    CData/*2:0*/ top__DOT__cpu0__DOT__state;
    CData/*7:0*/ top__DOT__cpu0__DOT__alu_y;
    CData/*0:0*/ top__DOT__cpu0__DOT__alu_z;
    CData/*0:0*/ top__DOT__cpu0__DOT__alu_c;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 256> top__DOT__ram0__DOT__mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
