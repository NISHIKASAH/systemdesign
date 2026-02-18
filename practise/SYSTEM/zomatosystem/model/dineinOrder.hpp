#pragma once
#include <iostream>
#include<vector>
#include<string>
#include "./order.h"

using namespace std;

class DineInOrder : public Order{
    string restaurantAddress;
    public : 
    DineInOrder(){
        restaurantAddress = "";
    }
    string getOrderType() override {
        return "DineIn";
    }
    void setRestaurantAddress(string address){
        restaurantAddress = address;
    }
    string getRestaurantAddress(){
        return restaurantAddress;
    }

};
