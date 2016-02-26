//
//  SawWave.hpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#ifndef SawWave_hpp
#define SawWave_hpp

#include <stdio.h>
#include "IWave.hpp"

class SawWave : public IWave
{
public:
    friend class Oscillator;
protected:
    SawWave() :
    IWave() { updateIncrement(); };

    virtual void generate(double* buffer, int nFrames);
    virtual double nextSample();
};

#endif /* SawWave_hpp */
