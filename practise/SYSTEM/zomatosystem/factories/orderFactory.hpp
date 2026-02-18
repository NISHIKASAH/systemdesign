#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../model/restaurant.hpp"
#include "../model/user.hpp"
#include "../model/menucard.hpp"
#include "../strategies/payment.hpp"
#include "../model/order.h"

using namespace std;


class OrderFactory {
    public : 
    virtual Order* createOrder(Restaurant * restaurant , vector<Menucard*>menuitemlist , User *user ,Payment*payment, string orderType ) = 0;
    virtual ~OrderFactory(){};
};