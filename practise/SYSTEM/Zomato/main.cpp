#include<bits/stdc++.h>
#include "zomato.h"
using namespace std;


int main(){

    ZomatoApp * Zomato = new ZomatoApp();
    Zomato->restaurantInitilization();


    User * user = new User("nishika" , "delhi");
    vector<Restaurant*>RestaurantList =  Zomato->searchForRestaurant("delhi");
    Zomato->selectRestaurant(user ,RestaurantList[0]);
    string code = RestaurantList[0]->getName();
    Zomato->addToCart(user , code);

   Order * order =  Zomato->checkOutNow(user , "onlinedelivery" , new UpiPayment("12345676543") , "12:30");
    Zomato->printUserCart(user);
    Zomato->PayForOrder(user , order);







    
};