//
//  IWave.hpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#ifndef IWave_hpp
#define IWave_hpp

#include <stdio.h>
#include <math.h>

class IWave
{
public:
    friend class Oscillator;
protected:
    IWave() :
    mPI(2*acos(0.0)),
    twoPI(2 * mPI),
    mFrequency(440.0),
    mSampleRate(44100.0),
    mPitchMod(0.0),
    mPhase(0.0) { updateIncrement(); };
    virtual ~IWave() {} // Should a subclass allocate additional memory

    virtual void generate(double* buffer, int nFrames);
    virtual double nextSample();
    void updateIncrement();
    void reset();
    void phaseIncrement();

    const double mPI;
    const double twoPI;
    double mFrequency;
    double mSampleRate;
    double mPitchMod;
    double mPhase;
    double mPhaseIncrement;
};

#endif /* IWave_hpp */
