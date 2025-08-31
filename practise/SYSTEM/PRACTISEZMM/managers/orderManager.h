#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <iostream>
#include "../models/order.h"

class OrderManager
{
private:
    vector<Order *> OrderList;
    static OrderManager *managerInstance;
    OrderManager()
    {
    }

public:
    static OrderManager *getInstance()
    {
        if (managerInstance == nullptr)
        {
            managerInstance = new OrderManager();
        }
        return managerInstance;
    }
    void addOrder(Order *order)
    {
        OrderList.push_back(order);
    }
    void ListofOrders()
    {
       cout << "\n--- All Orders ---" << endl;
        for (auto order : OrderList) {
            cout << order->getOrderId()<< " order for " << order->getUser()->getCart()
                    << " | At: " << order->getScheduleTime() << endl;
        }
    
    }
};
OrderManager *OrderManager ::managerInstance = nullptr;

#endif
