#pragma once
#include<iostream>
#include<vector>
#include "./enum.hpp"
using namespace std;

class Preference{
    int minage ;
    int maxage ;
    vector<GenderType>interestedIn ;
    vector<string>interests;

    public : 


    void setMinage(int x){
        minage = x;
    }
    void setMaxage(int y){
        maxage = y;
    }

    int getMinage(){
        return minage;
    }
    int getMaxage(){
        return maxage;
    }

   void addGender(GenderType type){
        interestedIn.push_back(type);
    }
    void addInterest(string interest){
        interests.push_back(interest);
    }
    vector<GenderType>getGender(){
        return interestedIn;
    }
    vector<string>getAllInterest(){
        return interests;
    }
    

};