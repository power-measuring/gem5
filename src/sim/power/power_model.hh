/*
 * Copyright (c) 2016, 2018 ARM Limited
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

#ifndef __SIM_POWER_POWER_MODEL_HH__
#define __SIM_POWER_POWER_MODEL_HH__

#include "base/statistics.hh"
#include "enums/PMType.hh"
#include "params/PowerModel.hh"
#include "params/PowerModelState.hh"
#include "sim/probe/probe.hh"

class SimObject;
class ClockedObject;

/**
 * A PowerModelState is an abstract class used as interface to get power
 * figures out of SimObjects
 */
class PowerModelState : public SimObject
{
  public:

    typedef PowerModelStateParams Params;
    PowerModelState(const Params *p);

    /**
     * Get the dynamic power consumption.
     *
     * @return Power (Watts) consumed by this object (dynamic component)
     */
    virtual double getDynamicPower() const = 0;
    virtual double getDynamicPowerGc() const = 0;
    virtual double getDynamicPower_0() const = 0;
    virtual double getDynamicPower_1() const = 0;
    virtual double getDynamicPower_2() const = 0;
    virtual double getDynamicPower_3() const = 0;
    virtual double getDynamicPower_4() const = 0;
    virtual double getDynamicPower_5() const = 0;
    virtual double getDynamicPower_6() const = 0;
    virtual double getDynamicPower_7() const = 0;

    /**
     * Get the static power consumption.
     *
     * @return Power (Watts) consumed by this object (static component)
     */
    virtual double getStaticPower() const = 0;
    virtual double getStaticPowerGc() const = 0;
    virtual double getStaticPower_0() const = 0;
    virtual double getStaticPower_1() const = 0;
    virtual double getStaticPower_2() const = 0;
    virtual double getStaticPower_3() const = 0;
    virtual double getStaticPower_4() const = 0;
    virtual double getStaticPower_5() const = 0;
    virtual double getStaticPower_6() const = 0;
    virtual double getStaticPower_7() const = 0;
    /**
     * Temperature update.
     *
     * @param temp Current temperature of the HW part (Celsius)
     */
    virtual void setTemperature(double temp) { _temp = temp; }

    void setClockedObject(ClockedObject * clkobj) {
        clocked_object = clkobj;
    }

    void regStats() {
        dynamicPower
          .method(this, &PowerModelState::getDynamicPower)
          .name(params()->name + ".dynamic_energy")
          .desc("Dynamic energy for this object (J)")
        ;

        staticPower
          .method(this, &PowerModelState::getStaticPower)
          .name(params()->name + ".static_energy")
          .desc("Static energy for this object (J)")
        ;

        dynamicPowerGc
          .method(this, &PowerModelState::getDynamicPowerGc)
          .name(params()->name + ".dynamic_energy_gc")
          .desc("Dynamic energy during gc for this object (J)")
        ;

        staticPowerGc
          .method(this, &PowerModelState::getStaticPowerGc)
          .name(params()->name + ".static_energy_gc")
          .desc("Static energy during gc for this object (J)")
        ;

        dynamicPower_stage[0]
          .method(this, &PowerModelState::getDynamicPower_0)
          .name(params()->name + ".dynamic_energy_0")
          .desc("Dynamic energy during stage 0 for this object (J)")
        ;

        staticPower_stage[0]
          .method(this, &PowerModelState::getStaticPower_0)
          .name(params()->name + ".static_energy_0")
          .desc("Static energy during stage 0 for this object (J)")
        ;

        dynamicPower_stage[1]
          .method(this, &PowerModelState::getDynamicPower_1)
          .name(params()->name + ".dynamic_energy_1")
          .desc("Dynamic energy during stage 1 for this object (J)")
        ;

        staticPower_stage[1]
          .method(this, &PowerModelState::getStaticPower_1)
          .name(params()->name + ".static_energy_1")
          .desc("Static energy during stage 1 for this object (J)")
        ;

        dynamicPower_stage[2]
          .method(this, &PowerModelState::getDynamicPower_2)
          .name(params()->name + ".dynamic_energy_2")
          .desc("Dynamic energy during stage 2 for this object (J)")
        ;

        staticPower_stage[2]
          .method(this, &PowerModelState::getStaticPower_2)
          .name(params()->name + ".static_energy_2")
          .desc("Static energy during stage 2 for this object (J)")
        ;

        dynamicPower_stage[3]
          .method(this, &PowerModelState::getDynamicPower_3)
          .name(params()->name + ".dynamic_energy_3")
          .desc("Dynamic energy during stage 3 for this object (J)")
        ;

        staticPower_stage[3]
          .method(this, &PowerModelState::getStaticPower_3)
          .name(params()->name + ".static_energy_3")
          .desc("Static energy during stage 3 for this object (J)")
        ;

        dynamicPower_stage[4]
          .method(this, &PowerModelState::getDynamicPower_4)
          .name(params()->name + ".dynamic_energy_4")
          .desc("Dynamic energy during stage 4 for this object (J)")
        ;

        staticPower_stage[4]
          .method(this, &PowerModelState::getStaticPower_4)
          .name(params()->name + ".static_energy_4")
          .desc("Static energy during stage 4 for this object (J)")
        ;

        dynamicPower_stage[5]
          .method(this, &PowerModelState::getDynamicPower_5)
          .name(params()->name + ".dynamic_energy_5")
          .desc("Dynamic energy during stage 5 for this object (J)")
        ;

        staticPower_stage[5]
          .method(this, &PowerModelState::getStaticPower_5)
          .name(params()->name + ".static_energy_5")
          .desc("Static energy during stage 5 for this object (J)")
        ;

        dynamicPower_stage[6]
          .method(this, &PowerModelState::getDynamicPower_6)
          .name(params()->name + ".dynamic_energy_6")
          .desc("Dynamic energy during stage 6 for this object (J)")
        ;

        staticPower_stage[6]
          .method(this, &PowerModelState::getStaticPower_6)
          .name(params()->name + ".static_energy_6")
          .desc("Static energy during stage 6 for this object (J)")
        ;

        dynamicPower_stage[7]
          .method(this, &PowerModelState::getDynamicPower_7)
          .name(params()->name + ".dynamic_energy_7")
          .desc("Dynamic energy during stage 7 for this object (J)")
        ;

        staticPower_stage[7]
          .method(this, &PowerModelState::getStaticPower_7)
          .name(params()->name + ".static_energy_7")
          .desc("Static energy during stage 7 for this object (J)")
        ;


    }

