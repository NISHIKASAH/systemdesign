#pragma once 

#include<iostream>
#include "../model/song.hpp"
using namespace std;

class Speaker {
    public : 
  void play(Song * song){
        cout<<"extrenal speaker device"<<endl;
        cout<<"playing song"<<song->gettitle();
    }
};