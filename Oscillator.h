//
//  Oscillator.h
//  Rain
//
//  Created by James Tiller on 2/24/16.
//
//

#ifndef __Rain__Oscillator__
#define __Rain__Oscillator__

#include <math.h>
#include <algorithm>
#include "IWave.hpp"
#include "SinWave.hpp"
#include "SawWave.hpp"
#include "SquareWave.hpp"
#include "TriangleWave.hpp"

class Oscillator {
public:
    enum OscillatorMode {
        OSCILLATOR_MODE_SINE = 0,
        OSCILLATOR_MODE_SAW,
        OSCILLATOR_MODE_SQUARE,
        OSCILLATOR_MODE_TRIANGLE,
        kNumOscillatorModes
    };
    void setMode(OscillatorMode mode);
    void setFrequency(double frequency);
    void setSampleRate(double sampleRate);
    void generate(double* buffer, int nFrames);
    double nextSample();
    Oscillator() :
    state(new IWave()) { state->updateIncrement(); };
    ~Oscillator() { delete state; }
    void reset() { state->reset(); }
    void setPitchMod(double amount);
private:
    IWave* state;
    OscillatorMode mOscillatorMode;
};

#endif /* defined(__Rain__Oscillator__) */
