/*
 * Copyright (c) 2016-2017 ARM Limited
 * All rights reserved
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: David Guillen Fandos
 */

#ifndef __SIM_MATHEXPR_POWERMODEL_PM_HH__
#define __SIM_MATHEXPR_POWERMODEL_PM_HH__

#include <unordered_map>

#include "params/MathExprPowerModel.hh"
#include "sim/mathexpr.hh"
#include "sim/power/power_model.hh"

namespace Stats {
    class Info;
}

/**
 * A Equation power model. The power is represented as a combination
 * of some stats and automatic variables (like temperature).
 */
class MathExprPowerModel : public PowerModelState
{
  public:

    typedef MathExprPowerModelParams Params;
    MathExprPowerModel(const Params *p);

    /**
     * Get the dynamic power consumption.
     *
     * @return Power (Watts) consumed by this object (dynamic component)
     */
    double getDynamicPower() const { return eval(dyn_expr); }
    
    double getDynamicPowerGc() const { return eval(dyn_expr_gc); }

    double getDynamicPower_0() const { return eval(dyn_expr_0); }

    double getDynamicPower_1() const { return eval(dyn_expr_1); }

    double getDynamicPower_2() const { return eval(dyn_expr_2); }

    double getDynamicPower_3() const { return eval(dyn_expr_3); }

    double getDynamicPower_4() const { return eval(dyn_expr_4); }

    double getDynamicPower_5() const { return eval(dyn_expr_5); }

    double getDynamicPower_6() const { return eval(dyn_expr_6); }

    double getDynamicPower_7() const { return eval(dyn_expr_7); }

    /**
     * Get the static power consumption.
     *
     * @return Power (Watts) consumed by this object (static component)
     */
    double getStaticPower() const { return eval(st_expr); }

    double getStaticPowerGc() const { return eval(st_expr_gc); }

    double getStaticPower_0() const { return eval(st_expr_0); }

    double getStaticPower_1() const { return eval(st_expr_1); }

    double getStaticPower_2() const { return eval(st_expr_2); }

    double getStaticPower_3() const { return eval(st_expr_3); }

    double getStaticPower_4() const { return eval(st_expr_4); }

    double getStaticPower_5() const { return eval(st_expr_5); }

    double getStaticPower_6() const { return eval(st_expr_6); }

    double getStaticPower_7() const { return eval(st_expr_7); }

    /**
     * Get the value for a variable (maps to a stat)
     *
     * @param name Name of the variable to retrieve the value from
     *
     * @return Power (Watts) consumed by this object (static component)
     */
    double getStatValue(const std::string & name) const;

    void startup();

    void regStats();

  private:
    /**
     * Evaluate an expression in the context of this object, fatal if
     * evaluation fails.
     *
     * @param expr Expression to evaluate
     * @return Value of expression.
     */
    double eval(const MathExpr &expr) const;

    /**
     * Evaluate an expression in the context of this object, set
     * failed if evaluation failed.
     *
     * @param expr Expression to evaluate
     * @return Value of expression.
     */
    double tryEval(const MathExpr &expr) const;

    // Math expressions for dynamic and static power
    MathExpr dyn_expr, st_expr;

    // Math expressions for dynamic and static power during gc
    MathExpr dyn_expr_gc, st_expr_gc;

    MathExpr dyn_expr_0;
    MathExpr st_expr_0;

    MathExpr dyn_expr_1;
    MathExpr st_expr_1;

    MathExpr dyn_expr_2;
    MathExpr st_expr_2;

    MathExpr dyn_expr_3;
    MathExpr st_expr_3;

    MathExpr dyn_expr_4;
    MathExpr st_expr_4;

    MathExpr dyn_expr_5;
    MathExpr st_expr_5;

    MathExpr dyn_expr_6;
    MathExpr st_expr_6;

    MathExpr dyn_expr_7;
    MathExpr st_expr_7;

    // Basename of the object in the gem5 stats hierachy
    std::string basename;

    // Map that contains relevant stats for this power model
    std::unordered_map<std::string, Stats::Info*> stats_map;

    // Did the expression fail to evaluate (e.g., because a stat value
    // can't be resolved)
    mutable bool failed;
};

#endif
