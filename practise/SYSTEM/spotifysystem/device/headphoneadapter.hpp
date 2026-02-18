#pragma once 
#include<iostream>
#include<vector>
#include "../external/HeadPhoneApi.hpp"
#include "../device/outputdevice.hpp"
using namespace std;


class HeadPhoneDevice : public OutPutDevice  {
    private : 
    HeadPhoneApi  * headphoneapi ;
    public : 
    HeadPhoneDevice(HeadPhoneApi * deviceapi){
        headphoneapi = deviceapi;
    }
    void playSound(Song * song) override {
        string payload = song->getName() + "by" + song->getArtist();
        headphoneapi->PlaySongViaHeadPhone(payload);
    }
};