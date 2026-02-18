#include<iostream>
#include<vector>
#include<string>
#include "./zomato.hpp"
using namespace std;


int main(){

    ZomatoApp * zomato = new ZomatoApp();
    zomato->initilization();

   vector<Restaurant*>restaurantList =  zomato->getRestaurantByLocSearch("chennai");

   User * user = new User("nishika" , "chennai");
   zomato->selectRestaurant(user , restaurantList[0]);

   zomato->addItemToUserCart(user , "idli");
   zomato->addItemToUserCart(user , "dosa");
   zomato->viewOrderItem(user);
  Order * order  =  zomato->checkOutSchedule(user , "Delivery", new CreditCard(23456),"1:30");

   zomato->PaymentProcess(order);
   

   delete zomato;
   delete user;

   return 0;
}