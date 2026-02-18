#pragma once 
#include<iostream>
#include<vector>
#include<string>
#include "./menucard.hpp"
using namespace std ;

class Restaurant { 
    private : 
    string rname;
    string rlocation;
    vector<Menucard*>RestMenuList;
    public : 
    Restaurant(string n , string loc , vector<Menucard*>menu){
        rname = n;
        rlocation = loc;
        RestMenuList = menu;
    }
    void addMenuItem(Menucard * item){
        RestMenuList.push_back(item);
    }
    vector<Menucard*>getRestMenuCard(){
        return RestMenuList;
    }

   void setRestName(string name){
         rname = name;
    }
    void setRestLoc(string loc){
        rlocation = loc;
    }
    string getRestName(){
        return rname;
    }
    string getRestLoc(){
        return rlocation;
    }

};
