#pragma once 
#include<iostream>
#include "./user.hpp"
#include "./deliverypartner.hpp"
using namespace std;

class Order { 
     public : 
    User * user;
    vector<pair<Product * , int>>Item;
    vector<DeliveryPartner*>partners;
    int total ;
    Order(User * u){
        user = u;
        total = 0;
    
        
    }


};