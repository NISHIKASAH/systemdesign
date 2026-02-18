#pragma once 
#include<iostream>
#include<vector>
using namespace std;


class BlueToothApi {
    public : 
    void PlaySongViaBluetooth(string data){
        cout<<"playing song :"<<data<<endl;
    }
};