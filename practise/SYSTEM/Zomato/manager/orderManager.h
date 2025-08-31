#include<bits/stdc++.h>
#include "model/order.h"

class OrderManager {
    static OrderManager * instance ;
    vector<Order*>orderList;
    OrderManager(){
    }
      public : 
      static OrderManager * getorderManager(){
        if(instance == nullptr){
            instance = new OrderManager();
        }
        return instance;
      }

    void addorders(Order * order) {
        orderList.push_back(order);
    }
    void displayAllorder(){
        for (auto order : orderList) {
            cout << order->orderType() << " order for " << order->getUser()->getName()
                    << " | Total: ₹" << order->gettotalAmount()
                    << " | At: " << order->getScheduled() << endl;
        }
    }



};
OrderManager* OrderManager :: instance = nullptr;