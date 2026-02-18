#pragma once 
#include<iostream>
#include "../extrenal/bluetooth.hpp"
#include "./outputdevice.hpp"
using namespace std;


class Bluetoothadapter : public Outputdevice {
   Bluetooth * bluetooth;
    public : 
    Bluetoothadapter(Bluetooth * b){
        bluetooth = b;

    }
    void playSong( Song *song ) override {
        bluetooth->play(song);

    }



};