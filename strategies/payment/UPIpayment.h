#ifndef UPIPAYMENT_H
#define UPIPAYMENT_H

#include <iostream>
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class UPIPayment : public PaymentStrategy {
    private:
        string upiId;
    public:
        UPIPayment(const string& upiId){
            this->upiId = upiId;
        }

        void pay(double amount) override {
            cout << "Paying " << amount << " using UPI ID: " << upiId << endl;
        }
};


#endif // UPIPAYMENT_H