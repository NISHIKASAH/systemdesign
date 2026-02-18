#pragma once
#include <iostream>
#include "./device/outputdevice.hpp"
#include "./manager/deviceManager.hpp"
#include "./core/audioEngine.hpp"
#include "./strategies/playlistStrategy.hpp"
#include "./manager/playlistManager.hpp"
#include "./manager/strategyManager.hpp"
using namespace std;

class SpotifyFacade
{
private:
    static SpotifyFacade *spotifyFacadeInstance;
    AudioEngine *audioengine;
    PlayListStrategy *playStrategy;
    PlayList *loadedplaylist;
    SpotifyFacade() {
        loadedplaylist = nullptr ; 
        playStrategy = nullptr ; 
        audioengine = new AudioEngine();
    
    }

public:
    static SpotifyFacade *getSpotifyFacade()
    {
        if (spotifyFacadeInstance == nullptr)
        {
            spotifyFacadeInstance = new SpotifyFacade();
        }
        return spotifyFacadeInstance;
    }
    void connectDevice(DeviceType deviceType)
    {
        DeviceManager ::getDeviceManager()->connect(deviceType);
    }

    void setPlaylistStrategy(StrategyType strategytype)
    {
        playStrategy = StrategyManager ::getStrategyManager()->getStrategy(strategytype);
    }

    void loadPlaylist(string playlistname)
    {
        loadedplaylist = PlayListManager ::getplayListManager()->getPlaylist(playlistname);
        if (!playStrategy) {
            throw runtime_error("Play strategy not set before loading.");
        }
    playStrategy->setPlayList(loadedplaylist);
    }
    void PlaySong(Song *song)
    {
        if (!DeviceManager ::getDeviceManager()->hasAudioDevice())
        {
            throw runtime_error("no device found to play music");
        }
        OutPutDevice *device = DeviceManager ::getDeviceManager()->getAudioDevice();
        audioengine->play(device, song);
    }
    void PauseSong(Song *song)
    {
        
        if (audioengine->getCurrenSongTitle() != song->getName())
        {
            throw runtime_error("current song :" + song->getName() + "is not currently playing");
        }

        audioengine->pause();
    }
    void playAllTrack()
    {
        if (!loadedplaylist)
        {
            throw runtime_error("playlist has not been loaded");
        }
        while (playStrategy->hasnext())
        {
            Song *nextSong = playStrategy->next();
            OutPutDevice *device = DeviceManager ::getDeviceManager()->getAudioDevice();
            audioengine->play(device, nextSong);
        }
        cout << "Completed playlist : " << loadedplaylist->getPlaylistName() << "\n";
    }

    void playNextTrack()
    {
        if (!loadedplaylist)
        {
            throw runtime_error("no playlist loaded");
        }
        if (playStrategy->hasnext())
        {
            Song *nextsong = playStrategy->next();
            OutPutDevice *outputdevice = DeviceManager ::getDeviceManager()->getAudioDevice();
            audioengine->play(outputdevice, nextsong);

        }
    }
    void playPrevious(){
        if(!loadedplaylist){
            throw runtime_error("no playlist loaded");
        }
        if(playStrategy->hasPrevious()){
            Song *prevSong = playStrategy->previous();
            OutPutDevice *outputdevice = DeviceManager ::getDeviceManager()->getAudioDevice();
            audioengine->play(outputdevice, prevSong);
        }
    }
    void enqueNext(Song * song){
        playStrategy->addToNext(song);
    }
};

SpotifyFacade *SpotifyFacade ::spotifyFacadeInstance = nullptr;