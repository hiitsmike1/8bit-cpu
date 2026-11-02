// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vfunc_top__DOT__cpu0__DOT__needs_operand__0__Vfuncout;
    __Vfunc_top__DOT__cpu0__DOT__needs_operand__0__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir;
    __Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir = 0;
    CData/*7:0*/ __Vdly__top__DOT__cpu0__DOT__A;
    __Vdly__top__DOT__cpu0__DOT__A = 0;
    CData/*7:0*/ __Vdly__top__DOT__cpu0__DOT__PC;
    __Vdly__top__DOT__cpu0__DOT__PC = 0;
    CData/*7:0*/ __Vdly__top__DOT__cpu0__DOT__IR;
    __Vdly__top__DOT__cpu0__DOT__IR = 0;
    CData/*7:0*/ __Vdly__top__DOT__cpu0__DOT__OP;
    __Vdly__top__DOT__cpu0__DOT__OP = 0;
    CData/*0:0*/ __Vdly__top__DOT__cpu0__DOT__Z;
    __Vdly__top__DOT__cpu0__DOT__Z = 0;
    CData/*7:0*/ __Vdly__top__DOT__addr_int;
    __Vdly__top__DOT__addr_int = 0;
    CData/*2:0*/ __Vdly__top__DOT__cpu0__DOT__state;
    __Vdly__top__DOT__cpu0__DOT__state = 0;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__ram0__DOT__mem__v0;
    __Vdlyvdim0__top__DOT__ram0__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram0__DOT__mem__v0;
    __Vdlyvval__top__DOT__ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram0__DOT__mem__v0;
    __Vdlyvset__top__DOT__ram0__DOT__mem__v0 = 0;
    // Body
    __Vdly__top__DOT__cpu0__DOT__state = vlSelf->top__DOT__cpu0__DOT__state;
    __Vdly__top__DOT__cpu0__DOT__Z = vlSelf->top__DOT__cpu0__DOT__Z;
    __Vdly__top__DOT__cpu0__DOT__OP = vlSelf->top__DOT__cpu0__DOT__OP;
    __Vdly__top__DOT__cpu0__DOT__PC = vlSelf->top__DOT__cpu0__DOT__PC;
    __Vdly__top__DOT__addr_int = vlSelf->top__DOT__addr_int;
    __Vdly__top__DOT__cpu0__DOT__IR = vlSelf->top__DOT__cpu0__DOT__IR;
    __Vdly__top__DOT__cpu0__DOT__A = vlSelf->top__DOT__cpu0__DOT__A;
    __Vdlyvset__top__DOT__ram0__DOT__mem__v0 = 0U;
    if (vlSelf->top__DOT__mem_we_int) {
        __Vdlyvval__top__DOT__ram0__DOT__mem__v0 = vlSelf->top__DOT__wdata_int;
        __Vdlyvset__top__DOT__ram0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__ram0__DOT__mem__v0 = vlSelf->top__DOT__addr_int;
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__cpu0__DOT__A = 0U;
        vlSelf->top__DOT__cpu0__DOT__B = 0U;
        __Vdly__top__DOT__cpu0__DOT__PC = 0U;
        __Vdly__top__DOT__cpu0__DOT__IR = 0U;
        __Vdly__top__DOT__cpu0__DOT__OP = 0U;
        __Vdly__top__DOT__cpu0__DOT__Z = 0U;
        vlSelf->top__DOT__cpu0__DOT__C = 0U;
        vlSelf->halted = 0U;
        __Vdly__top__DOT__addr_int = 0U;
        vlSelf->top__DOT__mem_we_int = 0U;
        vlSelf->top__DOT__wdata_int = 0U;
        __Vdly__top__DOT__cpu0__DOT__state = 0U;
    } else {
        vlSelf->top__DOT__mem_we_int = 0U;
        if ((0U == (IData)(vlSelf->top__DOT__cpu0__DOT__state))) {
            __Vdly__top__DOT__addr_int = vlSelf->top__DOT__cpu0__DOT__PC;
            __Vdly__top__DOT__cpu0__DOT__state = 1U;
        } else if ((1U == (IData)(vlSelf->top__DOT__cpu0__DOT__state))) {
            __Vdly__top__DOT__cpu0__DOT__PC = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cpu0__DOT__PC)));
            if ((0xfU == (0xfU & ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                  >> 4U)))) {
                vlSelf->halted = 1U;
                __Vdly__top__DOT__cpu0__DOT__state = 7U;
            } else {
                __Vdly__top__DOT__cpu0__DOT__state 
                    = (([&]() {
                            __Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir 
                                = vlSelf->top__DOT__cpu0__DOT__IR;
                            __Vfunc_top__DOT__cpu0__DOT__needs_operand__0__Vfuncout 
                                = ((0x80U & (IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir))
                                    ? ((1U & ((IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir) 
                                              >> 6U)) 
                                       && ((1U & (~ 
                                                  ((IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir) 
                                                   >> 5U))) 
                                           || (1U & 
                                               (~ ((IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir) 
                                                   >> 4U)))))
                                    : ((0x40U & (IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir))
                                        ? ((1U & (~ 
                                                  ((IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir) 
                                                   >> 5U))) 
                                           && (1U & 
                                               (~ ((IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir) 
                                                   >> 4U))))
                                        : ((1U & ((IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir) 
                                                  >> 5U)) 
                                           || (1U & 
                                               ((IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__ir) 
                                                >> 4U)))));
                        }(), (IData)(__Vfunc_top__DOT__cpu0__DOT__needs_operand__0__Vfuncout))
                        ? 2U : 3U);
            }
            __Vdly__top__DOT__cpu0__DOT__IR = vlSelf->top__DOT__rdata_int;
        } else if ((2U == (IData)(vlSelf->top__DOT__cpu0__DOT__state))) {
            __Vdly__top__DOT__addr_int = vlSelf->top__DOT__cpu0__DOT__PC;
            __Vdly__top__DOT__cpu0__DOT__state = 5U;
        } else if ((5U == (IData)(vlSelf->top__DOT__cpu0__DOT__state))) {
            __Vdly__top__DOT__cpu0__DOT__PC = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cpu0__DOT__PC)));
            __Vdly__top__DOT__cpu0__DOT__OP = vlSelf->top__DOT__rdata_int;
            __Vdly__top__DOT__cpu0__DOT__state = 3U;
        } else if ((3U == (IData)(vlSelf->top__DOT__cpu0__DOT__state))) {
            if ((0x80U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                if ((0x40U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                    if ((0x20U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                      >> 4U)))) {
                            if ((1U & (~ (IData)(vlSelf->top__DOT__cpu0__DOT__Z)))) {
                                __Vdly__top__DOT__cpu0__DOT__PC 
                                    = vlSelf->top__DOT__cpu0__DOT__OP;
                            }
                        }
                    } else if ((0x10U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                        if (vlSelf->top__DOT__cpu0__DOT__Z) {
                            __Vdly__top__DOT__cpu0__DOT__PC 
                                = vlSelf->top__DOT__cpu0__DOT__OP;
                        }
                    } else {
                        __Vdly__top__DOT__cpu0__DOT__PC 
                            = vlSelf->top__DOT__cpu0__DOT__OP;
                    }
                } else {
                    __Vdly__top__DOT__cpu0__DOT__A 
                        = vlSelf->top__DOT__cpu0__DOT__alu_y;
                    __Vdly__top__DOT__cpu0__DOT__Z 
                        = vlSelf->top__DOT__cpu0__DOT__alu_z;
                    vlSelf->top__DOT__cpu0__DOT__C 
                        = vlSelf->top__DOT__cpu0__DOT__alu_c;
                    __Vdly__top__DOT__cpu0__DOT__state = 0U;
                }
            } else if ((0x40U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                if ((0x20U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                    __Vdly__top__DOT__cpu0__DOT__A 
                        = vlSelf->top__DOT__cpu0__DOT__alu_y;
                    __Vdly__top__DOT__cpu0__DOT__Z 
                        = vlSelf->top__DOT__cpu0__DOT__alu_z;
                    vlSelf->top__DOT__cpu0__DOT__C 
                        = vlSelf->top__DOT__cpu0__DOT__alu_c;
                    __Vdly__top__DOT__cpu0__DOT__state = 0U;
                } else if ((0x10U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                    __Vdly__top__DOT__cpu0__DOT__A 
                        = vlSelf->top__DOT__cpu0__DOT__alu_y;
                    __Vdly__top__DOT__cpu0__DOT__Z 
                        = vlSelf->top__DOT__cpu0__DOT__alu_z;
                    vlSelf->top__DOT__cpu0__DOT__C 
                        = vlSelf->top__DOT__cpu0__DOT__alu_c;
                    __Vdly__top__DOT__cpu0__DOT__state = 0U;
                } else {
                    __Vdly__top__DOT__addr_int = vlSelf->top__DOT__cpu0__DOT__OP;
                    vlSelf->top__DOT__wdata_int = vlSelf->top__DOT__cpu0__DOT__A;
                    vlSelf->top__DOT__mem_we_int = 1U;
                    __Vdly__top__DOT__cpu0__DOT__state = 0U;
                }
            } else if ((0x20U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                if ((0x10U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                    __Vdly__top__DOT__addr_int = vlSelf->top__DOT__cpu0__DOT__OP;
                    __Vdly__top__DOT__cpu0__DOT__state = 4U;
                } else {
                    vlSelf->top__DOT__cpu0__DOT__B 
                        = vlSelf->top__DOT__cpu0__DOT__OP;
                }
            } else if ((0x10U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
                __Vdly__top__DOT__cpu0__DOT__A = vlSelf->top__DOT__cpu0__DOT__OP;
            }
            if ((1U & (~ ((3U == (0xfU & ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                          >> 4U))) 
                          | (4U == (0xfU & ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                            >> 4U))))))) {
                __Vdly__top__DOT__cpu0__DOT__state = 0U;
            }
        } else if ((4U == (IData)(vlSelf->top__DOT__cpu0__DOT__state))) {
            __Vdly__top__DOT__cpu0__DOT__A = vlSelf->top__DOT__rdata_int;
            __Vdly__top__DOT__cpu0__DOT__Z = (0U == (IData)(vlSelf->top__DOT__rdata_int));
            vlSelf->top__DOT__cpu0__DOT__C = 0U;
            __Vdly__top__DOT__cpu0__DOT__state = 0U;
        }
    }
    vlSelf->top__DOT__cpu0__DOT__PC = __Vdly__top__DOT__cpu0__DOT__PC;
    vlSelf->top__DOT__cpu0__DOT__OP = __Vdly__top__DOT__cpu0__DOT__OP;
    vlSelf->top__DOT__cpu0__DOT__Z = __Vdly__top__DOT__cpu0__DOT__Z;
    vlSelf->top__DOT__cpu0__DOT__state = __Vdly__top__DOT__cpu0__DOT__state;
    vlSelf->top__DOT__cpu0__DOT__A = __Vdly__top__DOT__cpu0__DOT__A;
    vlSelf->top__DOT__cpu0__DOT__IR = __Vdly__top__DOT__cpu0__DOT__IR;
    vlSelf->mem_we = vlSelf->top__DOT__mem_we_int;
    vlSelf->wdata = vlSelf->top__DOT__wdata_int;
    if ((0x80U & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))) {
        vlSelf->top__DOT__cpu0__DOT__alu_c = ((1U & 
                                               (~ ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                                   >> 6U))) 
                                              && ((1U 
                                                   & ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                                      >> 5U)) 
                                                  && (1U 
                                                      & ((0x10U 
                                                          & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                          ? (IData)(vlSelf->top__DOT__cpu0__DOT__A)
                                                          : 
                                                         ((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                          >> 7U)))));
        vlSelf->top__DOT__cpu0__DOT__alu_y = (0xffU 
                                              & ((0x40U 
                                                  & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                  ? (IData)(vlSelf->top__DOT__cpu0__DOT__A)
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                   ? 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                    ? 
                                                   VL_SHIFTR_III(8,8,32, (IData)(vlSelf->top__DOT__cpu0__DOT__A), 1U)
                                                    : 
                                                   VL_SHIFTL_III(8,8,32, (IData)(vlSelf->top__DOT__cpu0__DOT__A), 1U))
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                    ^ (IData)(vlSelf->top__DOT__cpu0__DOT__B))
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                    | (IData)(vlSelf->top__DOT__cpu0__DOT__B))))));
    } else {
        vlSelf->top__DOT__cpu0__DOT__alu_c = ((1U & 
                                               ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                                >> 6U)) 
                                              && ((0x20U 
                                                   & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                   ? 
                                                  ((1U 
                                                    & (~ 
                                                       ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                                        >> 4U))) 
                                                   && (1U 
                                                       & (((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                           - (IData)(vlSelf->top__DOT__cpu0__DOT__B)) 
                                                          >> 8U)))
                                                   : 
                                                  ((1U 
                                                    & ((IData)(vlSelf->top__DOT__cpu0__DOT__IR) 
                                                       >> 4U)) 
                                                   && (1U 
                                                       & (((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                           + (IData)(vlSelf->top__DOT__cpu0__DOT__B)) 
                                                          >> 8U)))));
        vlSelf->top__DOT__cpu0__DOT__alu_y = (0xffU 
                                              & ((0x40U 
                                                  & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                  ? 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                   ? 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                    & (IData)(vlSelf->top__DOT__cpu0__DOT__B))
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                    - (IData)(vlSelf->top__DOT__cpu0__DOT__B)))
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->top__DOT__cpu0__DOT__IR))
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__cpu0__DOT__A) 
                                                    + (IData)(vlSelf->top__DOT__cpu0__DOT__B))
                                                    : (IData)(vlSelf->top__DOT__cpu0__DOT__A)))
                                                  : (IData)(vlSelf->top__DOT__cpu0__DOT__A)));
    }
    vlSelf->top__DOT__cpu0__DOT__alu_z = (0U == (IData)(vlSelf->top__DOT__cpu0__DOT__alu_y));
    vlSelf->top__DOT__rdata_int = vlSelf->top__DOT__ram0__DOT__mem
        [vlSelf->top__DOT__addr_int];
    if (__Vdlyvset__top__DOT__ram0__DOT__mem__v0) {
        vlSelf->top__DOT__ram0__DOT__mem[__Vdlyvdim0__top__DOT__ram0__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__ram0__DOT__mem__v0;
    }
    vlSelf->top__DOT__addr_int = __Vdly__top__DOT__addr_int;
    vlSelf->addr = vlSelf->top__DOT__addr_int;
    vlSelf->rdata = vlSelf->top__DOT__rdata_int;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("obj_dir/../top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("obj_dir/../top.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
