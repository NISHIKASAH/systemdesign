#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "./cart.h"

using namespace std;

class User {
    private : 
    string uname;
    string ulocation ;
    Cart * userCart;
    public : 
    User(string name , string loc ){
        uname = name;
        ulocation = loc;
        userCart = new Cart();
    }
   Cart* getUserCart(){
    return userCart;
    }
   void setUserLocation(string loc){
    ulocation = loc;
    }
    string getUserLocation(){
        return ulocation;
    }
    void setUserName(string name){
        uname = name;
    }
    string getUserName(){
        return uname;
    }
     ~User(){
        delete userCart;
     }

};