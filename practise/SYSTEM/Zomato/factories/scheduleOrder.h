#include<bits/stdc++.h>
#include"orderfactory.h"
#include "../model/order.h"
#include "../model/deliveryorder.h"
#include "../model/pickuporder.h"
using namespace std;

class ScheduleOrder : public OrderFactory{
     public :

    Order * createOrder( User* user, Cart* cart, Restaurant* restaurant, const vector<MenuCard*>menuItems,
                                Payment* paymentStrategy, double totalCost, const string& orderType
    ) override { 
        Order * neworder ;
        if(orderType == "onlineorder")  {
            OnlineDelivery * online  = new OnlineDelivery();
            online->setUserAddress(user->getAddress());
            neworder = online;
        }
        else{
            PickupOrder * pickup = new PickupOrder();
            pickup->setUserAddress(restaurant->getLocation());
            neworder = pickup;
        }
        neworder->setUser(user);
        neworder->setRestaurant(restaurant);
        neworder->setMenuCard(menuItems);
        neworder->settotalAmount(totalCost);
        return neworder;
    }

};