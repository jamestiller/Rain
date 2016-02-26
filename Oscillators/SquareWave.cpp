//
//  SquareWave.cpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#include "SquareWave.hpp"

void SquareWave::generate(double* buffer, int nFrames) {
    for (int i = 0; i < nFrames; i++) {
        if (mPhase <= mPI) {
            buffer[i] = 1.0;
        } else {
            buffer[i] = -1.0;
        }
        mPhase += mPhaseIncrement;
        while (mPhase >= twoPI) {
            mPhase -= twoPI;
        }
    }
}

double SquareWave::nextSample() {
    double value = 0.0;
    if (mPhase <= mPI) {
        value = 1.0;
    } else {
        value = -1.0;
    }
    phaseIncrement();
    return value;
}

