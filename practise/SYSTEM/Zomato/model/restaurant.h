#include<bits/stdc++.h>
#include "model/menuCard.h"
using namespace std;

class Restaurant {
    private : 
    string name;
    string location;
    static int restaurantId;
    vector<MenuCard*>menuItem ;
    public : 
    Restaurant(string n , string loc ){
        this->name = n;
        this->location = loc;

    }
    void addMenuItems(MenuCard * menuitem){
        menuItem.push_back(menuitem);
    }
    string getName(){
        return this->name;
    }
    string getLocation(){
        return this->location;
    }
    vector<MenuCard*>getMenu() {
        return menuItem;
    }

    void displayMenuItem(){
        for(auto item : menuItem){
            cout<<"Name :"<<item->getName()<<endl;
            cout<<"Price : "<<item->getPrice()<<endl;
            cout<<"ItemCode :"<<item->getCode()<<endl;
        }
        
    }
    
};