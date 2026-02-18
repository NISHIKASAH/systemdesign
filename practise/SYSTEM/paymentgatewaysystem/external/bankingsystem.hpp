#pragma once 
#include<iostream>


using namespace std;

class BankingSystem  { 
    public : 
   virtual bool paymentProcessing(double amount) =0;
   virtual ~ BankingSystem(){};

};

