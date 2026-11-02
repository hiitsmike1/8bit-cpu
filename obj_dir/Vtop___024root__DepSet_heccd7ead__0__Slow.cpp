// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    if (VL_UNLIKELY(VL_TESTPLUSARGS_I(std::string{"PROGHEX"}))) {
        VL_WRITEF("Loading prog.hex ...\n");
        VL_READMEM_N(true, 8, 256, 0, std::string{"prog.hex"}
                     ,  &(vlSelf->top__DOT__ram0__DOT__mem)
                     , 0, ~0ULL);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("obj_dir/../top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->addr = vlSelf->top__DOT__addr_int;
    vlSelf->wdata = vlSelf->top__DOT__wdata_int;
    vlSelf->mem_we = vlSelf->top__DOT__mem_we_int;
    vlSelf->rdata = vlSelf->top__DOT__rdata_int;
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
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->halted = VL_RAND_RESET_I(1);
    vlSelf->addr = VL_RAND_RESET_I(8);
    vlSelf->wdata = VL_RAND_RESET_I(8);
    vlSelf->mem_we = VL_RAND_RESET_I(1);
    vlSelf->rdata = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__addr_int = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__wdata_int = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__rdata_int = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__mem_we_int = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cpu0__DOT__A = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__cpu0__DOT__B = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__cpu0__DOT__PC = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__cpu0__DOT__IR = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__cpu0__DOT__OP = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__cpu0__DOT__Z = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cpu0__DOT__C = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cpu0__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__cpu0__DOT__alu_y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__cpu0__DOT__alu_z = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cpu0__DOT__alu_c = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
