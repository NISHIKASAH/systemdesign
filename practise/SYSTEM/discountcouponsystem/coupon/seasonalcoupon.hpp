#pragma once
#include <iostream>
#include "./couponcore.hpp"
#include "../strategy/discountstrategy.hpp"
#include "../manager/strategymanager.hpp"
#include "../manager/strategytype.hpp"
using namespace std;

class SeasonalCoupon : public Coupon
{
private:
    string category;
    int percent;
    DiscountStrategy * strategy;

public:
    SeasonalCoupon(int p, string c)
    {
        category = c;
        percent = p;
        strategy = StrategyManager ::getStrategyManager()->getStrategy(StrategyType ::PERCENTDISCOUNT , percent);
    }
    ~SeasonalCoupon(){
        delete strategy;
    }
    bool isCombine() override
    {
        return true;
    }
    int getDiscount(Cart *cartitem) override {
        int subtotal = 0;
        for(CartItem *item : cartitem->getAllCartItem()){
            if(item ->getProduct()->getCategory() == category){
                subtotal += item->getProduct()->getPrice();
            }
        }
       return  strategy->calculate(subtotal);
    }
     bool isApplicable(Cart *cart) override
    {
        bool loyal = cart->getLoyality();
        return loyal;
    }
     string displayDiscountmsg() override {
        return "Seasonal discount  of " + to_string(percent) + "off in these winter \n";
     }
};