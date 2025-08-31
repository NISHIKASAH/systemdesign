#include<bits/stdc++.h>
#include<model/cart.h>
using namespace std;


class User {
    private : 
    string name;
    string address ; 
    Cart * cart;
    public : 
    User(string name , string address){
        this->name = name ; 
        this->address = address;
        this->cart = new Cart();
    }
    string getName(){
        return this->name;
    }
    string getAddress(){
        return this->address;
    }
    Cart* getCart() const {
        return cart;
    }
    

};
