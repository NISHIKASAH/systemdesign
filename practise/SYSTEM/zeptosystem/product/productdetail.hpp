#pragma once
#include <iostream>
using namespace std;


class Product {
    private : 
    string name ; 
    int price; 
    int suk;
    public : 
    Product( int id , string n , int p ){
         suk = id;
        name = n;
        price = p;
       

    }
    string getName(){
        return  name;
    
    }
    int getPrice(){
        return price;
    }
    int getSuk(){
        return suk;
    }

};
