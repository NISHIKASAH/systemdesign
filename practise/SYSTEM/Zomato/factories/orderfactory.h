#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H
-
#include<bits/stdc++.h>
#include "../model/order.h"
#include "../model/user.h"
#include "../restaurant.h"
#include "../strategies/Ipayment.h"
using namespace std ; 

class OrderFactory {
    public :
   virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuCard*>menuItems,
                                Payment* paymentStrategy, double totalCost, const string& orderType) = 0;

};


#endif 