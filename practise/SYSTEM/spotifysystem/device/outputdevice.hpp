#pragma once 
#include<iostream>
#include<vector>
#include "../model/song.hpp"
using namespace std;


class OutPutDevice {
    public :

    virtual void playSound(Song * song) = 0;
      virtual ~OutPutDevice() = default;
};