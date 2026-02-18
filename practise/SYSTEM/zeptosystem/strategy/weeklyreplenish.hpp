#pragma once
#include<iostream>
#include "../product/dbinventorystore.hpp"
#include "./replenish.hpp"

using namespace std;

class WeeklyReplenish : public Replenish {
    public : 
    void replenishing(InventoryManager * manager , map<int,int>itemtostockup) override {
        for(auto items : itemtostockup){
          int quantity =   manager->checkProductStocks(items.first);
          int sku = items.first;
          manager->addStock(sku , quantity);
          cout<<"SKU : "<<sku << "Stockup By : "<<items.second<<endl;

        }
    }
};