#pragma once
#include<iostream>
using namespace std;

class DiscountStrategy {
    public: 
   virtual int calculate(int d) = 0;
   virtual  ~DiscountStrategy(){};

};