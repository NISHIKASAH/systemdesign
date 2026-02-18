#pragma once
#include <iostream>
#include "./productdetail.hpp"
using namespace std;

class ProductFactory
{

public:
    static Product *createproduct(int sku)
    {

        string name;
        int price;
        if (sku == 101)
        {
            name = "Apple";
            price = 20;
        }
        else if (sku == 102)
        {
            name = "Banana";
            price = 10;
        }
        else if (sku == 103)
        {
            name = "Chocolate";
            price = 50;
        }
        else if (sku == 201)
        {
            name = "T-Shirt";
            price = 500;
        }
        else if (sku == 202)
        {
            name = "Jeans";
            price = 1000;
        }
        else
        {
            name = "Item" + to_string(sku);
            price = 100;
        }
       return  new Product(sku , name,price);
    }
};