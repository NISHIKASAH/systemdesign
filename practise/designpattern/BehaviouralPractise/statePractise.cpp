#include<bits/stdc++.h>
using namespace std;

class RideState {
    public : 
    virtual void handleRequest() = 0;
    virtual void handleCancel() =0;
};
class RequestRidestate  : public RideState {
    public : 
    void handleRequest() override {
        cout<<"Request for ride"<<endl;
    }
    void handleCancel() override {
        cout<<"Cancel ride"<<endl;
    }
};
class AssignDriverstate : public RideState {
    public : 
    void handleRequest () override {
        cout<<"Driver assigned "<<endl;
    }
    void handleCancel () override {
        cout<<"Driver  cancelled ride"<<endl;
    }

};
class RideStartedstate  : public RideState {
    public : 
    void handleRequest () override {
        cout<<"Ride has been started "<<endl;
    }
    void handleCancel () override {
        cout<<"Ride started cannot be cancelled "<<endl;
    }

};

class Ride {
    RideState * state ;
    public : 
    Ride (){
        state = new RequestRidestate();

    }
    void setRide(RideState * newstate ){
        state = newstate;
    }
    void RequestRide(){
        state->handleRequest();
    }
    void cancelRide(){
        state->handleCancel();
    }
};
int main(){

    Ride ride;
    ride.RequestRide();
    ride.cancelRide();

    ride.setRide(new AssignDriverstate());
    ride.RequestRide();
    ride.cancelRide();

    ride.setRide(new RideStartedstate());
    ride.RequestRide();
    ride.cancelRide();
    


}