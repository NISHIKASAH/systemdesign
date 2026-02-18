#pragma once
#include <iostream>
#include <cmath>
#include "../manager/inventorymanager.hpp"
#include "../strategy/replenish.hpp"
using namespace std;

class Deepstore
{
    string storename;
    InventoryManager *inventorymanager;
    Replenish *strategy;
    int sx;
    int sy;

public:
    Deepstore( string name  , int x, int y ,Replenish *st)
    {
        storename = name;
        inventorymanager = new InventoryManager(new DbInventorystore());
        strategy = st;
        sx = x;
        sy = y;
    }
    ~Deepstore()
    {
        delete inventorymanager;
        if (strategy)
        {
            delete strategy;
        }
    }

    void runReplenishing(map<int, int> itemtostockup)
    {
        strategy->replenishing(inventorymanager, itemtostockup);
    }
    int distanceTo(int ux, int uy)
    {
        int dist = sqrt((sx - ux) * (sx - ux) + (sy - uy) * (sy - uy));
        return dist;
    }
    int checkProductStock(int sku)
    {
       return inventorymanager->checkProductStocks(sku);
    }
    void addstocktostore( int sku , int qty){
        inventorymanager->addStock(sku , qty);
    }
    void removestockfromstore(int sku , int qty){
        inventorymanager->removeStock(sku,qty);
    }
    vector<Product *> getAllProduct()
    {
        return inventorymanager->viewAvailableProduct();
    }
    void setStrategy(Replenish *str){
        strategy = str;
    }
    Replenish* getStrategy(){
        return strategy;
    }
    string getName(){
        return storename;
    }
    int getXCoordinates(){
        return sx;
    }
    int getYCoordinates(){
        return sy;
    }
    InventoryManager * getManager(){
        return inventorymanager;
    }

};