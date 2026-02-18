#pragma once
#include <iostream>
#include "./strategyType.hpp"
#include "../strategy/flatdiscount.hpp"
#include "../strategy/discountstrategy.hpp"
#include "../strategy/percentagediscount.hpp"
#include "../strategy/capwithpercentag.hpp"
using namespace std;

class StrategyManager
{
private:
    static StrategyManager *startegymanager;
    StrategyManager() {};
    StrategyManager(const StrategyManager *) =delete ; 
    StrategyManager*operator = (const StrategyManager*) = delete ;
public:

 ~StrategyManager(){};
    static StrategyManager *getStrategyManager()
    {
        if (startegymanager == nullptr)
        {
            startegymanager = new StrategyManager();
        }
        return startegymanager;
    }

    DiscountStrategy *getStrategy(StrategyType type, int baseamount, int capvalue = 0)
    {
        if (type == StrategyType ::FLATDISCOUNT)
        {
            return new FlatDiscount(baseamount);
        }
        else if (type == StrategyType ::PERCENTDISCOUNT)
        {
            return new PercentageDiscount(baseamount);
        }
        else if(type == StrategyType ::PERCENTWITHCAPDISCOUNT )
        {
            return new CapWithPercentDiscount(baseamount, capvalue);
        }
        else nullptr;
    }
};

StrategyManager * StrategyManager :: startegymanager = nullptr;