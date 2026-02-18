#pragma once
#include <iostream>
#include <vector>
#include "./cartItem.hpp"
using namespace std;

class Cart
{
private:
    vector<CartItem *> items;
    int totalAmount;
    int finalAmount;
    bool isLoyal;

public:
    Cart()
    {
        totalAmount = 0;
        finalAmount = 0;
        isLoyal = false;
    }
    void addProduct(Product *p, int quantity)
    {
        CartItem *cart = new CartItem();
        totalAmount += p->getPrice() * quantity;
        finalAmount += p->getPrice() * quantity;
        cart->setProduct(p);
        cart->setQuantity(quantity);
    }

    vector<CartItem *> getAllCartItem()
    {
        return items;
    }

    void applyDiscountOnItem(int d)
    {
        finalAmount = finalAmount - d;
        if (finalAmount < 0)
        {
            finalAmount = 0;
        }
    }

    int getTotal()
    {
        return totalAmount;
    }
    int getFinalAmount()
    {
        return finalAmount;
    }
    void setLoyality(bool value)
    {
        isLoyal = value;
    }

    bool getLoyality()
    {
        return isLoyal;
    }
};