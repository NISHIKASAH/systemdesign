#include<bits/stdc++.h>
#include "model/order.h"
using namespace std;

class PickupOrder : public Order{
    string userAddress; 
    public : 
    PickupOrder(){
        userAddress = "";
    }
     string orderType () override {
     return "pickuporder";
   } 

    void setUserAddress(string address){
        userAddress = address;
        
    }
    string getUserAddress(){
        return userAddress;
    }

};