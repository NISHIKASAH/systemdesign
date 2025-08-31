#include<bits/stdc++.h>
using namespace std;

/*
Bridge pattern  : Bridge Pattern is used to decouple abstraction 
from its implementation, so that both can evolve independently. 

Imagine this situation:
You are building remotes for different devices (TV, Radio).
You want to control any device using any remote.
You don’t want to rewrite the remote code when a new device is added. 
*/
// NOTE : Abstraction layer - has object pointer/ reference to other layer .

//Abstraction Layer 
class Device {
    public : 
    virtual void TurnOn() =0;
    virtual void  turnOff() = 0; 

};

class Radio : public Device {
    public : 
    void TurnOn() override  {
         cout<<"Radio On "<<endl;
    
    }
     void turnOff() override {
         cout<<"Radio Off "<<endl;
    
    }
};

class Tv: public Device {
    public : 
    void TurnOn() {
         cout<<"Tv On "<<endl;
    
    }
     void TurnOff() {
         cout<<" Tv Off "<<endl;
    
    }
}; 

class Fan : public Device {
    public : 
    void TurnOn() {
         cout<<"Fan On "<<endl;
    
    }
     void TurnOff() {
         cout<<"Fan Tv Off "<<endl;
    
    }
}; 
//Implementation Layer 
class Remote {
    Device * device;
    public: 
    Remote(Device * device ) {
        this->device = device;
    }
    virtual void Play() =0 ;
    virtual void powerOff() =0;
    
};

class SmartRemote : public Remote  {
    public : 
    SmartRemote(Device * device) : Remote(device){}; 
    void Play() override {
        cout<<"Turn On "<<endl;
    }
    void powerOff() override{
         cout<<"Turn Off "<<endl;
    }
    void pause(){
        cout<<"Pause "<<endl;
    }
};

class TraditionalRemote : public Remote {
    public :
    TraditionalRemote(Device * device) : Remote(device) {}; 
    void Play() override {
        cout<<"Turn On "<<endl;
    }
    void powerOff() override{
         cout<<"Turn Off "<<endl;
    }
}; 
int main(){
    Device * radio = new Radio();

    SmartRemote *smartremote = new SmartRemote(radio);
    smartremote->Play();
    smartremote->pause();
    smartremote->powerOff();


}