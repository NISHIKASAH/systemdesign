#pragma once
#include<iostream>
#include "./discountstrategy.hpp"
using namespace std;

class CapWithPercentDiscount :  public DiscountStrategy {
    int percent;
    int capval ;
    public: 
   CapWithPercentDiscount(int d , int c) {
    percent = d;
    capval =c;
   }
   int calculate(int baseamount) override {
       int pvalue = percent/100 * baseamount; 
       return min(capval , pvalue);

   }

};