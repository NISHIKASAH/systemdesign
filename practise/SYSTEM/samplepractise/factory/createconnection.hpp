#pragma once
#include<iostream>
#include "../enum/deviceType.hpp"
#include "./bluetoothadapter.hpp"
#include "./speakeradapter.hpp"
using namespace std;


class ConnectonFactory {
     public : 
     Outputdevice* createconnection(deviceType type){
        if(type == deviceType::BLUETOOTH){
            return new Bluetoothadapter(new Bluetooth());
        }
        else if(type == deviceType ::SPEAKER){
            return new Speakeradapter(new Speaker());
        }
        else{
            cout<<"No type found !!"<<endl;
        }
     }
};