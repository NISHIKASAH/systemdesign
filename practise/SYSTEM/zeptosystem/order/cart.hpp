#pragma once
#include<iostream>
#include<vector>
#include "../product/productdetail.hpp"
#include "../product/productfactory.hpp"
using namespace std;

class Cart{
    private : 
    vector<pair<Product*,int>>cartItems;
    public : 
    void addToCart(int sku,int qty){
       Product * product =  ProductFactory ::createproduct(sku);
        cartItems.push_back(make_pair(product, qty));
    }
    int getTotal(){
        int total =0 ;
        cout<<"total cart start"<<endl;
        for(auto items : cartItems){
            total += items.first->getPrice()*items.second ;
        }
         cout<<"total cart end"<<endl;
        return total;

    }
    void viewCartProduct(){
        for(auto it : cartItems){
            cout<<"Name : "<<it.first->getName()<<" ";
        }
        cout<<endl;
    }
    void clearCart(){
        cartItems.clear();
    }
    vector<pair<Product*,int>>getCartitems(){
        return cartItems;
    }
};