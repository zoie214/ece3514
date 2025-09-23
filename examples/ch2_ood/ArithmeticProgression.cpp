//ArithmeticProgression.cpp
#include "ArithmeticProgression.hpp"

int main() {
    // Test base Progression (default increment +1)
    Progression p1;
    std::cout << "Default Progression starting at 0 (+1 each step):\n";
    p1.print_progression(10);

    // Test base Progression starting at 5
    Progression p2(5);
    std::cout << "Default Progression starting at 5 (+1 each step):\n";
    p2.print_progression(10);

    // Test ArithmeticProgression with step size 5, starting at 0
    ArithmeticProgression ap1(5);
    std::cout << "Arithmetic Progression starting at 0 (+5 each step):\n";
    ap1.print_progression(10);

    // Test ArithmeticProgression with step size 3, starting at 10
    ArithmeticProgression ap2(3, 10);
    std::cout << "Arithmetic Progression starting at 10 (+3 each step):\n";
    ap2.print_progression(10);

    return 0;
}
