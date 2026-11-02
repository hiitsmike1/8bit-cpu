// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__addr_int),8);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__wdata_int),8);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__rdata_int),8);
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__mem_we_int));
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__cpu0__DOT__A),8);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__cpu0__DOT__B),8);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__cpu0__DOT__PC),8);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__cpu0__DOT__IR),8);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__cpu0__DOT__OP),8);
        bufp->chgBit(oldp+9,(vlSelf->top__DOT__cpu0__DOT__Z));
        bufp->chgBit(oldp+10,(vlSelf->top__DOT__cpu0__DOT__C));
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__cpu0__DOT__state),3);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__cpu0__DOT__alu_y),8);
        bufp->chgBit(oldp+13,(vlSelf->top__DOT__cpu0__DOT__alu_z));
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__cpu0__DOT__alu_c));
        bufp->chgCData(oldp+15,((0xfU & ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                         >> 4U))),4);
    }
    bufp->chgBit(oldp+16,(vlSelf->clk));
    bufp->chgBit(oldp+17,(vlSelf->rst));
    bufp->chgBit(oldp+18,(vlSelf->halted));
    bufp->chgCData(oldp+19,(vlSelf->addr),8);
    bufp->chgCData(oldp+20,(vlSelf->wdata),8);
    bufp->chgBit(oldp+21,(vlSelf->mem_we));
    bufp->chgCData(oldp+22,(vlSelf->rdata),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
