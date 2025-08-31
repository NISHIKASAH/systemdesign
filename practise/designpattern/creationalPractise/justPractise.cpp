#include<bits/stdc++.h>
using namespace std;

class Engine {
    public : 
    virtual void display () = 0;

};
class Wheel  {
    public : 
  virtual void display () = 0;

};

class LuxuryEngine : public Engine {
    public : 
    void display () override {
        cout<<"Luxury Engine"<<endl;
    }
 
};
class LuxuryWheel : public Wheel {
    public : 
    void display () override {
        cout<<"Luxury Wheel"<<endl;
    }
 
};

class SportyEngine : public Engine {
    public : 
    void display () override {
        cout<<"Sporty Engine"<<endl;
    }
 
};
class SportyWheel : public Wheel {
    public : 
    void display () override {
        cout<<"Sporty Wheel"<<endl;
    }
 
};

class VehicleFactory {
    public : 
    virtual Engine * createEngine() = 0;
    virtual Wheel * createWheel() = 0;
    
};

class LuxuryVehicleFactory : public VehicleFactory {
    public : 
    Engine * createEngine() {
        return new LuxuryEngine();

    }
    Wheel *createWheel(){
        return new LuxuryWheel();
    }
};

class SportyVehicleFactory : public VehicleFactory {
    public : 
    Engine * createEngine() {
        return new SportyEngine();

    }
    Wheel *createWheel(){
        return new SportyWheel();
    }
};

int main(){

    LuxuryVehicleFactory * luxury = new LuxuryVehicleFactory();
   Engine * lengine =  luxury->createEngine();
   lengine->display();
   Wheel * lwheel = luxury->createWheel();
   lwheel->display();


   SportyVehicleFactory * sporty  = new SportyVehicleFactory();
   Engine * sengine  = sporty->createEngine();
   sengine->display();
   Wheel* swheel = sporty->createWheel();
   swheel->display();



}