#include<bits/stdc++.h>
#include "notification/emailNotification.h"
#include "model/cart.h"
#include "model/user.h"
#include "factories/nowOrder.h"
#include "manager/orderManager.h"
#include "manager/restaurantManager.h"
#include "factories/orderfactory.h"
#include "factories/scheduleOrder.h"
#include "model/restaurant.h"
#include "manager/restaurantManager.h"
#include "strategies/creditCardPayment.h"
#include "strategies/upiPayment.h"
using namespace std;

class ZomatoApp {
    public:
  
    ZomatoApp(){
        restaurantInitilization();
    }
    void  restaurantInitilization(){
        Restaurant * restaurant1 = new Restaurant("Delhi ki  cahat" , "delhi");
        restaurant1->addMenuItems(new MenuCard("chaat" , 245, "87654"));
        restaurant1->addMenuItems(new MenuCard("chowmein" , 198, "98976545"));
        restaurant1->addMenuItems(new MenuCard("momo" , 199 , "976756"));

        Restaurant * restaurant2 = new Restaurant("Vaishno thali" , "chennai");
        restaurant2->addMenuItems(new MenuCard("daal" ,200 ,"4567"));
        restaurant2->addMenuItems(new MenuCard("chawal" , 190 , "3456787"));
        restaurant2->addMenuItems(new MenuCard("sabji" , 169 , "89767544"));

        RestaurantManager * restaurantManager = RestaurantManager ::getrestaurantManager();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);


    }
    vector<Restaurant*>searchForRestaurant(string location){
        return RestaurantManager ::getrestaurantManager()->searchRestaurantByLoc(location);
    }
    void selectRestaurant(User * user , Restaurant * restaurant ){
       Cart * cart =  user->getCart();
       cart->setRestaurant(restaurant);
       
    }
    void addToCart(User * user , string &itemcode){
          Restaurant* res= user->getCart()->getRestaurant();
          for(auto it : res->getMenu()){
            if(it->getName() == itemcode){
                user->getCart()->addItemtoCart(it);
                break;
            }
          }
          return ;
    }
    Order * checkOutNow( User * user , string orderType , Payment * paymentStrategy ,string scheduleTime ){
        return checkOut(user , orderType , paymentStrategy , new ScheduleOrder());
        
    }
    Order* checkOut(User * user , string orderType , Payment * paymentStrategy , OrderFactory * orderfactory){
        Cart *usercart  = user->getCart();
        if(usercart->IsCartEmpty()){
            return nullptr;
        
        }
        Restaurant * restaurant = usercart->getRestaurant();
        vector<MenuCard*>AllCartItems  = usercart->getItems();
       int totalCost =  usercart->totalItem();
        orderfactory->createOrder(user, usercart, restaurant , AllCartItems , 
        paymentStrategy , totalCost , orderType);
    }

    void PayForOrder(User * user ,Order * order){
        bool isPaymentSucessful = order->processPayment();
        if(isPaymentSucessful){
            Notification * notification = new EmailNotification(order);
            notification->getNotification();
            user->getCart()->clearCart();
        }
    }
    void printUserCart(User *user){
        Cart * cart = user->getCart();
       vector<MenuCard*>cartItems =  cart->getItems();
       for(auto item : cartItems){
         cout << item->getCode() << " : " << item->getName() << " : ₹" << item->getPrice() << endl;
       }
       int TotalPrice = cart->totalItem();
       cout<<"TotalPrice:" << TotalPrice<<endl;


    }


    
};