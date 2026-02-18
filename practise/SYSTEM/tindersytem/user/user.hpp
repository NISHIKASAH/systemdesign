#pragma once
#include<iostream>
#include<vector>
#include<map>
#include "./enum.hpp"
#include "./preference.hpp"
#include "./profile.hpp"
using namespace std;

class User {
    string id ;
    map< string, SwipeType>swipeHistory;
    Profile * profile;
    Preference * preference;

    public: 
    User(string userid ){
        id =userid;
    }
   void setProfile(Profile * pro){
    profile = pro;

    }
    void setPreference(Preference * pre){
        preference = pre;
    }
    void Swapping(string targetid , SwipeType action){
      
            swipeHistory[targetid] = action;
        

    }
    bool hasLiked(string targetid){
        if(swipeHistory.find(targetid) != swipeHistory.end()){
           return SwipeType ::RIGHT ==  swipeHistory[targetid] ;
        }
        return false;
        
       
    }
    
    bool hasdisLiked(string targetid ){
        if(swipeHistory.find(targetid) != swipeHistory.end()){
            return SwipeType ::LEFT == swipeHistory[targetid];
        }
        return false;
    }
    bool showedSomeinterest(string targetid ){
        if(swipeHistory.find(targetid) != swipeHistory.end()){
            return true;
        }
        return false;
    }

    void displayProfile(){
        cout<<"User Profile "<<endl;
        cout<<"Name : "<<profile->getName()<<endl;
        cout<<"Age : "<<profile->getAge()<<endl;
        cout<<"Interest includes : "<<endl;
        vector<string>interest = preference->getAllInterest();
        for(auto it : interest){
            cout<<it<< " ";
        }
        cout<<endl;

    }

    


    

};