  protected:
    Stats::Value dynamicPower, staticPower, dynamicPowerGc, staticPowerGc;
    Stats::Value dynamicPower_stage[8];
    Stats::Value staticPower_stage[8];
    /** Current temperature */
    double _temp;



    /** The clocked object we belong to */
    ClockedObject * clocked_object;
};

/**
 * @sa \ref gem5PowerModel "gem5 Power Model"
 *
 * A PowerModel is a class containing a power model for a SimObject.
 * The PM describes the power consumption for every power state.
 */
class PowerModel : public SimObject
{
  public:

    typedef PowerModelParams Params;
    PowerModel(const Params *p);

    /**
     * Get the dynamic power consumption.
     *
     * @return Power (Watts) consumed by this object (dynamic component)
     */
    double getDynamicPower() const;
    double getDynamicPowerGc() const;
    double getDynamicPower_0() const;
    double getDynamicPower_1() const;
    double getDynamicPower_2() const;
    double getDynamicPower_3() const;
    double getDynamicPower_4() const;
    double getDynamicPower_5() const;
    double getDynamicPower_6() const;
    double getDynamicPower_7() const;

    /**
     * Get the static power consumption.
     *
     * @return Power (Watts) consumed by this object (static component)
     */
    double getStaticPower() const;
    double getStaticPowerGc() const;
    double getStaticPower_0() const;
    double getStaticPower_1() const;
    double getStaticPower_2() const;
    double getStaticPower_3() const;
    double getStaticPower_4() const;
    double getStaticPower_5() const;
    double getStaticPower_6() const;
    double getStaticPower_7() const;

