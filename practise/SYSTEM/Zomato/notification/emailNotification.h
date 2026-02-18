#include<bits/stdc++.h>
#include "../model/order.h"
#include "notification/notification.h"
using namespace std;


class EmailNotification : public Notification {
    public : 
    EmailNotification(Order * order) : Notification(order){};

    void getNotification(){
       int orderid =  order->getOrderId();
       cout<<"Email has been sent successfully for orderId :"<<orderid<<endl;
    }
};