//credit_card_memory_leak.hpp
#pragma once

#include <iostream>

class CreditCard {
    public:
        // Destructor NOT virtual → bad in polymorphic base
        ~CreditCard() { 
            std::cout << "~CreditCard\n"; 
        }
        
        // polymorphic class
        virtual bool charge(double) { 
            return true; 
        }
};

class PredatoryCreditCard : public CreditCard {
    // pretend dynamically allocated resource
    int* log_;
    public:
        PredatoryCreditCard(){ //allocate resource
            log_ = new int[1000];
        }
        ~PredatoryCreditCard() { // should free resource
            std::cout << "~PredatoryCreditCard (freeing)\n";
            delete[] log_;
        }
};

/*
~CreditCard
~CreditCard
*/
