#pragma once
#include<iostream>
#include "../model/playlist.hpp"
#include<map>
using namespace std;

class PlayListManager {
  
    map<string, Playlist* >playlist;
   static PlayListManager * instance;

    PlayListManager(){};
     public :

      void createPlaylist(string name ){
        playlist[name] = new Playlist();
    }
   static  PlayListManager* getInstance(){
        if( instance == nullptr){
            instance = new PlayListManager();
        }
        return instance;
     }

    void  addSongToPlayList( string playlistname , Song * song ){

       if( !playlist.count(playlistname)) {
          cout<<"playlist not found "<<endl;
       }

        playlist[playlistname]->addSong( song);


     }
    Playlist * getPlayList(string playlistname ){

        if( !playlist.count(playlistname)) {
          cout<<"playlist not found "<<endl;
       } 
        if(playlist.count(playlistname)){
            return playlist[playlistname];
        }

    }

    


     
     

      
};

PlayListManager * PlayListManager :: instance   = nullptr;