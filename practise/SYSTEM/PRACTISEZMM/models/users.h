#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include "../models/cart.h"
using namespace std;

class User
{
private:
    string id = 0;
    static int userid;
    string name;
    string location;
    Cart *cart;

public:
    // getter and setter
    User(string name, string loc)
    {
        this->name = name;
        this->location = loc;
        cart = new Cart();
        this->userid = ++id;
    }
    ~User()
    {
        delete cart;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setUserLocation(string loc)
    {
        this->location = loc;
    }
    string getUserLocation()
    {
        return location;
    }
    Cart *getCart()
    {
        return cart;
    }
};
#endif