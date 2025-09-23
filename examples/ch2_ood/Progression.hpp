//Progression.hpp
#pragma once

#include <iostream>

class Progression {
    protected:
        long current;
        virtual void advance();

    public:
        Progression(long start = 0);
        virtual ~Progression();
        long next_value();
        void print_progression(int n);
};

// Advances the current value to the next value of the progression
// we declare this virtual, expecting it to be overridden
// default implementation is to increase by 1
void Progression::advance() {
    current++;
}

// Constructs a progression with given start value (default: 0)
Progression::Progression(long start) : current{start} {}

// virtual destructor                                            
Progression::~Progression() = default;

// Returns the next value of the progression
long Progression::next_value() {
    long answer{current};
    advance();  // the protected call updates the current value
    return answer;
}

// Prints the next n values of the progression, separate by spaces
void Progression::print_progression(int n) {
    std::cout << next_value();  //first value
    for (int j{1}; j<n; j++)
        std::cout << " " << next_value(); //other values
    std::cout << "\n";
}

