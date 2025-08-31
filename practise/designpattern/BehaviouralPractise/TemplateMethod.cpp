#include<bits/stdc++.h>
using namespace std;

/*
TemplateMethod : define skeleton of algorithm(template method) in base class, 
and allow subclass to override template method ,  without changing its structure . 

Promite : code reuseability 
*/
class OrderTemplate {
    public : 
    void processOrder(){ // template method contains common steps  , use by all subclasses 
        selectItem();
        doPayment();
        getDeliver();
    }
    virtual void selectItem() = 0;
    virtual void doPayment() =0 ;
    virtual void getDeliver() =0 ;

};
class InternaltionOrder : public  OrderTemplate {
    public : 
    void selectItem() override {
        cout<<"selecting item - international "<<endl;
    }
    void doPayment() override {
        cout<<"Make payement - international "<<endl;
    }
    void getDeliver() override {
        cout<<"Order to be delivered -international "<<endl;
    }
};

class LocalOrder : public  OrderTemplate {
    public : 
    void selectItem() override {
        cout<<"selecting item- local "<<endl;
    }
    void doPayment() override {
        cout<<"Make payement -local "<<endl;
    }
    void getDeliver() override {
        cout<<"Order to be delivered -local "<<endl;
    }
};
int main(){

    OrderTemplate * international = new InternaltionOrder();
    international->processOrder();
    cout<<endl<<"-------------------"<<endl;
    OrderTemplate * local = new LocalOrder();
    local->processOrder();
    delete international ; 
    delete local;



}