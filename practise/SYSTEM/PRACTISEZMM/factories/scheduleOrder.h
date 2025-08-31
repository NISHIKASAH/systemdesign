#include NOW_ORDER_H
#define NOW_ORDER_H
#include <iostream>
#include "../factories/orderfactory.h"
#include "../models/order.h"
#include "../models/deliveryOrder.h"
#include "../models/pickupOrder.h"
using namespace std;

class ScheduleOrder : public OrderFactory
{
private:
    string scheduleTime;

public:
    ScheduleOrder(string time)
    {
        scheduleTime = time;
    }
    Order *createorder(User *user, Restaurant *restaurant, vector<MenuItem *> menuitems,
                       PaymentStrategy *payment, string orderType) override
    {
        Order *newOrder;
        if (orderType == "onlineorder")
        {
            DeliveryOrder *delivery = new DeliveryOrder();
            delivery->setUserAddress(user->getUserLocation());
            newOrder = delivery;
        }
        else
        {
            PickupOrder *pickup = new PickupOrder();
            pickup->setRestaurantAddress(restaurant->getRestaurantLocation());
            newOrder = pickup;
        }
        newOrder->setRestaurant(restaurant->getRestaurantName());
        newOrder->setUser(user->getName());
        newOrder->setMenuitem(menuitems);
        newOrder->setScheduleTime(scheduleTime);
        newOrder->setPaymentStrategy(payment);

        return newOrder;
    }
}

#endif