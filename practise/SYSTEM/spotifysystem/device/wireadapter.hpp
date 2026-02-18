#pragma once 
#include<iostream>
#include<vector>
#include "../external/WireApi.hpp"
#include "../device/outputdevice.hpp"
using namespace std;


class WiredDevice : public OutPutDevice  {
    private : 
    WiredApi * wireapi ;
    public : 
    WiredDevice(WiredApi * deviceapi){
        wireapi = deviceapi;
    }
    void playSound(Song * song) override {
        string payload = song->getName() + "by" + song->getArtist();
        wireapi->PlaySongViaWire(payload);
    }
};