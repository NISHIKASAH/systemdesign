#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include <iostream>
#include "../models/order.h"
using namespace std; 

class PickupOrder : public Order {
    string restaurantAddress;
     public :
    string orderType()  override {
        return "offlineorder" ;
    }
    void setRestaurantAddress(string address){
       restaurantAddress = address;
    }
    string getRestaurantAddress(){
        return restaurantAddress;
    }

};
#endif