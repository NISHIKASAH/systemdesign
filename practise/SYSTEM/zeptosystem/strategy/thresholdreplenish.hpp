#pragma once
#include<iostream>
#include "../product/dbinventorystore.hpp"
#include "./replenish.hpp"
using namespace std;

class ThresholdReplenish : public Replenish  { 
    int threshold;
    public : 
    ThresholdReplenish(int th){
        this->threshold = th;
    }
     void replenishing(InventoryManager * manager , map<int,int>itemtostockup) override {
        for(auto items : itemtostockup){
          int quantity =   manager->checkProductStocks(items.first);
          int sku = items.first;
          if(quantity < threshold )
          manager->addStock(sku , quantity);
          cout<<"SKU : "<<sku << "Stockup By : "<<items.second<<endl;

        }
    }

};