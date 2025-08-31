#include<iostream>
#include<vector>
#include<string>
#include "./tomato.h"
using namespace std;

int main(){
    
    Tomato * tomatoApp = new Tomato();

   vector<Restaurant*> res =  SearchRestaurantByLocation("chennai");

    User * user1 = new User("nishika" , "chennai");

     selectRestaurant(user1 , res[0]);
     
     tomatoApp->addItemToCart(user1, "chat");
     tomatoApp->addItemToCart(user1 , "vada");

     tomatoApp->ViewCartlist();
    Order * orderCreated =  tomatoApp->checkoutScheduled(user1 , new UpiPayment(121345678765),"onlineorder" );

     tomatoApp->payForOrder(user1 , orderCreated );

     delete tomatoApp;
     delete user1;


};