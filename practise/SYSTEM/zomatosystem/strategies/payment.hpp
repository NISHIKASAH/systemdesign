#pragma once
#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Payment {

    public : 
   virtual  void doPayment(double amount)= 0;
   virtual ~Payment(){}

    
};