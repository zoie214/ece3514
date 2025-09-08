//FibonacciProgression.cpp

#include "FibonacciProgression.hpp"

int main() {
    // Test FibonacciProgression with default first=0, second=1
    FibonacciProgression fp1;
    std::cout << "Fibonacci Progression starting at 0, 1:\n";
    fp1.print_progression(10);

    // Test FibonacciProgression with first=4, second=6
    FibonacciProgression fp2(4, 6);
    std::cout << "Fibonacci Progression starting at 4, 6:\n";
    fp2.print_progression(10);

    // Test FibonacciProgression with first=2, second=5
    FibonacciProgression fp3(2, 5);
    std::cout << "Fibonacci Progression starting at 2, 5:\n";
    fp3.print_progression(10);

    return 0;
}
