#pragma once
#include <iostream>
#include "./manager/deepstoremanager.hpp"
#include "./order/user.hpp"
#include "./product/productdetail.hpp"
#include "./strategy/thresholdreplenish.hpp"
#include "./strategy/weeklyreplenish.hpp"
using namespace std;

class Zeptorchestra
{
public:
   static void viewAllItems(User *user)
    {
        int x = user->getuserxcoordinate();
        int y = user->getuserycoorinate();
        vector<Deepstore *> deepstorelist = DeepstoreManger::getManagerInstance()->getNearByStore(x, y, 5);

        map<int, string> skutoname;
        map<int, int> skutoprice;
        for (auto stores : deepstorelist)
        {
            for (auto items : stores->getAllProduct())
            {
                int suk = items->getSuk();
                skutoname[suk] = items->getName();
                skutoprice[suk] = items->getPrice();
            }
        }
        for (auto& items : skutoprice)
        {
            cout << "  SKU " << items.first << " - " << skutoname[items.first] << " $" << items.second << "\n";
        }
    }

   static void initilization()
    {
        Replenish *weekly = new WeeklyReplenish();
        Deepstore *deepstore1 = new Deepstore("deepstore1", 1, 3, weekly);
        deepstore1->addstocktostore(101, 4);
        deepstore1->addstocktostore(102, 2);
        deepstore1->addstocktostore(103, 4);
        deepstore1->addstocktostore(201, 1);
        deepstore1->addstocktostore(202, 3);

        Deepstore *deepstore2 = new Deepstore("deepstore2", 1, 1, weekly);

        deepstore2->addstocktostore(101, 4);
        deepstore2->addstocktostore(102, 2);
        deepstore2->addstocktostore(103, 4);
        deepstore2->addstocktostore(201, 1);
        deepstore2->addstocktostore(202, 3);

        DeepstoreManger * deepstoremanager = DeepstoreManger::getManagerInstance();
        deepstoremanager->registerStores(deepstore1);
        deepstoremanager->registerStores(deepstore2);

        deepstoremanager->viewAllStoreListed();
        
    }

};