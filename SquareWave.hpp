//
//  SquareWave.hpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#ifndef SquareWave_hpp
#define SquareWave_hpp

#include <stdio.h>
#include "IWave.hpp"

class SquareWave : public IWave
{
public:
    friend class Oscillator;
protected:
    SquareWave() :
    IWave() { updateIncrement(); };

    virtual void generate(double* buffer, int nFrames);
    virtual double nextSample();
};

#endif /* SquareWave_hpp */
