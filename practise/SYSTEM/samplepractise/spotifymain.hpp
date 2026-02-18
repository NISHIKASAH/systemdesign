#pragma once
#include<iostream>
#include<vector>
#include "./model/song.hpp"
#include "./manager/playlistmanager.hpp"
#include "./facade.hpp"
using namespace std;

class Spotifymain {

    static Spotifymain * instance;
    vector<Song*>LibrarySong; 

    Spotifymain(){};

    public : 
static Spotifymain * getSpotifyinstance(){
    if(instance == nullptr){
        instance = new Spotifymain();
    }
    return instance;
}
    void addSongtoLibrary(Song *song ){
        LibrarySong.push_back(song);

    }
void createPlayList(string name){
   PlayListManager ::getInstance()->createPlaylist(name);
}
void addsongtoplaylist( string playlistname , Song * song){
    PlayListManager ::getInstance()->addSongToPlayList( playlistname , song );
}

void connectdevice(deviceType type ){
    FacadeSpotify ::getfacadeinstance()->connectdevice(type );
}
void setPlayliststrategy( stratergyType type ){
     FacadeSpotify ::getfacadeinstance()->setPlaylistStrategy(type);

}
void loadPlaylist(string name ){
     FacadeSpotify ::getfacadeinstance()->loadPlaylist(name);

}
void playsong(Song *song ){
    FacadeSpotify ::getfacadeinstance()->playPlaylist(song);

}
void playnext(){
    FacadeSpotify ::getfacadeinstance()->playnext();
}
void playprevious( ){
    FacadeSpotify ::getfacadeinstance()->playprevious();
}
void playAllTrack(){
    FacadeSpotify ::getfacadeinstance()->playAllTrack();
}


    

};

Spotifymain * Spotifymain :: instance = nullptr;