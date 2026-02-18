#pragma once
#include <iostream>
#include "./couponcore.hpp"
#include "../strategy/discountstrategy.hpp"
#include "../manager/strategymanager.hpp"
#include "../manager/strategytype.hpp"
using namespace std;


class LoyalityCoupon : public Coupon {
    private : 
    int percent;
    int capvalue;
    DiscountStrategy * strategy ;
    public: 
    LoyalityCoupon(int n , int p){
        capvalue = n;
        percent = p;
        strategy = StrategyManager :: getStrategyManager()->getStrategy(StrategyType ::PERCENTWITHCAPDISCOUNT , percent , capvalue);
    }

    ~LoyalityCoupon(){
        delete strategy;
    }
    int getDiscount(Cart *c)  override{
        return strategy->calculate(c->getFinalAmount());
    }

   bool isCombine() override {
        return true;
    }
    bool isApplicable(Cart *cart) override {
       return cart->getLoyality();
    }
    string displayDiscountmsg() override { 
        return "Display discount of " + to_string(percent) + "with capvalue" + to_string(capvalue) +
        "for memership customer \n";
    }



};