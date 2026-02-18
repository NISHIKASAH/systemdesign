#pragma once
#include <iostream>
#include<vector>
#include<string>
#include "./model/order.h"

using namespace std;

class Notification {

   
    public : 
     
    void getNotify(Order * order){
       cout << "\nNotification: New " << order->getOrderType() << " order placed!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Order ID: " << order->getOrderId() << endl;
        cout << "Customer: " << order->getUser()->getUserName() << endl;
        cout << "Restaurant: " << order->getRestaurant()->getRestName() << endl;
        cout << "Items Ordered:\n";

        const vector<Menucard*>items = order->getOrderItem();
        for (const auto& item : items) {
            cout << "   - " << item->getItemName() << " (₹" << item->getItemPrice() << ")\n";
        }

        cout << "Total: ₹" << order->totalCartAmount() << endl;
        cout << "Scheduled For: " << order->getScheduleTime() << endl;
        cout << "Payment: Done" << endl;
        cout << "---------------------------------------------" << endl;
    }
};