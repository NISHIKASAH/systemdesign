#include<bits/stdc++.h>
#include"../model/order.h"
using namespace std;

class Notification {
    protected:
    Order * order;
     public : 
     Notification(Order  *o){
        order = o;
     }
     virtual void getNotification() =0 ;
};
