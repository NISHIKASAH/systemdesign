#pragma once
#include <iostream>
#include<vector>
#include<string>
#include "./payment.hpp"

using namespace std;

class UpiCard : public Payment{
    int mobileNo ; 
    public :
    UpiCard(int no){
        mobileNo = no;
    }
   void doPayment(double amount) override {
    cout<<" \n Payment of "<<amount<<"done successfully with UpiNumber : "<<mobileNo<<endl;
    }
};