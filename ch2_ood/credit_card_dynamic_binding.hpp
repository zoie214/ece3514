//credit_card_dynamic_binding.hpp

#pragma once

#include <string>
#include <iostream>
#include <cmath>

class CreditCard {
    private:
        std::string customer;
        std::string bank;
        std::string account;
        int limit;

    protected:
        double balance;

    public:
        CreditCard() = default;
        CreditCard(std::string cust, std::string bk, std::string acnt, int lim, double initial_bal=0.0);

        std::string get_customer() const;
        std::string get_bank() const;
        std::string get_account() const;
        int get_limit() const;
        double get_balance() const;

        virtual bool charge(double price);
        void make_payment(double amount);

        virtual void process_month(){};

        friend std::ostream& operator<<(std::ostream& out, const CreditCard& c);
};

class PredatoryCreditCard : public CreditCard {
    private:
        double apr;

    public:
        PredatoryCreditCard() = default;
        PredatoryCreditCard(std::string cust, std::string bk, std::string acnt, int lim, double initial_bal, double rate);

        void process_month(); // new function
        bool charge(double price); //Override
};


CreditCard::CreditCard(
    std::string cust, std::string bk, std::string acnt, int lim, double initial_bal)
    : customer{cust}, bank{bk}, account{acnt}, 
    limit{lim}, balance{initial_bal} {}


std::string CreditCard::get_customer() const {
    return customer; 
}

std::string CreditCard::get_bank() const { 
    return bank; 
}

std::string CreditCard::get_account() const { 
    return account; 
}

int CreditCard::get_limit() const {
    return limit; 
}

double CreditCard::get_balance() const {
    return balance; 
}

// Charges if within credit limit
bool CreditCard::charge(double price) {
    std::cout << "from CreditCard\n";
    if (price + balance > limit)
        return false;
    balance += price;
    return true;
}

// Processes customer payment to reduce the balance
void CreditCard::make_payment(double amount) { 
    std::cout << "from CreditCard\n";
    balance -= amount; 
}

// no scope resolution when friend
std::ostream& operator<<(std::ostream& out, const CreditCard& c) {
    out << "Customer = " << c.customer << "\n";
    out << "Bank = " << c.bank << "\n";
    out << "Account = " << c.account << "\n";
    out << "Balance = " << c.balance << "\n";
    out << "Limit = " << c.limit << "\n";
    return out;
}


// constructs a new predatory credit card.
PredatoryCreditCard::PredatoryCreditCard(
    std::string cust, std::string bk, 
    std::string acnt, int lim, double initial_bal, double rate)
    
    : CreditCard{cust, bk, acnt, lim, initial_bal}, apr{rate} {}


// A new function for assessing monthly interest charges
//monthly rate = (1 + APR)^(1/12) - 1
void PredatoryCreditCard::process_month() {
    std::cout << "from PredatoryCreditCard\n";
    if (balance > 0) { 
        double monthly_rate = pow(1 + apr, 1.0/12) - 1;
        balance += balance * monthly_rate;
    }
}

// Overriding the charge function
bool PredatoryCreditCard::charge(double price) {
    std::cout << "PredatoryCreditCard calling ...\n";
    bool is_success{CreditCard::charge(price)};
    if (!is_success)
        balance += 5; // assess a $5 penalty
    return is_success;
}