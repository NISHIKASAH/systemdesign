#pragma once
#include <iostream>
#include <vector>
#include "./productdetail.hpp"
using namespace std;

class Inventorystore
{
public:
    virtual void addProduct(Product *,int quantity) = 0;
    virtual void removeProduct(int id , int quantity )  = 0;
    virtual int checkStock(int id) = 0;
    virtual vector<Product *> ListAvailableProduct() = 0;

   virtual ~Inventorystore(){};
};