#pragma once 
#include<iostream>
#include<vector>
#include "../external/BluetoothApi.hpp"
#include "../device/outputdevice.hpp"
using namespace std;


class BlueToothDevice : public OutPutDevice  {
    private : 
    BlueToothApi * bluetoothapi ;
    public : 
    BlueToothDevice(BlueToothApi * deviceapi){
        bluetoothapi = deviceapi;
    }
    void playSound(Song * song) override {
        string payload = song->getName() + "by" + song->getArtist();
        bluetoothapi->PlaySongViaBluetooth(payload);
    }
};