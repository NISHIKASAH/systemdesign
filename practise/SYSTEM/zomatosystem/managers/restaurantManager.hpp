#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../model/restaurant.hpp"


using namespace std;

class RestuarantManager {
   vector<Restaurant*>ListOfRestaurant;
   static RestuarantManager * restManagerInstance ;
   RestuarantManager(){};
    public : 
    static RestuarantManager*getRestManager(){
        if(restManagerInstance == nullptr){
            restManagerInstance = new RestuarantManager();
        }
        restManagerInstance;
    }
    void addRestaurant(Restaurant * restaurant){
        ListOfRestaurant.push_back(restaurant);
    }
   vector< Restaurant*> searchRestaurantByLoc(string location){
     vector< Restaurant*>searchedRestaurant;
        for(Restaurant * res : ListOfRestaurant){
            if(res->getRestLoc() == location){
                searchedRestaurant.push_back(res);
            }
        }
        return searchedRestaurant;
    }

};

RestuarantManager * RestuarantManager ::restManagerInstance = nullptr;