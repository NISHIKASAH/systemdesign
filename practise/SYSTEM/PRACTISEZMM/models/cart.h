#ifndef CART_H
#define CART_H
#include<iostream>
#include<string>
#include<vector>
#include "../models/menuitem.h"
#include "../models/restaurant.h"

class Cart {
    vector<MenuItem*>menuItem;
    Restaurant * restaurant;
    string totalCost =0;

    public : 
    void addItems(MenuItem * item){
        menuItem.push_back(item);
    }
    vector<MenuItem*>getAllItems(){
        return menuItem;

    }
    void clearCart(){
        menuItem = {};

    }
    void setRestaurant(Restaurant * res ){
        restaurant = res;

    }
    Restaurant * getRestaurant(){
        return restaurant;
    }
    int getTotal(){

        for(auto it : menuItem){
            totalCost += it->getPrice();
        }
        return totalCost;
    }
    bool isEmpty(){
        return menuItem.empty();
    }
    
    
}



#endif 