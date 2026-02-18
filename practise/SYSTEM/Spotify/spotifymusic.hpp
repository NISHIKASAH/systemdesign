#pragma once
#include <iostream>
#include <vector>
#include "./manager/playlistManager.hpp"
#include "./spotifyFacade.hpp"
using namespace std;

class SpotifyApp
{
    vector<Song *> LibrarySong;
    SpotifyApp() {};
    static SpotifyApp *spotifyinstance;

public:
    static SpotifyApp *getSpotifyAppInstance()
    {
        if (spotifyinstance == nullptr)
        {
            spotifyinstance = new SpotifyApp();
        }
        return spotifyinstance;
    }

    void createSongToLibrary(string name, string artist, string path)
    {
        Song *newsong = new Song(name, artist, path);
        LibrarySong.push_back(newsong);
    }
    void createNewPlayList(string playlistname)
    {
        PlayListManager *playlistmanager = PlayListManager ::getplayListManager();
        playlistmanager->createPlayList(playlistname);
    }
   Song * findSongByName(string songname)
    {
    
        for (Song *song : LibrarySong)
        {
            if (song->getName() == songname)
            {
                return song;
            }
        }
        return nullptr;
    } 
    void AddSongToPlaylist(string playlistname, string songname)
    {

       Song * song =  findSongByName(songname);
        PlayListManager *playlistmanager = PlayListManager ::getplayListManager();

        playlistmanager->addSongToPlaylist(playlistname, song);
    }

    void connectToDevice(DeviceType devicetype)
    {
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->connectDevice(devicetype);
    }

    
    void setPlayListStrategy(StrategyType strategtype)
    {
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->setPlaylistStrategy(strategtype);
    }

    void loadingPlaylist(string playlistname)
    {
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->loadPlaylist(playlistname);
    }
    void findAllPlayTrack()
    {
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->playAllTrack();
    }
    void playSingSong(string songname)
    {
          Song * song =  findSongByName(songname);
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->PlaySong(song);
    }

    void pauseCurrentSong(string songname)
    {
         Song * song =  findSongByName(songname);
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->PauseSong(song);
    }

    void playNextTrack()
    {
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->playNextTrack();
    }

    void playPreviousTrack(){
         SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->playPrevious();
    }
    void addnextSongToQueue(string songname){
         Song * song =  findSongByName(songname);
        SpotifyFacade *spotifyfacade = SpotifyFacade ::getSpotifyFacade();
        spotifyfacade->enqueNext(song);

    }
};

SpotifyApp *SpotifyApp ::spotifyinstance = nullptr;
