//ProgressionAll.cpp

#include "Progression.hpp"
#include "ArithmeticProgression.hpp"
#include "GeometricProgression.hpp"
#include "FibonacciProgression.hpp"

int main() {
    /** Test program for the progression classes */
    Progression* prog;

    // test AritheticProgression
    std::cout << "Arithmetic progression with default increment: ";
    prog = new ArithmeticProgression();
    prog->print_progression(10);

    std::cout << "Arithmetic progression with increment 5: ";
    prog = new ArithmeticProgression(5);
    prog->print_progression(10);

    std::cout << "Arithmetic progression with increment 5 and start 2: ";
    prog = new ArithmeticProgression(5, 2);
    prog->print_progression(10);

    // test GeometricProgression
    std::cout << "Geometric progression with default base: ";
    prog = new GeometricProgression();
    prog->print_progression(10);

    std::cout << "Geometric progression with base 3: ";
    prog = new GeometricProgression(3);
    prog->print_progression(10);

    // test FibonacciProgression
    std::cout << "Fibonacci progression with default start values: ";
    prog = new FibonacciProgression();
    prog->print_progression(10);

    std::cout << "Fibonacci progression with start values 4 and 6: ";
    prog = new FibonacciProgression(4, 6);
    prog->print_progression(10);

    delete prog;

    return EXIT_SUCCESS;                   // successful execution
}

