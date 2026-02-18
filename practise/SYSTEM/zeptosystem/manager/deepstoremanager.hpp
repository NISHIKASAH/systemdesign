#pragma once
#include<iostream>
#include<algorithm>
#include<cmath>
#include "../product/deepstore.hpp"
using namespace std;

class DeepstoreManger { 
    vector<Deepstore*>deepstorelist;
    static DeepstoreManger * deepstoremanagerinstance;
     DeepstoreManger(){}
    public : 

    ~DeepstoreManger(){
        for(auto stores : deepstorelist){
            delete stores;
        }
    }
    static DeepstoreManger * getManagerInstance(){
        if(deepstoremanagerinstance == nullptr){
            deepstoremanagerinstance = new DeepstoreManger();
        }
        return deepstoremanagerinstance;

    }
    void registerStores(Deepstore * store){
        deepstorelist.push_back(store);
        cout<<"Manager added store : " <<store->getName()<<endl;
    }
    void viewAllStoreListed(){
        for(auto stores : deepstorelist){
            cout<<"Store : "<<stores->getName()<<" ";
        }
        cout<<endl;
    }
    vector<Deepstore*>getNearByStore( int x , int y , int mindis){
        vector<pair<int , Deepstore*>>nearbystore;
        for(auto stores : deepstorelist){
          int dist =  stores->distanceTo(x , y);
          if(dist <= mindis){
            nearbystore.push_back(make_pair(dist , stores));
          }
        }
        sort(nearbystore.begin() , nearbystore.end(), [](pair<int,Deepstore *>&a ,pair<int,Deepstore *>&b){
            return a.first < b.first;
        } );
        vector<Deepstore*>result ; 
        for(auto& it : nearbystore){
            result.push_back(it.second);
        }
        return result;
    }

    
   
};
 DeepstoreManger* DeepstoreManger::deepstoremanagerinstance = nullptr;