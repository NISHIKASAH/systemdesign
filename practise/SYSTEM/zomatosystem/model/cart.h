#pragma once
#include <iostream>
#include<vector>
#include<string>
#include "./restaurant.hpp"
#include "./menucard.hpp"
using namespace std;

class Cart
{

private:
    Restaurant *restaurant;
    vector<Menucard *>ItemsIncart;

public:
    Cart()
    {
        restaurant = nullptr;
    }
    void setRestaurant(Restaurant *res)
    {
        restaurant = res;
    }
    Restaurant * getRestaurant(){
        return restaurant;
    }
    void addItemToCard(string name){
        if(!restaurant) cout<<" \n Select Restaurant \n"<<endl;
        vector<Menucard*>menu = restaurant->getRestMenuCard();
        for(Menucard *item : menu){
            if(item->getItemName() == name)
            ItemsIncart.push_back(item);
        }
    }
    vector<Menucard*>getCartItem(){
        return ItemsIncart;
    }
    bool isCartEmpty(){
        return ItemsIncart.size() != 0;
    }
   

    bool clearCart(){
        ItemsIncart.clear();
        restaurant = nullptr;
    }

     int totalAmount()
    {
        int totalamount = 0;
        for (Menucard *item  : ItemsIncart)
        {
            totalamount += item->getItemPrice();
        }
        return totalamount;
    }
    
};