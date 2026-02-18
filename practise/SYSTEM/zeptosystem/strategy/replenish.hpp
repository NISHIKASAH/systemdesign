#pragma once
#include <iostream>
#include "../manager/inventorymanager.hpp"
using namespace std;

class Replenish { 
    public : 
    virtual void replenishing(InventoryManager * manager ,map<int,int>itemtostockup) = 0;
    virtual ~Replenish() {};
};