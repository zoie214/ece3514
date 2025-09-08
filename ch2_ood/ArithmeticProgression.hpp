//ArithmeticProgression.hpp
#pragma once

#include "Progression.hpp"

class ArithmeticProgression : public Progression {
    protected:
        long stepsize;

        // Adds the arithmetic increment to the current value
        virtual void advance() {
            current += stepsize;
        }

    public:
        //stepsize is increment
        ArithmeticProgression(long stepsize=1, long start=0) 
        : Progression{start}, stepsize{stepsize} {}
};