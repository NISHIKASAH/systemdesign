#pragma once
#include<iostream>
using namespace std;

class DeliveryPartner { 
    string name;
    public : 
    DeliveryPartner(string n){
        name = n;
        cout<<"deliverypartner class"<<endl;
    }
   void delivery(){
    cout<<" order is ready to delivery by : "<<name;
    }

};