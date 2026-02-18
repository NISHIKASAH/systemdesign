#pragma once
#include<iostream>
#include "./cart.hpp"
using namespace std;

class User { 
    string name; 
    int ux; int uy;
    Cart * cart;
    public : 
    User(string n, int x,int y){
        name = n;
        ux= x;
        uy = y;
        cart = new Cart();
    }
    ~User(){
        cart->clearCart();
    }
    string getName(){
        return name;
    }
    int getuserxcoordinate(){
        return ux;
    }
    int getuserycoorinate(){
        return uy;
    }
    Cart*getCart(){
        return cart;
    }


};