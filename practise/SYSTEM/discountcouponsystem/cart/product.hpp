#pragma once
#include <iostream>
using namespace std;

class Product
{
private:
    string name;
    int price;
    string category;

public:
    Product(string n, int p, string c)
    {
        name = n;
        price = p;
        category = c;
    }
    string getName(string n)
    {
        return name;
    }

    string getCategory()
    {
        return category;
    }
    int getPrice()
    {
        return price;
    }
};