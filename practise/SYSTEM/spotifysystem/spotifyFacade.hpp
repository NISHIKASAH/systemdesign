#pragma once
#include <iostream>
#include "./core/audioEngine.hpp"
#include "./manager/deviceManager.hpp"
#include "./manager/playlistManager.hpp"
#include "./manager/strategyManager.hpp"
using namespace std;


class SpotifyFacade {
  static SpotifyFacade * spotifyfacadeinstance; 

  AudioEngine * audioengine ;
   DeviceManager * devicemanager ;
    StrategyManager * stratergymanager ;
     PlayListStrategy * playListstratergy;

    SpotifyFacade(){
        audioengine = new AudioEngine();
        devicemanager = nullptr;
         stratergymanager = nullptr;
           playListstratergy = nullptr;

    }
     public : 

     static SpotifyFacade * getSpotifyFacade(){
        if(spotifyfacadeinstance == nullptr){
            spotifyfacadeinstance = new SpotifyFacade();
        }

        return spotifyfacadeinstance;
     }

     void connect(DeviceType type){
        devicemanager = DeviceManager ::getDeviceManager();
        devicemanager->connect(type);

     }

     void setStratergy( StrategyType type){
        stratergymanager  = StrategyManager ::getStrategyManager();
       playListstratergy =  stratergymanager->getStrategy(type);

     }
     void LoadPlayList(string playlistname){

        PlayListManager * playlistmanager = PlayListManager ::getplayListManager();
       PlayList * loadedplaylist =  playlistmanager->getPlaylist(playlistname);
       playListstratergy->setPlayList(loadedplaylist);


     }

     void Play(Song * song){
       if(! devicemanager->hasAudioDevice()){
        cout<<"No audio device found"<<endl;
       }
       OutPutDevice *device = devicemanager->getAudioDevice();
       audioengine->play(device , song);

     }

     void Pause(){

         if(! devicemanager->hasAudioDevice()){
        cout<<"No audio device found"<<endl;
       }
       OutPutDevice *device = devicemanager->getAudioDevice();
       audioengine->pause();

     }

     void PlayAllTrack(){
        OutPutDevice *device = devicemanager->getAudioDevice();
       while( playListstratergy->hasnext()){
        Song * nextsong =  playListstratergy->next();
        audioengine->play(device , nextsong );
       }
     }
     void PlayNextSong(){
          OutPutDevice *device = devicemanager->getAudioDevice();
       if( playListstratergy->hasnext()){
        Song * nextsong =  playListstratergy->next();
        audioengine->play(device , nextsong );
       }
     }
     void PlayPreviosSong(){
         OutPutDevice *device = devicemanager->getAudioDevice();
       if( playListstratergy->hasPrevious()){
        Song * nextsong =  playListstratergy->next();
        audioengine->play(device , nextsong );
       }
     }

};

 SpotifyFacade *  SpotifyFacade ::spotifyfacadeinstance = nullptr;