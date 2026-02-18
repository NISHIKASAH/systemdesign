#pragma once
#include <iostream>
#include "./product.hpp"
using namespace std;

class CartItem
{
    Product *product;
    int quantity;
    int total;

public:
    CartItem()
    {
        product = nullptr;
        quantity = 0;
        total = 0;
    }
    void setProduct(Product *p)
    {
        product = p;
    }
    Product *getProduct()
    {
        return product;
    }
    void setQuantity(int n)
    {
        quantity = n;
    }
    int getQuantity()
    {
        return quantity;
    }
    void setTotal()
    {
        int sum = 0;
        sum = product->getPrice() * quantity;
        total = sum;
    }
    int getTotal()
    {
        return total;
    }

};