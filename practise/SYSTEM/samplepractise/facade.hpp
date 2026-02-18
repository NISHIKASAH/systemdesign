#pragma once
#include<iostream>
#include<vector>
#include "./factory/audioengine.hpp"
#include "./startegy/sequencestrategy.hpp"
#include "./startegy/randomstrategy.hpp"
#include "./model/playlist.hpp"
#include "./manager/devicemanager.hpp"
#include "./manager/playlistmanager.hpp"
#include "./manager/strategymanager.hpp"


using namespace std;

class FacadeSpotify {
    static FacadeSpotify * instance;
    AudioEngine * audioengine;
    PlayListStrategy* playlistst;
    Playlist* loadingplaylist;


     

    FacadeSpotify(){

        audioengine = new AudioEngine();
        playlistst= nullptr;
        loadingplaylist= nullptr;



    };

    public : 
    static FacadeSpotify * getfacadeinstance(){
        if(instance == nullptr){
            instance = new FacadeSpotify();
        }
        return instance;
    }

    void connectdevice(deviceType type){
        DeviceManager ::getdeviceinstance()->connect(type);
    }
    void setPlaylistStrategy(stratergyType type){
      playlistst=   StrategyManager ::getstrategymanagerinstance()->getStrategy(type);

    }
    void loadPlaylist(string playlistname ){
        
      Playlist * askedPlaylist=   PlayListManager ::getInstance()->getPlayList(playlistname);
      playlistst->setPlayList(askedPlaylist);


    }
    void playPlaylist(Song * song ){

        Outputdevice * device = DeviceManager ::getdeviceinstance()->getoutputdevice();
        audioengine->playSong(song, device);
    }
    void playnext(){
       if( playlistst->hasNext()){
        playlistst->next();
       }
        
    }
     void playprevious(){
       if( playlistst->hasPrevious()){
        playlistst->previous();
       }
        
    }
    void playAllTrack(){
       while( playlistst->hasNext()){
        playlistst->next();
       }
    }




};

FacadeSpotify * FacadeSpotify :: instance = nullptr;

