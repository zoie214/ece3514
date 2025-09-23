//credit_card.cpp

#include "credit_card.hpp"

int main1() {
    PredatoryCreditCard card(
        "John Doe",
        "Bank of Nowhere",
        "1234 5678 9012",
        5000,               // limit
        0.0,             // initial balance
        0.36                // APR = 36%
    );

    std::cout << "Initial card info:\n";
    std::cout << card << "\n";

    if (card.charge(200)) {
        std::cout << "Charged $200 successfully.\n";
    } else {
        std::cout << "Charge of $200 denied.\n";
    }

    if (card.charge(10000)) {
        std::cout << "Charged $10000 successfully.\n";
    } else {
        std::cout << "Charge of $10000 denied. $5 penalty applied.\n";
    }

    std::cout << "\nCard info after charges:\n";
    std::cout << card << "\n";

    // Process monthly interest
    card.process_month();
    std::cout << "After processing one month of interest:\n";
    std::cout << card << "\n";

    // Make a payment
    card.make_payment(300);
    std::cout << "After making a $300 payment:\n";
    std::cout << card << "\n";

    return 0;
}

int main2() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    //make_payment is only in base class
    wallet[0]->make_payment(100);//from CreditCard
    wallet[1]->make_payment(100);//from CreditCard

    delete wallet[0];
    delete wallet[1];

    return 0;
}


int main3() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    //make_payment in base class is without penalty
    //make_payment in child class is with penalty
    wallet[0]->charge(10000);//from CreditCard
    wallet[1]->charge(10000);//from CreditCard

    delete wallet[0];
    delete wallet[1];

    return 0;
}



int main() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    //process_month is a new function added in child class
    //not allowed - compilation error
    //wallet[1]->process_month();

    delete wallet[0];
    delete wallet[1];

    return 0;
}