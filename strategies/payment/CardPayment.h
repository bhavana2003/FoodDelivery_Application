#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H

#include <iostream>
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class CardPayment : public PaymentStrategy {
    private:
        string cardNumber;
        string cardHolderName;
        string expiryDate;
        string cvv;
    public:
        CardPayment(const string& cardNumber, const string& cardHolderName, const string& expiryDate, const string& cvv) {
            this->cardNumber = cardNumber;
            this->cardHolderName = cardHolderName;
            this->expiryDate = expiryDate;
            this->cvv = cvv;
        }

        void pay(double amount) override {
            cout << "Paying " << amount << " using Card: " << cardNumber << endl;
        }
};

#endif // CARDPAYMENT_H