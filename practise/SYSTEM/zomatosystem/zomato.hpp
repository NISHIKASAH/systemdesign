#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "./managers/orderManager.hpp"
#include "./managers/restaurantManager.hpp"
#include "./factories/scheduleFactory.hpp"
#include "./factories/nowFactory.hpp"
#include "./strategies/creditCard.hpp"
#include "./strategies/upiCard.hpp"
#include "./factories/orderFactory.hpp"
#include "./notification.hpp"

class ZomatoApp
{
public:
    void initilization()
    {
        RestuarantManager *restaurantmanager = RestuarantManager ::getRestManager();
        vector<Menucard *> southcuisine = {new Menucard("idli", 100), new Menucard("dosa", 120)};
        vector<Menucard *> northcuisine = {new Menucard("somosa", 12), new Menucard("momo", 60)};
        restaurantmanager->addRestaurant(new Restaurant("desiChennai", "chennai", southcuisine));
        restaurantmanager->addRestaurant(new Restaurant("benarasiya", "banaras", northcuisine));
    }
    vector<Restaurant *> getRestaurantByLocSearch(string location)
    {
        RestuarantManager *restaurantmanager = RestuarantManager ::getRestManager();
        vector<Restaurant *> searchRestaurant = restaurantmanager->searchRestaurantByLoc(location);
        return searchRestaurant;
    }

    void selectRestaurant(User *user, Restaurant *res)
    {
        user->getUserCart()->setRestaurant(res);
    }
    void addItemToUserCart(User *user, string dishName)
    {
        Restaurant *selectedRes = user->getUserCart()->getRestaurant();
        vector<Menucard *> menuList = selectedRes->getRestMenuCard();
        for (Menucard *menu : menuList)
        {
            if (menu->getItemName() == dishName)
            {
                user->getUserCart()->addItemToCard(menu->getItemName());
                cout << "\n item added into cart \n";
            }
        }
    }

    Order *checkOutSchedule(User *user, string orderType, Payment *paymentstrategy, string timing)
    {
        return checkOut(user, orderType, paymentstrategy, new ScheduleFactory(timing));
    }
    Order *checkoutNow(User *user, string orderType, Payment *paymentstrategy)
    {
        return checkOut(user, orderType, paymentstrategy, new NowReadyFactory());
    }

    Order *checkOut(User *user, string orderType, Payment *paymentstrategy, OrderFactory *orderfactory)
    {
        if (user->getUserCart()->isCartEmpty())
        {
            cout << "\nCart is empty \n";
            return nullptr;
        }
        Restaurant *res = user->getUserCart()->getRestaurant();
        vector<Menucard *> itemselected = user->getUserCart()->getCartItem();
        int totalAmount = user->getUserCart()->totalAmount();
        Order *order = orderfactory->createOrder(res, itemselected, user, paymentstrategy, orderType);
        OrderManager *ordermanager =  OrderManager ::getOrderManager();
        ordermanager->addOrder(order);
        return order;
    }
    void PaymentProcess(Order * order){
        
       bool paymentstatus =  order->processToPayment();
       if(paymentstatus){
        Notification * notify = new Notification();
        notify->getNotify(order);
        order->getUser()->getUserCart()->clearCart();
       }
       else{
        cout<<" \n Something went wrong while making payment \n";
       }

    }
    void viewOrderItem(User *user){
        vector<Menucard*>CartItems= user->getUserCart()->getCartItem();
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : CartItems) {
            cout  << item->getItemName()<<":  $ " << item->getItemPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : $" << user->getUserCart()->totalAmount() << endl;
    }
};