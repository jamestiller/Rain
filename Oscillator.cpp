//
//  Oscillator.cpp
//  Rain
//
//  Created by James Tiller on 1/1/16.
//
//

#include "Oscillator.h"

void Oscillator::setMode(OscillatorMode mode) {
    if (mode == mOscillatorMode)
        return;
    
    IWave* nextState;
    
    switch (mode)
    {
        case OSCILLATOR_MODE_SINE:
            nextState = new SinWave();
            break;
        case OSCILLATOR_MODE_SAW:
            nextState = new SawWave();
            break;
        case OSCILLATOR_MODE_SQUARE:
            nextState = new SquareWave();
            break;
        case OSCILLATOR_MODE_TRIANGLE:
            nextState = new TriangleWave();
            break;
        default:
            nextState = new IWave();
            break;
    }
    
    nextState->mFrequency = state->mFrequency;
    nextState->mSampleRate = state->mSampleRate;
    nextState->mPitchMod = state->mPitchMod;
    nextState->mPhase = state->mPhase;
    nextState->mPhaseIncrement = state->mPhaseIncrement;
    std::swap(state, nextState);
    mOscillatorMode = mode;
    delete nextState;
}

void Oscillator::setFrequency(double frequency) {
    state->mFrequency = frequency;
    state->updateIncrement();
}

void Oscillator::setSampleRate(double sampleRate) {
    state->mSampleRate = sampleRate;
    state->updateIncrement();
}

void Oscillator::generate(double* buffer, int nFrames) {
    state->generate(buffer, nFrames);
}

double Oscillator::nextSample() {
    return state->nextSample();
}

void Oscillator::setPitchMod(double amount) {
    state->mPitchMod = amount;
    state->updateIncrement();
}
