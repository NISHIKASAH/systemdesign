#ifndef TOMATO_H
#define TOMATO_H
#include <iostream>
#include<vector>
#include<string>
#include "../models/cart.h"
#include "../models/users.h"
#include "../models/restaurant.h"
#include "../models/deliveryOrder.h"
#include "../models/menuitem.h"
#include "../managers/orderManager.h"
#include "../managers/restaurantManager.h"
#include "../payment/creditCardPayment.h"
#include "../payment/upiPayment.h"
#include "../notification/notification.h"
#include "../factories/nowOrder.h"
#include "../factories/scheduleOrder.h"

using namespace std;

class Tomato
{
public:
    void initilization()
    {
        Restaurant *res1 = new Restaurant("a2b", "chennai", new MenuItem("chat", 125, "001"));
        Restaurant *res2 = new Restaurant("sangeetha", "chennai", new MenuItem("idli", 147, "003"));
        Restaurant *res3 = new Restaurant("pushpa", "chennai", new MenuItem("vada", 115, "044"));

        RestaurantManger *RestmanagerInstance ::getRestaurantManagerInstance();
        RestmanagerInstance->addRestaurant(res1);
        RestmanagerInstance->addRestaurant(res2);
        RestmanagerInstance->addRestaurant(res3);
    }
    vector<Restaurant*> SearchRestaurantByLocation(RestaurantManger *manager, string loc)
    {
        return manager->searchRestaurantByLocation(location);
    }
    void selectRestaurant(User *user, Restaurant *res)
    {
        Cart *cart = user->getCart();
        cart->setRestaurant(res);
    }

    void addItemToCart(User *user, string itemCode)
    {
        Restaurant *restaurant = user->getCart()->getRestaurant();
        vector<MenuItem *> menu = restaurant->getMenuItems();
        for (const auto &res : menu)
        {
            if (itemCode == res->getCode())
            {
                user->getCart()->addItems(res);
                break;
            }
        }
    }

    Order * checkoutNow(User * user , PaymentStrategy * payment ,string orderType ){
        return checkout(user , payment , orderType , new NowOrder());
    }

      Order* checkoutScheduled(User * user , PaymentStrategy * payment ,string orderType ,string scheduleTime ){
        return checkout(user , payment , orderType , new ScheduleOrder(scheduleTime));
    }

    void checkout(User * user , PaymentStrategy * payment , string orderType , OrderFactory * orderfactory){

        Cart * cart  = user->getCart();
        if(cart->isEmpty()){
            cout<<"Cart is empty"<<endl;
        }

        Restaurant * restaurant = cart->getRestaurant();
        vector<MenuItem*>menuitem = restaurant->getMenuItems();
        Order* neworder=   orderfactory->createorder(user , restaurant , menuitem , payment , orderType);
        
      return neworder;

    }

    void payForOrder(User*user, Order * order){
        bool result =  order->processToPayment();
        if(result){
            Notification * notification = new Notification();
            notification->notify(order);
            user->getCart()->clearCart();
        }
    }

    void ViewCartlist(User * user ){
         cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getAllItems()) {
            cout << item->getCode() << " : " << item->getName() << " : ₹" << item->getPrice()<< endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->getTotal(); << endl;
    }

};

#endif