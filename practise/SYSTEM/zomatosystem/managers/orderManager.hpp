#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../factories/orderFactory.hpp"
#include "../model/dineinOrder.hpp"
#include "../model/deliveryOrder.hpp"

using namespace std;

class OrderManager { 
    vector<Order*>orderList;
    static OrderManager * orderManagerInstance;
    OrderManager(){};
    public : 
    static OrderManager* getOrderManager(){
        if(orderManagerInstance == nullptr){
            orderManagerInstance = new OrderManager();
        }
        return orderManagerInstance;
    }
    void addOrder(Order * order){
        orderList.push_back(order);
    }
    vector<Order*>getListOfOrders(){
        return orderList;
    }
    void viewOrders(){
        for(Order*order : orderList){
            cout<<"orderType : " <<order->getUser()->getUserName();
            cout<<"total Price :"<<order->totalCartAmount();
        }
    }

};
OrderManager * OrderManager ::orderManagerInstance = nullptr;