#include<bits/stdc++.h>
using namespace std;

class MenuCard {
     public :
     string name ;
     int price;
     string itemCode; 

     MenuCard(string name , int price ,string code){
        this->name = name;
        this->price = price;
        this->itemCode = code;
     }
     //Getters and setters
    string getCode() const {
        return itemCode;
    }

    void setCode(const string &c) {
        itemCode = c;
    }

    string getName() const {
        return name;
    }

    void setName(const string &n) {
        name = n;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int p) {
        price = p;
    }


};
