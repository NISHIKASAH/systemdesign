#pragma once
#include<iostream>
#include<vector>
#include "./song.hpp"
using namespace std;


class Playlist {
    string playlistname;
    vector<Song*>playlist;
    public : 
   
    Playlist(string name){
        playlistname = name;
    }
    void addSong(Song * song){
        playlist.push_back(song);
    }
    Song * getSong(string songname){
        bool notfound = true;
        for(int i=0;i<playlist.size() ;i++){
            if(playlist[i]->gettitle() == songname){
                notfound = false;
                return playlist[i];
            }
        }
        if(notfound == true){
            cout<<"Song not avaialable in playlist"<<endl;
        }

        
    }

    int getSize(){
        return playlist.size();
    }
    vector<Song * >getPlayList(){
        return playlist;
    }



};

