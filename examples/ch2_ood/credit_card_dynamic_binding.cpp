//credit_card_dynamic_binding.cpp

#include "credit_card_dynamic_binding.hpp"


int main() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    //charge in base class is without penalty
    //charge in child class is with penalty
    wallet[0]->charge(10000);//from CreditCard
    wallet[1]->charge(10000);//from PredatoryCreditCard

    delete wallet[0];
    delete wallet[1];

    return 0;
}

int main2() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    //process_month new function 
    //works as expected since virtual
    wallet[1]->process_month();//from PredatoryCreditCard

    delete wallet[0];
    delete wallet[1];

    return 0;
}