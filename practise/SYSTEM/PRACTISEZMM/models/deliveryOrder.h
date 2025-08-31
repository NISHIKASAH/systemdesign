#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include <iostream>
#include "../models/order.h"
using namespace std; 

class DeliveryOrder : public Order {
    string userAddress;
     public :
    string orderType()  override {
        return "onlineorder" ;
    }
    void setUserAddress(string address){
       userAddress = address;
    }
    string getUserAddress(){
        return userAddress;
    }

};
#endif