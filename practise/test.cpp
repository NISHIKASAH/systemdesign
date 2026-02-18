#include <bits/stdc++.h>
using namespace std;

class Engine {
    public : 
    virtual  void start() = 0;
};

class PetrolEngine  : public Engine{
    public : 
    void start() override {
        cout<<"ignating using petrol"<<endl;
    }
};

class DesileEngine : public Engine {
    public : 
    void start() override {
          cout<<"ignating using desile"<<endl;
    }
};
class ElectricEngine : public Engine {
    public :
    void start() override {
        cout<<"ignating using electricity"<<endl;
    }
};

class Car {
    protected: 
    Engine * engine; 

    Car(Engine * e){
        engine = e;
    }
    public : 
    virtual void drive()  =0;

};

class Sudan : public Car { 
    public : 
    Sudan(Engine *e) : Car(e){};
    void drive() override {
        engine->start();
        cout<<"driving sudan car"<<endl;
    }
};

class Hundai : public Car { 
    public : 
    Hundai(Engine * e) : Car(e){};
    void drive() override {
           engine->start();
        cout<<"driving Hundai car"<<endl;
    }
};
class BMW : public Car { 
    public : 
    BMW(Engine *e) : Car(e){};
    void drive() override {
           engine->start();
        cout<<"driving bmw car"<<endl;
    }
    
};


int main(){
    Engine *pertolengine = new PetrolEngine();
    Car * bmw = new BMW(pertolengine);
    bmw->drive();
}