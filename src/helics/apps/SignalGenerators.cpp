/*
Copyright � 2017-2018,
Battelle Memorial Institute; Lawrence Livermore National Security, LLC; Alliance for Sustainable Energy, LLC
All rights reserved. See LICENSE file and DISCLAIMER for more details.
*/
#include "SignalGenerators.hpp"
#include <cmath>

constexpr double pi = 3.14159265358979323846;

namespace helics
{
namespace apps
{
void  RampGenerator::set(const std::string &parameter, double val)
{
    if (parameter == "level")
    {
        level = val;
        if (lastTime > keyTime)
        {
            keyTime = lastTime;
        }
    }
    else if (parameter == "ramp")
    {
        ramp = val;
        if (lastTime > keyTime)
        {
            keyTime = lastTime;
        }
    }
    else
    {
        SignalGenerator::set(parameter, val);
    }
}

defV RampGenerator::generate(Time signalTime)
{
    double newVal = level + ramp * (signalTime - keyTime);
    lastTime = signalTime;
    return newVal;
}


void  SineGenerator::set(const std::string &parameter, double val)
{
    if (parameter == "frequency")
    {
        frequency = val;
    }
    else if (parameter == "period")
    {
        frequency = 1.0 / val;
    }
    else if (parameter == "dfdt")
    {
        dfdt = val;
    }
    else if (parameter == "dadt")
    {
        dAdt = val;
    }
    else if (parameter == "amplitude")
    {
        Amplitude = val;
    }
    else if (parameter == "level")
    {
        level = val;
    }
    else if (parameter == "offset")
    {
        offset = val;
    }
    else
    {
        SignalGenerator::set(parameter, val);
    }
}

defV SineGenerator::generate(Time signalTime)
{
    auto dt = signalTime - lastTime;
    auto tdiff = signalTime - lastCycle;
    // account for the frequency shift
    frequency += dfdt * dt;
    Amplitude += dAdt * dt;
    // compute the sine wave component
    double newValue = level+Amplitude * sin(2.0 * pi * (frequency * tdiff) + offset);
    period = (frequency > 0.0) ? 1.0 / frequency : 1e36;
    while (tdiff > period)
    {
        tdiff -= period;
        lastCycle += period;
    }
    lastTime = signalTime;
    return newValue;
}

void  PhasorGenerator::set(const std::string &parameter, double val)
{
    if (parameter == "frequency")
    {
        frequency = val;
    }
    else if (parameter == "period")
    {
        frequency = 1.0 / val;
    }
    else if (parameter == "dfdt")
    {
        dfdt = val;
    }
    else if (parameter == "dadt")
    {
        dAdt = val;
    }
    else if (parameter == "amplitude")
    {
        Amplitude = val;
    }
    else if (parameter == "bias_real")
    {
        bias_real = val;
    }
    else if (parameter == "bias_imag")
    {
        bias_imag = val;
    }
    else if (parameter == "offset")
    {
        state *= std::polar(1.0, (val - offset));
        offset = val;
    }
    else
    {
        SignalGenerator::set(parameter, val);
    }
}

defV PhasorGenerator::generate(Time signalTime)
{
    auto dt = signalTime - lastTime;

    frequency += dfdt * dt;
    Amplitude += dAdt * dt;
    rotation = std::polar(1.0, frequency*dt * (2 * pi));
    state *= rotation;
    lastTime = signalTime;
    return Amplitude*state+std::complex<double>(bias_real,bias_imag);
}

}
}
