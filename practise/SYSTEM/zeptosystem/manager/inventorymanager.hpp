#pragma once
#include<iostream>
#include "../product/dbinventorystore.hpp"
#include "../product/productfactory.hpp"
using namespace std;


class InventoryManager { 
    private : 
Inventorystore * Inventory;
    public : 
    InventoryManager(Inventorystore *store ){
        Inventory = store;
    }

    void addStock(int sku , int qty){
       Product * newproduct =  ProductFactory ::createproduct(sku);

       Inventory->addProduct(newproduct , qty);
       cout<<"[Inventory manager added new product] "<<newproduct->getSuk() <<" : " <<newproduct->getName()
       <<endl;

    }
    void removeStock(int sku ,int qty){

       Inventory->removeProduct(sku , qty);
    }
    int checkProductStocks(int sku){
        return Inventory->checkStock(sku);
    }
    vector<Product*> viewAvailableProduct(){
       return Inventory->ListAvailableProduct();
    }


};