#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "./orderFactory.hpp"
#include "../model/dineinOrder.hpp"
#include "../model/deliveryOrder.hpp"

using namespace std;

class NowReadyFactory : public OrderFactory
{
public:
    Order *createOrder(Restaurant *restaurant, vector<Menucard *> menuitemlist, User *user, 
        Payment *payment, string orderType)  override {
            Order * scheduleOrder = nullptr;
            if(orderType == "DineIn"){
                scheduleOrder = new DineInOrder();
                user->setUserLocation(restaurant->getRestLoc());
            }
            else {
                scheduleOrder = new DeliveryOrder();
                restaurant->setRestLoc(user->getUserLocation());
            }
            scheduleOrder->setOrderItem(menuitemlist);
            scheduleOrder->setPaymentStrategy(payment);
            scheduleOrder->setScheduleTime("justarrived");
            scheduleOrder->totalCartAmount();
            return scheduleOrder;
        }
        
};