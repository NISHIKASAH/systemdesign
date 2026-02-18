#pragma once 
#include<iostream>
#include "./bankingsystem.hpp"


using namespace std;

class RazorBankingSystem  : public BankingSystem  { 
    public : 
   bool paymentProcessing(double amount) override {
       cout << " Processing payment of " << amount << "...\n";
    int r = rand()%100;
    return r<90;
   }

};