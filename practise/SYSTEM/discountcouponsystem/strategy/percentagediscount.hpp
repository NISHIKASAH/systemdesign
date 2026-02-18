#pragma once
#include<iostream>
#include "./discountstrategy.hpp"
using namespace std;

class PercentageDiscount :  public DiscountStrategy {
    int percent;
    public: 
   PercentageDiscount(int d) {
    percent = d;
   }
   int calculate(int baseamount) override {
      return percent/100 * baseamount;
   }

};