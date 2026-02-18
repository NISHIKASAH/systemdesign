#pragma once
#include <iostream>
#include "../cart/cart.hpp"
#include "../coupon/couponcore.hpp"
using namespace std;

class CouponManager
{
private:
    Coupon *nexthandler;
    static CouponManager *coupleinstance;
    CouponManager() {
        nexthandler = nullptr;
    };
public:
    ~CouponManager() {};
    static CouponManager *getCouponManagerinstance()
    {
        if (coupleinstance == nullptr)
        {
            coupleinstance = new CouponManager();
        }
        return coupleinstance;
    }

    void RegisterCoupon(Coupon * newcoupon){
      
        if(!nexthandler){
              nexthandler = newcoupon;
        }else{
          Coupon * curr = nexthandler;
        while(curr->getNext()){
            curr  =curr->getNext(); //move to tail,to add register coupon
        }
        curr->setNext(newcoupon);
        }
        
    }
    int applyAvailableCoupon(Cart *cart){
         if(!nexthandler) return 0;
        if(nexthandler){
            if(nexthandler->isApplicable(cart)){
                nexthandler->applyDiscount(cart);
            }
        }
        return cart->getFinalAmount();
        
    }
    vector<string>showApplycoupon(Cart *cart){
        vector<string>appliedcouplononcart;
        Coupon * curr = nexthandler;
        while(curr){
           if(curr->isApplicable(cart)){
             appliedcouplononcart.push_back(curr->displayDiscountmsg());
           }
           curr = curr->getNext();
        }
        return appliedcouplononcart;
    }
    
};

CouponManager *CouponManager ::coupleinstance = nullptr;