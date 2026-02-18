#pragma once
#include<iostream>
#include<string>

using namespace std;

class Menucard {
    private : 
    string mname;
    int mprice;
    public : 
    Menucard(string n , int p){
        mname = n;
        mprice = p;
    }
   string getItemName(){
    return mname;
    }
    int getItemPrice(){
        return mprice;
    }

};