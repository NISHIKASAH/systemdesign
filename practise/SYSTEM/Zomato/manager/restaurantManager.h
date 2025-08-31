#include<bits/stdc++.h>
#include "./model/restaurant.h"

class RestaurantManager {
    static RestaurantManager * instance ;
    vector<Restaurant*>restarantList;
    RestaurantManager(){
    }
      public : 
      static RestaurantManager * getrestaurantManager(){
        if(instance == nullptr){
            instance = new RestaurantManager();
        }
        return instance;
      }

    void addRestaurant(Restaurant* rest) {
        restarantList.push_back(rest);
    }
   vector<Restaurant*>searchRestaurantByLoc(string loc){
    vector<Restaurant*>restList;
     transform(loc.begin() , loc.end()  , loc.begin(), :: tolower);
    for(auto it : restarantList){
       string resloc =  it->getLocation();
       transform(resloc.begin() , resloc.end(), resloc.begin() , :: tolower);
       if(loc == resloc){
        restList.push_back(it);


       }
       
    }
    return restList;
   }



};
RestaurantManager* RestaurantManager :: instance = nullptr;