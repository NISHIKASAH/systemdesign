#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>
#include <string>
#include "../models/restaurant.h"
#include "../models/menuitem.h"
#include "../models/users.h"
#include "../payment/upiPayment.h"


using namespace std;

class Order {
private:
    Restaurant *restaurant;
    User *user;
    vector<MenuItem *> menuitems;
    PaymentStrategy *paymentstrategy;
    string orderType;
    int orderId;
    static int nextorderId;
    string scheduleTime;

public:
    Order()
    {
        orderType = "";
        orderId = ++nextorderId;
        user = nullptr;
        restaurant = nullptr;
        paymentstrategy = nullptr;
        scheduleTime = "";
    }
    virtual ~Order() {
        delete paymentstrategy;
    }

    void setRestaurant(Restaurant *res)
    {
        this->restaurant = res;
    }
    Restaurant *getRestaurant()
    {
        return restaurant;
    }

    void setUser(User *user)
    {
        this->user = user;
    }
    User *getUser()
    {
        return user;
    }

    void setMenuitem(vector<MenuItem *> items)
    {
        this->menuitems = items;
    }
    vector<MenuItem *> getMenuitem()
    {
        return menuitems;
    }

    void setScheduleTime(string time)
    {
        this->scheduleTime = time;
    }
    string getScheduleTime()
    {
        return this->scheduleTime;
    }

    void setPaymentStrategy(PaymentStrategy *payment)
    {
        this->paymentstrategy = payment;
    }
    bool processToPayment(int amount)
    {
        if (paymentstrategy)
        {
            paymentstrategy->doPayment(amount);
            return true;
        }
        else
        {
            cout << "First Choose payment method : " << endl;
        }
    }
   virtual string orderType() = 0;
    int getOrderId()
    {
        return orderId;
    
    }

};
int Order ::nextorderId = 0;

#endif