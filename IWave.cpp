//
//  IWave.cpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//  Default Implementation is a Sin Wave

#include "IWave.hpp"

void IWave::generate(double* buffer, int nFrames) {
    for (int i = 0; i < nFrames; i++) {
        buffer[i] = sin(mPhase);
        mPhase += mPhaseIncrement;
        while (mPhase >= twoPI) {
            mPhase -= twoPI;
        }
    }
}

void IWave::updateIncrement() {
    double pitchModAsFrequency = pow(2.0, fabs(mPitchMod) * 14.0) - 1;
    if (mPitchMod < 0) {
        pitchModAsFrequency = -pitchModAsFrequency;
    }
    double calculatedFrequency = fmin(fmax(mFrequency + pitchModAsFrequency, 0), mSampleRate/2.0);
    mPhaseIncrement = calculatedFrequency * 2 * mPI / mSampleRate;
}

double IWave::nextSample() {
    double value = 0.0;
    value = sin(mPhase);
    mPhase += mPhaseIncrement;
    while (mPhase >= twoPI) {
        mPhase -= twoPI;
    }
    return value;
}

void IWave::reset() {
    mPhase = 0.0;
}

void IWave::phaseIncrement()
{
    mPhase += mPhaseIncrement;
    while (mPhase >= twoPI) {
        mPhase -= twoPI;
    }
}