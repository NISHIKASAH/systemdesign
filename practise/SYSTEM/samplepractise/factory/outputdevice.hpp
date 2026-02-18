#pragma once
#include<iostream>
#include "../model/song.hpp"
using namespace std;

class Outputdevice {
    public : 
   virtual void playSong( Song *song ) =0;
};