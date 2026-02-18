#pragma once
#include <iostream>
#include "../model/song.hpp"
#include "../device/outputdevice.hpp"
#include "../model/song.hpp"

class AudioEngine { 
    private : 
    Song* currentSong  ; 
    bool ispaused; 
    public : 
    AudioEngine(){
        currentSong  = nullptr ; 
        ispaused = false;

    }
    bool songPaused() {
        return ispaused;
    }
    string getCurrenSongTitle(){
        if(currentSong == nullptr){
            return "";
        }
        else return currentSong->getName();
    }
    void play(OutPutDevice *audiodevice , Song * song ) {
        if(song == nullptr) {
            throw runtime_error("no song to play .");
        }
        if(ispaused &&  currentSong == song){
            ispaused = false;
            audiodevice->playSound(song);
            cout<<"Resume song :" << song->getName() <<"\n";
            return;
        }
        ispaused = false;
        currentSong = song ; 
         cout<<"Playing song :"<<song->getName() << "\n";
        audiodevice->playSound(currentSong);
       

    }
    void pause(){
       if(currentSong == nullptr){
        throw runtime_error("no song is currently playing to pause");
       }
       ispaused = true;
       cout<<" Paused currentsong  : " <<currentSong->getName() <<"\n";
    }


};