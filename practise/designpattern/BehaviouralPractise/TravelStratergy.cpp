#include<bits/stdc++.h>
using namespace std ;


/*
It lets you define a family of algorithms, 
put each of them in a separate class, and make 
them interchangeable at runtime.
bus  ,car , train is a strategy for travel.
You as a person decide at runtime which strategy to use.

prevent from changing vehcileStrategy code , prevent huge if-else use . 
*/
class Vehicle {
    public : 
    virtual void Travel(string name , int price) =0;

};

class Bike : public Vehicle
 {

    public : 
    void Travel(string name , int price) override {
        cout<<"Name: "<<name;
        cout<<"Price: "<<price<<endl;
    }

 };
 
class Bus : public Vehicle
 {

    public : 
    void Travel(string name , int price) override {
        cout<<"Name: "<<name;
        cout<<"Price: "<<price<<endl;
    }

 };
 
class Car : public Vehicle
 {

    public : 
    void Travel(string name , int price) override {
        cout<<"Name: "<<name;
        cout<<"Price: "<<price<<endl;
    }

 };

 class VehicleStratergy {
    private : 
    Vehicle * stratergy;
    public : 
    VehicleStratergy(Vehicle* st){
        this->stratergy = st;
    }

    void VehicleTravelCost(string name , int  price){
        stratergy->Travel(name , price);

    }
 
 };
int main(){
    cout<<"Implement Stratergy " <<endl;
    Bus* bus = new Bus();
    Car * car = new Car();
    Bike *bike = new Bike();

    VehicleStratergy* str = new VehicleStratergy(bus);
    str->VehicleTravelCost("Bus" , 23);

    str->VehicleTravelCost("Car" , 278);
    

}