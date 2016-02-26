//
//  SinWave.cpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#include "SinWave.hpp"

void SinWave::generate(double* buffer, int nFrames) {
    for (int i = 0; i < nFrames; i++) {
        buffer[i] = sin(mPhase);
        mPhase += mPhaseIncrement;
        while (mPhase >= twoPI) {
            mPhase -= twoPI;
        }
    }
}

double SinWave::nextSample() {
    double value = 0.0;
    value = sin(mPhase);
    phaseIncrement();
    return value;
}