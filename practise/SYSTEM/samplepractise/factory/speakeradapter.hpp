#pragma once 
#include<iostream>
#include "../extrenal/speaker.hpp"
#include "./outputdevice.hpp"
using namespace std;


class Speakeradapter : public Outputdevice {
    Speaker * speaker;
    public : 
    Speakeradapter(Speaker *s){
        speaker = s;
    }
    void playSong( Song *song ) override {
        speaker->play(song);

    }



};