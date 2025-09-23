//FibonacciProgression.hpp
#pragma once

#include "Progression.hpp"

class FibonacciProgression : public Progression {
    protected:
        long prev;

        // Replaces (prev,current) with (current,current+prev)
        virtual void advance() {
            long temp{prev};
            prev = current;
            current += temp;
        }

    public:
        // Constructs a Fibonacci sequence using the given first and second values
        FibonacciProgression(long first=0, long second=1) 
        : Progression{first}, prev{second - first} {}
};

