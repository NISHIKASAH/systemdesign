#pragma once
#include <iostream>
#include "../cart/cart.hpp"
using namespace std;

class Coupon
{
private:
    Coupon *nexthandler;

public:
    Coupon()
    {
        nexthandler = nullptr;
    }
    virtual ~Coupon()
    {
        delete nexthandler;
    }
    void setNext(Coupon *next)
    {
        nexthandler = next;
    }
    Coupon *getNext()
    {
        return nexthandler;
    }
    void applyDiscount(Cart *cart)
    {
        if (isApplicable(cart))
        {
            int discount = getDiscount(cart);
            cart->applyDiscountOnItem(discount);
              cout << displayDiscountmsg() << " applied: " << discount << endl;
            if (!isCombine())
            {
                return;
            }
        }
            if (nexthandler)
            {
                nexthandler->applyDiscount(cart);
            }
        
    }
    virtual bool isCombine() = 0;
    virtual int getDiscount(Cart *c) = 0;
    virtual bool isApplicable(Cart *cart) = 0;
    virtual string displayDiscountmsg() = 0;
};