#pragma once 
#include<iostream>
#include "../startegy/randomstrategy.hpp"
#include "../startegy/sequencestrategy.hpp"
#include "../enum/stratergy.hpp"
using namespace std;

class StrategyManager { 
  static  StrategyManager * instance;
    RandomStrategy * random;
    SequenceStrategy * sequence; 

    StrategyManager(){
        random = new RandomStrategy();
        sequence = new SequenceStrategy();
    }
    public : 

   static  StrategyManager * getstrategymanagerinstance(){
        if(instance == nullptr){
           instance =  new StrategyManager();
        }
        return instance;
    }
   PlayListStrategy* getStrategy(stratergyType type){
    if(type == stratergyType ::RANDOM){
        return random;
    }
    else{
        return sequence;
    }
    

   }


};

StrategyManager * StrategyManager :: instance = nullptr;