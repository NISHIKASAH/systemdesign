#include<bits/stdc++.h>
using namespace std;

class Ac {
    public : 
    void startAc(){
        cout<<"Ac turn on "<<endl;
    }
    void endAc(){
        cout<<"Ac turn off "<<endl;
    }
};

class Light {
    public : 
    void turnOn(){
        cout<<"light turn on "<<endl;
    }
    void turnOff(){
        cout<<"light turn off "<<endl;
    }
};
class Curtain {
    public : 
    void openCurtains(){
        cout<<"curtains open "<<endl;
    }
    void closeCurtains(){
        cout<<" curtains close "<<endl;
    }
};

class FacadeClass {
    Curtain* curtain ; 
    Light * light;
    Ac * ac ; 
    public:
    FacadeClass(Curtain * curtain , Light * light , Ac * ac ){
        this->ac = ac; 
        this->curtain = curtain ; 
        this->light = light;

    }
    void startRelaxMode(){
        this->curtain->openCurtains();
        this->light->turnOn();
        this->ac->startAc();
    }

    void endRelaxMode(){
        this->curtain->closeCurtains();
        this->light->turnOff();
        this->ac->endAc();
    }

};

int main(){
    Light * light = new Light();
    Curtain * curtain = new Curtain();
    Ac * ac = new Ac();
    FacadeClass * facade  = new FacadeClass(curtain , light , ac);
    facade->startRelaxMode();
    cout<<"-----------"<<endl;
    facade->endRelaxMode();

}