#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
using namespace std;

class MenuItem
{
private:
    string code;
    string name;
    int price;

public:
    MenuItem(string n, int p, string c)
    {
        this->name = n;
        this->price = p;
        this->code = c;
    }
    // getter and setter

    void setCode(string s)
    {
        this->code = s;
    }
    string getCode()
    {
        return code;
    }

     void setPrice(string )
    {
        this->price = p;
    }
    int getPrice()
    {
        return price;
    }

     void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
};

#endif