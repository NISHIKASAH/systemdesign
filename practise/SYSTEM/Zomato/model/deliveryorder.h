#include<bits/stdc++.h>
#include "model/order.h"
#include "model/restaurant.h"
using namespace std;

class OnlineDelivery  : public Order{
    string userAddress ;
    public : 
    OnlineDelivery(){
        userAddress ="";
    }
   string orderType () override {
     return "onlineorder";
   }
    void setUserAddress(string address){
        userAddress = address;
        
    }
    string getUserAddress(){
        return userAddress;
    }

};