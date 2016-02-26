//
//  SawWave.cpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#include "SawWave.hpp"

void SawWave::generate(double* buffer, int nFrames) {
    for (int i = 0; i < nFrames; i++) {
        buffer[i] = 1.0 - (2.0 * mPhase / twoPI);
        mPhase += mPhaseIncrement;
        while (mPhase >= twoPI) {
            mPhase -= twoPI;
        }
    }
}

double SawWave::nextSample() {
    double value = 0.0;
    value = 1.0 - (2.0 * mPhase / twoPI);
    phaseIncrement();
    return value;
}