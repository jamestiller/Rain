//
//  Voice.cpp
//  Rain
//
//  Created by James Tiller on 2/24/16.
//
//

#include "Voice.h"

double Voice::nextSample() {
    if (!isActive) return 0.0;
    
    double oscillatorOneOutput = mOscillatorOne.nextSample();
    double oscillatorTwoOutput = mOscillatorTwo.nextSample();
    double oscillatorSum = ((1 - mOscillatorMix) * oscillatorOneOutput) + (mOscillatorMix * oscillatorTwoOutput);
    
    double volumeEnvelopeValue = mVolumeEnvelope.nextSample();
    double filterEnvelopeValue = mFilterEnvelope.nextSample();
    
    mFilter.setCutoffMod(filterEnvelopeValue * mFilterEnvelopeAmount + mLFOValue * mFilterLFOAmount);
    
    mOscillatorOne.setPitchMod(mLFOValue * mOscillatorOnePitchAmount);
    mOscillatorTwo.setPitchMod(mLFOValue * mOscillatorTwoPitchAmount);
    
    return mFilter.process(oscillatorSum * volumeEnvelopeValue * mVelocity / 127.0);
}

void Voice::setFree() {
    isActive = false;
}

void Voice::reset() {
    mNoteNumber = -1;
    mVelocity = 0;
    mOscillatorOne.reset();
    mOscillatorTwo.reset();
    mVolumeEnvelope.reset();
    mFilterEnvelope.reset();
    mFilter.reset();
}