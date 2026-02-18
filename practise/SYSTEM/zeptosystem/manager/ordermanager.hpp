#pragma once
#include <iostream>
#include <vector>
#include "../manager/deepstoremanager.hpp"
#include "../order/user.hpp"
#include "../order/userorder.hpp"
#include "../order/deliverypartner.hpp"
using namespace std;

class OrderManager
{
    static OrderManager *ordermanagerinstance;
    vector<Order *> orderList;
    OrderManager()
    {
       
    }

public:
    static OrderManager *getOrdermanagerinstance()
    {

        if (ordermanagerinstance == nullptr)
        {

            ordermanagerinstance = new OrderManager();
        }
        return ordermanagerinstance;
    }
    void placeOrder(User *user, Cart *cart)
    {
       

        map<int, int> cartqtytrack;
        vector<pair<Product *, int>> cartitem = cart->getCartitems();
        int distance = 5;
        Order *neworder = new Order(user);

        for (auto it : cartitem)
        {
            neworder->Item.push_back(it);
            cartqtytrack[it.first->getSuk()] = it.second;
        }
 
        DeepstoreManger *manager = DeepstoreManger ::getManagerInstance();
        vector<Deepstore *> deepstores = manager->getNearByStore(user->getuserxcoordinate(), user->getuserycoorinate(), 5);
        if (deepstores.size() == 0)
        {
            cout << "NO store availabale within " << distance;
            return;
        }
        bool allitemavailable = true;
        bool placed = false;
        
        for (auto stores : deepstores)
        {
            allitemavailable = true;
            for (auto &item : cartitem)
            {
                
                int sku = item.first->getSuk();
                int qty = item.second;
                 cout<<"place order 1"<<endl;
                int availableqty = stores->checkProductStock(sku);
                 cout<<"place order 1111"<<endl;
                int requiredqty = qty;
                 cout<<"place order 22"<<endl;
                if (availableqty < requiredqty)
                {
                    allitemavailable = false;
                    break;
                }
            }
            

            if (allitemavailable)
            {

                for (auto &item : cartitem)
                {
                    int sku = item.first->getSuk();
                    int qty = item.second;
                    int availableqty = stores->checkProductStock(sku);
                    int taken = min(qty, availableqty);
                    if (taken > 0)
                    {
                        stores->removestockfromstore(sku, taken);
                        cartqtytrack[sku] = 0;
                    }
                }
                cout<<"place order 2"<<endl;
                DeliveryPartner *deliverypartner = new DeliveryPartner("hitesh");

                cout << "new Order created for user :" << user->getName() << endl;
                neworder->partners.push_back(deliverypartner);
                orderList.push_back(neworder);
                cout<<"place order 3"<<endl;
                neworder->total = cart->getTotal();
                cout<<"place order 4"<<endl;
                cout << "delivered by deliverypartner1 :" << endl;
                deliverypartner->delivery();

                placed = true;
                break;
            }
        }
        if (!placed)
        {
            int partnerid = 0;
            bool assigned = false;

            for (auto stores : deepstores)
            {
                assigned = false;
                for (auto &item : cartitem)
                {
                    int sku = item.first->getSuk();
                    int qty = item.second;
                    int availableqty = stores->checkProductStock(sku);
                    int requiredqty = qty;

                    if (availableqty > 0)
                    {
                        assigned = true;
                    }
                }
                if (assigned)
                {

                    for (auto &item : cartitem)
                    {
                        int sku = item.first->getSuk();
                        int qty = item.second;
                        int availableqty = stores->checkProductStock(sku);
                        int requiredqty = qty;

                        int taken = min(availableqty, requiredqty);
                        if (taken > 0)
                        {
                            cartqtytrack[sku] -= taken;
                            stores->removestockfromstore(sku, taken);
                        }
                    }
                    DeliveryPartner *deliverypartner = new DeliveryPartner(to_string(++partnerid));
                    int sum = 0;
                    for (auto it : neworder->Item)
                    {
                        sum += it.first->getPrice() * it.second;
                    }
                    neworder->total = sum;

                    neworder->total = sum;
                    neworder->partners.push_back(deliverypartner);
                    orderList.push_back(neworder);
                    cout << "new Order created for user :" << user->getName() << endl;
                    cout << "order delivered by deliverypartner :" << partnerid << endl;
                }
            }
            for (auto cart : cartqtytrack)
            {
                if (cart.second != 0)
                {
                    cout << "Could not fullfill other items \n";
                }
            }
        }
    }
};

OrderManager *OrderManager ::ordermanagerinstance = nullptr;
