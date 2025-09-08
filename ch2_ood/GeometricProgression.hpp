//GeometricProgression.hpp
#pragma once

#include "Progression.hpp"

class GeometricProgression : public Progression {
    protected:
        long base{2};

        // Multiply the current value by the geometric base
        virtual void advance() {
            current *= base;
        }

    public:
        // Constructs a geometric progression with given base and start
        GeometricProgression(long b=2, long start=1) 
        : Progression{start}, base{b} {}
};