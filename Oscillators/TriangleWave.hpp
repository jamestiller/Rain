//
//  TriangleWave.hpp
//  Rain
//
//  Created by James Tiller on 2/25/16.
//
//

#ifndef TriangleWave_hpp
#define TriangleWave_hpp

#include <stdio.h>
#include "IWave.hpp"

class TriangleWave : public IWave
{
public:
    friend class Oscillator;
protected:
    TriangleWave() :
    IWave() { updateIncrement(); };
    virtual void generate(double* buffer, int nFrames);
    virtual double nextSample();
};

#endif /* TriangleWave_hpp */
