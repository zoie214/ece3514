// Progression.cpp
#include "Progression.hpp"

int main() {
    // Create a progression starting at 0
    Progression p1;
    std::cout << "Progression starting at 0:\n";
    p1.print_progression(10);

    // Create a progression starting at 5
    Progression p2(5);
    std::cout << "Progression starting at 5:\n";
    p2.print_progression(10);

    return 0;
}
