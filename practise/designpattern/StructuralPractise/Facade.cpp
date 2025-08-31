#include<bits/stdc++.h>
using namespace std;

/*
🧩 Facade Design Pattern Notes

- The Facade class simplifies complex tasks by providing a unified interface 
  to a set of interfaces in a subsystem(group of related class like dvd , sound , projector ).

- It interacts with multiple subsystems (like DVD player, projector, sound system),
  hiding their complexities from the client.

- The client only needs to interact with the Facade (e.g., press a single button),
  and the Facade handles the rest behind the scenes.

🎯 Purpose: To reduce coupling between client and subsystems, and make usage simpler.
*/ 

class DvdPlayer {
    string dvdName ;
    public : 
    DvdPlayer(string dvd){
        this->dvdName= dvd;
    }
    void PlayDVD(){
        cout<<"Play Dvd"<<dvdName<<endl;
    }
    void offDvd(){ 
        cout << "DVD Player is OFF\n"; 
    }
    

};
class Projector {
    string screenName ; 
    public : 
    Projector(string name){
        this->screenName = name; 
    }
    void PlayProjector(){
        cout<<"Play projector: "<<screenName<<endl;
    }
     void offprojector(){ 
        cout << "projector Player is OFF\n"; 
    }
};
class SoundSystem {
    bool isAudible ; 
    public : 
    SoundSystem(bool speaker){
        this->isAudible = speaker ; 
    }
    void checkAudibity(){
        cout<<"Check Sound : "<<(isAudible ?  "ON" : "OFF" )<<endl;
    }
     void offspeaker(){ 
        cout << "sound Player is OFF\n"; 
    }

};

class TheaterSystemFacade{
    DvdPlayer * dvd ; 
    SoundSystem *sound ; 
    Projector * projector ; 
    public : 
    TheaterSystemFacade( Projector* projector , DvdPlayer * dvd  , SoundSystem * sound){
        this->dvd = dvd;
        this->projector = projector ; 
        this->sound = sound; 
        
    }
    void PlayMovie(){
        projector->PlayProjector();
        dvd->PlayDVD();
        sound->checkAudibity();

    }
    void EndMovie(){
        projector->offprojector();
        sound->offspeaker();
        dvd->offDvd();
    }

};

int main(){
    DvdPlayer * dvd = new DvdPlayer("MirchiDVD");
    SoundSystem * sound = new SoundSystem(true);
    Projector* projector = new Projector("Saiyaara");

    TheaterSystemFacade  * facade = new TheaterSystemFacade(projector , dvd , sound);
    facade->PlayMovie();
    cout<<endl;
    cout<<"-----------------------------"<<endl;
    facade->EndMovie();

}
