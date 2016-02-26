//
//  TriangleWave.cpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#include "TriangleWave.hpp"

void TriangleWave::generate(double* buffer, int nFrames) {
    for (int i = 0; i < nFrames; i++) {
        double value = -1.0 + (2.0 * mPhase / twoPI);
        buffer[i] = 2.0 * (fabs(value) - 0.5);
        mPhase += mPhaseIncrement;
        while (mPhase >= twoPI) {
            mPhase -= twoPI;
        }
    }
}

double TriangleWave::nextSample() {
    double value = 0.0;
    value = -1.0 + (2.0 * mPhase / twoPI);
    value = 2.0 * (fabs(value) - 0.5);
    phaseIncrement();
    return value;
}

