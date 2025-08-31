#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H
#include <iostream>
#include<vector>
#include<string>
#include "../models/order.h"
#include "../payment/paymentStrategy.h"
#include "../models/menuitem.h"
using namespace std;


class OrderFactory {

    public : 
    virtual Order * createorder(User * user , Restaurant * restaurant , vector<MenuItem*>menuitems,
         PaymentStrategy * payment , string orderType ) =0;


};


#endif 