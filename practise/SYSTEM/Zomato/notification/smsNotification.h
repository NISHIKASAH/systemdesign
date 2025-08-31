#include<bits/stdc++.h>
#include "model/order.h"
#include "notification/notification.h"
using namespace std;


class SMSNotification : public Notification {
    public : 
    SMSNotification(Order * order) : Notification(order){};

    void getNotification(){
       int orderid =  order->getOrderId();
       cout<<"SMS has been sent successfully for orderId :"<<orderid<<endl;
    }
};