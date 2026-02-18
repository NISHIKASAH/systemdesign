#pragma once
#include <iostream>
#include <map>
#include "./productdetail.hpp"
#include "./inventory.hpp"

using namespace std;

class DbInventorystore : public Inventorystore
{
private:
    map<int, int> *stock;
    map<int, Product *> *productList;

public:
    DbInventorystore()
    {
        stock = new map<int, int>();
        productList = new map<int, Product *>();
    }

    ~DbInventorystore()
    {
        for (auto items : *productList)
        {
            delete items.second;
        }
        delete stock;
        delete productList;
    }
    void addProduct(Product *newproduct, int quantity) override
    {
        int id = newproduct->getSuk();
        if( !productList->count(id)){
            (*productList)[id] = newproduct;
        }
        else {
            (*stock)[id] += quantity;
        }
    }
    void removeProduct(int id ,int quantity) override{
        if( !productList->count(id)){
            cout<<"NO PRODUCT TO REMOVE \n";
        }
        else {
            int currentstock = (*stock)[id];
            int remaining = currentstock - quantity;
            if(remaining >0){
                (*stock)[id] = remaining;
            }
            else  {
                stock->erase(id);
            }
        }
    }
    int checkStock(int id ) override {
        if(!stock->count(id)){
            cout<<"No stock  for product : " <<  (*productList)[id]->getName()<<endl;
        }
        return (*stock)[id];

    }
    vector<Product *> ListAvailableProduct() override {
         vector<Product*> available;
        for(auto& it : *stock){
          int sku = it.first;
            int qty = it.second;
            if (qty > 0 && stock->count(sku)) {
                available.push_back((*productList)[sku]);
            }
        }
        return available;
    }
};