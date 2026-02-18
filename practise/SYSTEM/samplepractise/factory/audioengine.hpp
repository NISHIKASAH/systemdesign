#pragma once 
#include<iostream>
#include "./outputdevice.hpp"
using namespace std;

class AudioEngine {
   bool ispause ;
Outputdevice * outputdevice; 

    public :
    void playSong( Song * song , Outputdevice * device ){
        ispause = false;
        device->playSong(song);

    }
    void pause(Song * song){
        if(ispause == false){
            cout<<"already pause"<<endl;
        } 
        ispause = !ispause;


    }
};