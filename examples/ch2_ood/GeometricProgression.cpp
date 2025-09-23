//GeometricProgression.cpp

#include "GeometricProgression.hpp"

int main() {
    // Test GeometricProgression with default base 2, starting at 1
    GeometricProgression gp1;
    std::cout << "Geometric Progression starting at 1 (×2 each step):\n";
    gp1.print_progression(10);

    // Test GeometricProgression with base 3, starting at 1
    GeometricProgression gp2(3);
    std::cout << "Geometric Progression starting at 1 (×3 each step):\n";
    gp2.print_progression(10);

    // Test GeometricProgression with base 5, starting at 2
    GeometricProgression gp3(5, 2);
    std::cout << "Geometric Progression starting at 2 (×5 each step):\n";
    gp3.print_progression(10);

    return 0;
}