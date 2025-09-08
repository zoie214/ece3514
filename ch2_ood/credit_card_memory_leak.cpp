//credit_card_memory_leak.cpp

#include "credit_card_memory_leak.hpp"

int main() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    // ... use wallet ...

    // Delete via base pointer
    for (auto* c : wallet) 
        delete c;
}
