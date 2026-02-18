#pragma once
#include <iostream>
#include<vector>
#include<string>
#include "./payment.hpp"

using namespace std;

class CreditCard : public Payment{
    int creditNo; 
    public:
    CreditCard(int no){
        creditNo = no;
    }
   void doPayment(double amount ) override {
    cout<<" \n Payment of "<<amount<<"done successfully with CreditNumber : "<<creditNo<<endl;
    }
};