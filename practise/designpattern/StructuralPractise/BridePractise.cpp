#include<bits/stdc++.h>
using namespace std;


//Implemntation 

class Navigation {
    protected:
    string pickUp;
    string drop;
    public : 
    Navigation(string pick , string drop ){
        this->pickUp = pick;
        this->drop = drop;

    }
    virtual void showpickupLocation() = 0;
    virtual void showDropLocation()= 0 ;


};
class GoogleNavigation : public Navigation  {
    public : 
    GoogleNavigation(string pickup ,string drop ) : Navigation (pickup ,drop  ){};

    void showpickupLocation() override{
        cout<<"Google location "<<this->pickUp<<endl; 

    }
    void showDropLocation() override {
         cout<<"Google location "<<this->drop<<endl; 
    }


}; 

class AppleNavigation : public Navigation  {
    public : 
    AppleNavigation(string pickup , string drop) : Navigation (pickup , drop ){};

     void showpickupLocation() override{
        cout<<"Apple location "<<this->pickUp<<endl; 

    }
    void showDropLocation() override {
         cout<<"Apple location "<<this->drop<<endl; 
    }



}; 

//Abstraction layer
class Ride  { 
   protected :
    Navigation * navigation ; 
    public : 
    Ride(Navigation * navigation){
        this->navigation  = navigation ; 
    }
    virtual void PickUpLocation() =0 ;
    virtual void DropLocation() = 0;


};
class Uber  : public Ride  {
    public :
    Uber (Navigation * navigation) : Ride(navigation) {};
   void PickUpLocation() override {
     navigation->showpickupLocation();
    }
    void DropLocation() override {
        navigation->showDropLocation();

    }

}; 
class Ola : public Ride  {
    public :
    Ola(Navigation * navigation ):Ride ( navigation) {};
   void PickUpLocation() override {
     navigation->showpickupLocation();
    }
    void DropLocation() override {
        navigation->showDropLocation();

    }

};
//client 


int main(){
    Navigation * navigation = new GoogleNavigation("Eldin spx" , "ramaburam");

    Ride * ride= new Ola(navigation);
    ride->PickUpLocation();
    ride->DropLocation();

}


