#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include "../models/order.h"
using namespace std;

class Notification {
     public : 
     void notify(Order * order ){
         cout << "\nNotification: New " << order->orderType() << " order placed!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Order ID: " << order->getOrderId() << endl;
        cout << "Customer: " << order->getUser()->getName()<< endl;
        cout << "Restaurant: " << order->getRestaurant()->getRestaurantName()<<endl;
        cout << "Items Ordered:\n";

        const vector<MenuItem*>items = order->getMenuitem();
        for (const auto& item : items) {
            cout << "   - " << item->getName() << " (₹" << item->getPrice() << ")\n";
        }

        cout << "Total: ₹" << order->getUser()->getCart()->getTotal() << endl;
        cout << "Scheduled For: " << order->getScheduleTime()<< endl;
        cout << "Payment: Done" << endl;
        cout << "---------------------------------------------" << endl;

     }
}