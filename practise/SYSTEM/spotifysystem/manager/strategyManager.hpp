#pragma once 
#include <iostream>
#include "../strategies/customQueueStrategy.hpp"
#include "../strategies/sequenceStrategy.hpp"
#include "../strategies/randomStrategy.hpp"
#include "../enum/strategyType.hpp"
using namespace std;

class StrategyManager
{
private:
    RandomStrategy *randomstrategy;
    CustomQueueStrategy *customstrategy;
    SequenceStrategy *sequencestrategy;
    static StrategyManager *StrategyManagerInstance;

    StrategyManager()
    {
        randomstrategy = new RandomStrategy();
        customstrategy = new CustomQueueStrategy();
        sequencestrategy = new SequenceStrategy();
    }

public:
    static StrategyManager *getStrategyManager()
    {
        if (StrategyManagerInstance == nullptr)
        {
            StrategyManagerInstance = new StrategyManager();
        }
        return StrategyManagerInstance;
    }
    PlayListStrategy *getStrategy(StrategyType strategytype)
    {
        if (strategytype == StrategyType ::CUSTOMTYPE)
        {
            return customstrategy;
        }
        else if (strategytype == StrategyType ::SEQUENCETYPE)
        {
            return sequencestrategy;
        }
        else
        {
            return randomstrategy;
        }
    }
};

StrategyManager *StrategyManager ::StrategyManagerInstance = nullptr;