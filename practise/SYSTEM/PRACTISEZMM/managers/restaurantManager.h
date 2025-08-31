#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include <iostream>
#include "../models/restaurant.h"
using namespace std;


class RestaurantManger {
     private : 
     vector<Restaurant*>RestaurantList;
    static  RestaurantManger * restaurantInstance; 
    RestaurantManger(){};
     public : 

     static RestaurantManger * getRestaurantManagerInstance(){
        if(RestaurantList == nullptr){
            restaurantInstance = new RestaurantManger();
        }
        return restaurantInstance;
     }
    void addRestaurant(Restaurant * res ){
        RestaurantList.push_back(res);

     }
     vector<Restaurant*>searchRestaurantByLocation(string loc){
        vector<Restaurant*>searchList;
        transform(loc.begin() , loc.end() , loc.begin(), :: tolower);
        for(auto lc : RestaurantList){
            string res = lc->setRestaurantLocation();
             transform(res.begin() , res.end() , res.begin() ,:: tolower);
            if( res == loc){
               
                searchList.push_back(res);
            }
        }
     }





};

RestaurantManger * RestaurantManger ::  restaurantInstance = nullptr;

#endif