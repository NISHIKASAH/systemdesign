#include<bits/stdc++.h>
using namespace std;


class Fan {

    public : 
    void on(){
        cout<<"Fan is on"<<endl;
    }
     void off(){
        cout<<"Fan is off"<<endl;
    }
};
class Light {

    public : 
    void on() {
        cout<<"Light is on"<<endl;
    }
      void off() {
        cout<<"Light is off"<<endl;
    }
};
class Curtain {

    public : 
    void on() {
        cout<<"curtain is on"<<endl;
    }
      void off() {
        cout<<"curtain is off"<<endl;
    }
};

class ICommand {
    public : 
    virtual void execute() =0;
    virtual void undo() = 0;
    

};

class LightCommand : public ICommand {
    Light * light;
    public : 
    LightCommand(Light * l){
        light = l;
    }

    void execute() override {
        light->on();
    }
    void undo() override {
        light->off();
    }

};
class FanCommand : public ICommand {
    Fan * fan;
    public : 
    FanCommand(Fan * f) {
        fan = f;
    }

    void execute() override {
        fan->on();
    }
    void undo() override {
        fan->off();
    }
    
};
class CurtainCommand : public ICommand {
    Curtain  *curtain;
    public : 
    CurtainCommand(Curtain * c) {
        curtain = c;
    }

    void execute() override {
        curtain->on();
    }
    void undo() override {
        curtain->off();
    }
    
};

class RemoteControl {
   const static int numofBtn  = 4;
   ICommand* buttons [numofBtn];
   bool pressBtn[numofBtn];
    public : 
    RemoteControl(){
        for(int i=0;i<numofBtn;i++){
            buttons[i]=  nullptr;
            pressBtn[i] = false;
        }

    }
    void setCommand(ICommand * command , int idx ){
         if(idx < 0 || idx >= numofBtn) {
            cout<<"No command assigned for !! "<<idx <<endl;
        }
        buttons[idx] = command; 
        pressBtn[idx]  = false;
    
    }
    void pressButton(int idx ){
        
        if(idx < 0 || idx >= numofBtn) {
            cout<<"cannot pressed as no command assigned !!"<<idx <<endl;
        }
       if(pressBtn[idx] == false){
        buttons[idx]->execute();

       }
       else{
        buttons[idx]->undo();
       }
       pressBtn[idx] = !pressBtn[idx];
    
    }
    ~RemoteControl(){
        for(int i=0;i<numofBtn;i++){
            delete buttons[i];
        }
    }


};

int main(){
    Fan* fan = new Fan();
    ICommand * fanCommand = new FanCommand(fan);
    RemoteControl * control = new RemoteControl();
    control->setCommand(fanCommand , 2);
    control->pressButton( 2);
    control->pressButton(2);


    Curtain* curtain = new Curtain();
    ICommand * curtainCommand = new CurtainCommand(curtain);
    RemoteControl * control2 = new RemoteControl();
    control2->setCommand(curtainCommand , 1);
    control2->pressButton(1);
    control2->pressButton(1);

    delete fan;
    delete curtain;

  


}