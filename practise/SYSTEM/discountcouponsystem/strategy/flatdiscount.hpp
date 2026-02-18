#pragma once
#include<iostream>
#include "./discountstrategy.hpp"
using namespace std;

class FlatDiscount :  public DiscountStrategy {
    int discount ;
    public: 
   FlatDiscount(int d) {
    discount = d;
   }
   int calculate(int baseamount) override {
      return min(discount , baseamount);
   }

};