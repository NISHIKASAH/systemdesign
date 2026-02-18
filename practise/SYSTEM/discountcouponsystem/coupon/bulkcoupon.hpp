#pragma once
#include <iostream>
#include "./couponcore.hpp"
#include "../strategy/discountstrategy.hpp"
#include "../manager/strategymanager.hpp"
#include "../manager/strategytype.hpp"
using namespace std;


class BulkCoupon : public Coupon {
    private : 
    int threshold; 
    int flatdiscount;
    DiscountStrategy * strategy ;
    public: 
    BulkCoupon(int n , int d){
        threshold= n;
        flatdiscount = d;
        strategy = StrategyManager :: getStrategyManager()->getStrategy(StrategyType ::FLATDISCOUNT , flatdiscount);
    }
    ~BulkCoupon(){
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
        return "Bulk purchase of " + to_string(flatdiscount) + "off on "  + to_string(threshold) + "\n";
        
    }


};