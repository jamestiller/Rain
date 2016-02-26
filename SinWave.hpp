//
//  SinWave.hpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#ifndef SinWave_hpp
#define SinWave_hpp

#include <stdio.h>
#include "IWave.hpp"

class SinWave : public IWave
{
public:
    friend class Oscillator;
protected:
    SinWave() :
    IWave() { updateIncrement(); };

    virtual void generate(double* buffer, int nFrames);
    virtual double nextSample();
};

#endif /* SinWave_hpp */
