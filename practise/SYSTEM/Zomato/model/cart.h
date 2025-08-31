#include<bits/stdc++.h>
#include "model/menuCard.h"
#include "model/restaurant.h"
using namespace std;

class Cart {
    private : 
    Restaurant * restaurant ;
    vector<MenuCard*>menuList;
    public :
    void addItemtoCart(MenuCard * item){
        menuList.push_back(item);
    }

    int totalItem(){
        int total = 0;
        for(auto item : menuList){
            total += item->getPrice();
        }
        return total;
    }
    vector<MenuCard*>getItems(){
        return menuList;
    }
    bool IsCartEmpty(){
        return menuList.empty();
    }
      void setRestaurant(Restaurant * res){
        restaurant = res;
        
    }
    Restaurant * getRestaurant(){
        return restaurant;
    }
    void displayCartItems(){
        for(auto items : menuList){
            cout<<"Name :"<<items->name<<endl;
            cout<<"Price :"<<items->price<<endl;
        }
    }
     void clearCart(){
        menuList = {};
    }
};
