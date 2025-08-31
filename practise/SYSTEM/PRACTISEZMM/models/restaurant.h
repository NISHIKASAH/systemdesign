#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<vector>
#include<string>
#include "../models/menuitem.h"
using namespace std;

class Restaurant {
    private : 
    string Name ; 
    string location ;
    vector<MenuCard*>RestaurantMenu;

    public :
    Restaurant(string name, string loc , vector<MenuItem *>menu){
        this->Name = name; 
        this->location = loc;
        this->RestaurantMenu = menu;
    }
    //getter and setter 

    void setRestaurantName(string name) {
        this->Name = name;
    }
    string getRestaurantName(){
        return Name;
    }

     void setRestaurantLocation(string loc) {
        this->location= loc;
    }
    string getRestaurantLocation(){
        return location;
    }
    
    void setMenuItems(MenuCard * item){
        RestaurantMenu.push_back(item);
    }
    vector<MenuCard*>getMenuItems(){
        return RestaurantMenu;
    }

};

#endif 