    void regStats() {
        dynamicPower
          .method(this, &PowerModel::getDynamicPower)
          .name(params()->name + ".dynamic_energy")
          .desc("Dynamic energy for this power state")
        ;

        staticPower
          .method(this, &PowerModel::getStaticPower)
          .name(params()->name + ".static_energy")
          .desc("Static energy for this power state")
        ;

        dynamicPowerGc
          .method(this, &PowerModel::getDynamicPowerGc)
          .name(params()->name + ".dynamic_energy_gc")
          .desc("Dynamic energy during gc for this power state")
        ;

        staticPowerGc
          .method(this, &PowerModel::getStaticPowerGc)
          .name(params()->name + ".static_energy_gc")
          .desc("Static energy during gc for this power state")
        ;

        dynamicPower_stage[0]
            .method(this, &PowerModel::getDynamicPower_0)
            .name(params()->name + ".dynamic_energy_0")
            .desc("Dynamic energy during stage 0 for this power state")
            ;

        staticPower_stage[0]
            .method(this, &PowerModel::getStaticPower_0)
            .name(params()->name + ".static_energy_0")
            .desc("Static energy during stage 0 for this power state")
            ;

        dynamicPower_stage[1]
            .method(this, &PowerModel::getDynamicPower_1)
            .name(params()->name + ".dynamic_energy_1")
            .desc("Dynamic energy during stage 1 for this power state")
            ;

        staticPower_stage[1]
            .method(this, &PowerModel::getStaticPower_1)
            .name(params()->name + ".static_energy_1")
            .desc("Static energy during stage 1 for this power state")
            ;

        dynamicPower_stage[2]
            .method(this, &PowerModel::getDynamicPower_2)
            .name(params()->name + ".dynamic_energy_2")
            .desc("Dynamic energy during stage 2 for this power state")
            ;

        staticPower_stage[2]
            .method(this, &PowerModel::getStaticPower_2)
            .name(params()->name + ".static_energy_2")
            .desc("Static energy during stage 2 for this power state")
            ;

        dynamicPower_stage[3]
            .method(this, &PowerModel::getDynamicPower_3)
            .name(params()->name + ".dynamic_energy_3")
            .desc("Dynamic energy during stage 3 for this power state")
            ;

        staticPower_stage[3]
            .method(this, &PowerModel::getStaticPower_3)
            .name(params()->name + ".static_energy_3")
            .desc("Static energy during stage 3 for this power state")
            ;

        dynamicPower_stage[4]
            .method(this, &PowerModel::getDynamicPower_4)
            .name(params()->name + ".dynamic_energy_4")
            .desc("Dynamic energy during stage 4 for this power state")
            ;

        staticPower_stage[4]
            .method(this, &PowerModel::getStaticPower_4)
            .name(params()->name + ".static_energy_4")
            .desc("Static energy during stage 4 for this power state")
            ;

        dynamicPower_stage[5]
            .method(this, &PowerModel::getDynamicPower_5)
            .name(params()->name + ".dynamic_energy_5")
            .desc("Dynamic energy during stage 5 for this power state")
            ;

        staticPower_stage[5]
            .method(this, &PowerModel::getStaticPower_5)
            .name(params()->name + ".static_energy_5")
            .desc("Static energy during stage 5 for this power state")
            ;

        dynamicPower_stage[6]
            .method(this, &PowerModel::getDynamicPower_6)
            .name(params()->name + ".dynamic_energy_6")
            .desc("Dynamic energy during stage 6 for this power state")
            ;

        staticPower_stage[6]
            .method(this, &PowerModel::getStaticPower_6)
            .name(params()->name + ".static_energy_6")
            .desc("Static energy during stage 6 for this power state")
            ;

        dynamicPower_stage[7]
            .method(this, &PowerModel::getDynamicPower_7)
            .name(params()->name + ".dynamic_energy_7")
            .desc("Dynamic energy during stage 7 for this power state")
            ;

        staticPower_stage[7]
            .method(this, &PowerModel::getStaticPower_7)
            .name(params()->name + ".static_energy_7")
            .desc("Static energy during stage 7 for this power state")
            ;

    }

    void setClockedObject(ClockedObject *clkobj);

    virtual void regProbePoints();

    void thermalUpdateCallback(const double & temp);

  protected:
    /** Listener class to catch thermal events */
    class ThermalProbeListener : public ProbeListenerArgBase<double>
    {
      public:
        ThermalProbeListener(PowerModel &_pm, ProbeManager *pm,
                      const std::string &name)
            : ProbeListenerArgBase(pm, name), pm(_pm) {}

        void notify(const double &temp)
        {
            pm.thermalUpdateCallback(temp);
        }

      protected:
        PowerModel &pm;
    };

    Stats::Value dynamicPower, staticPower, dynamicPowerGc, staticPowerGc;
    Stats::Value dynamicPower_stage[8];
    Stats::Value staticPower_stage[8];

    /** Actual power models (one per power state) */
    std::vector<PowerModelState*> states_pm;

    /** Listener to catch temperature changes in the SubSystem */
    std::unique_ptr<ThermalProbeListener> thermalListener;

    /** The subsystem this power model belongs to */
    SubSystem * subsystem;

    /** The clocked object we belong to */
    ClockedObject * clocked_object;

    /** The type of power model - collects all power, static or dynamic only */
    Enums::PMType power_model_type;
};

#endif
