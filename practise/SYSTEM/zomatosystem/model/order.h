#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "./restaurant.hpp"
#include "./user.hpp"
#include "../strategies/payment.hpp"

using namespace std;

class Order
{
private:
    static int id;
    int orderid;
    string orderType;
    Restaurant *restaurant;
    User *user;
    string scheduleTime;
    vector<Menucard *> ItemsOrderedList;
    Payment *paymentstrategy;
    int totalAmount;

public:
    Order()
    {

        restaurant = nullptr;
        user = nullptr;
        paymentstrategy = nullptr;
        totalAmount = 0;
        orderid = ++id;
        orderType = "";
    }
    
    virtual ~Order() {
        delete paymentstrategy;
    }
    virtual string getOrderType() = 0;

    string setScheduleTime(string time)
    {
        scheduleTime = time;
    }
    string getScheduleTime(){
        return scheduleTime;
    }
    int getOrderId(){
        return orderid;
    }
    void setRestaurant(Restaurant *res)
    {
        restaurant = res;
    }
    Restaurant *getRestaurant()
    {
        return restaurant;
    }
    void setUser(User *u)
    {
        user = u;
    }
    User *getUser()
    {
        return user;
    }
    void setOrderItem(vector<Menucard *> selectedItem)
    {
        ItemsOrderedList = selectedItem;
    }
    vector<Menucard *> getOrderItem()
    {
        return ItemsOrderedList;
    }
    int totalCartAmount()
    {
        for (Menucard *item : ItemsOrderedList)
        {
            totalAmount += item->getItemPrice();
        }
        return totalAmount;
    }
    void setPaymentStrategy(Payment *payment)
    {
        paymentstrategy = payment;
    }
    Payment *getPaymentStrategy()
    {
        return paymentstrategy;
    }
    bool processToPayment()
    {
        
        if(paymentstrategy){
            paymentstrategy->doPayment(totalAmount);
            return true;
        }
        return false;
    }
};

int Order ::id = 0;