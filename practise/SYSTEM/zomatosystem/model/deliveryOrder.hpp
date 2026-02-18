#pragma once
#include <iostream>
#include<vector>
#include<string>
#include "./order.h"

using namespace std;

class DeliveryOrder : public Order {
    string userAddress;
    public : 
    DeliveryOrder(){
        userAddress = "";
    }
    string getOrderType() override {
        return "Delivery";
    }
    void setUserAddress(string address){
        userAddress = address;
    }
    string getUserAddress(){
        return userAddress;
    }


};