#include<bits/stdc++.h>
#include "model/user.h"
#include "model/restaurant.h"
#include "model/menuCard.h"
#include "strategies/creditCardPayment.h"
#include "strategies/upiPayment.h"
using namespace std;

class Order {
    private : 
    static  int nextorderId ;
    vector<MenuCard*>menulist;
    Restaurant * restaurant;
    Payment * payment;
    User * user;
     int orderId ;
     string schedule ;
     int totalAmount ;
    public : 
    Order(){
        this->restaurant = nullptr ;
        this->user = nullptr;
        this->orderId = ++nextorderId;
        schedule="";
        totalAmount = 0;
    }
    bool processPayment(){
        if(payment){
            payment->doPayment(totalAmount );
            return true;
        }
        else{
            cout<<"First Choose a payment strategy"<<endl;
            return false;
        }
        
        
    }
    virtual  string orderType () = 0;
    void setUser(User *  user){
        user = user;
    }
    User * getUser(){
        return user;

    }
    void setPaymentStrategy(Payment * paymentstrategy){
        payment = paymentstrategy;
    }
    Payment * getPaymentStrategy(){
        return payment;
    }

     void setRestaurant(Restaurant *res){
        restaurant = res;
    }
    Restaurant * getRestaurant(){
        return restaurant;

    }
    void setMenuCard(vector<MenuCard*>menu){
        menulist = menu;

    }
    int gettotalAmount(){
        int total = 0;
        for(auto item : menulist){
            total += item->getPrice();
        }
        return total;
    }
    int settotalAmount(int amount ){
        totalAmount =amount;
    }
    vector<MenuCard*>getMenuCard(){
        return menulist;
    }
    void setOrderId(int id ){
        orderId = id;
        
    }

    int getOrderId(){
        return orderId;
    }
    
    void setScheduled(const string& s) {
        schedule = s;
    }

    string getScheduled() const {
        return schedule;
    }
};

int Order ::nextorderId = 0;
