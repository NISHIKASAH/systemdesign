#pragma once 
#include<iostream>
#include <vector>
#include "../model/song.hpp"
using namespace std;

class PlayList {
    private : 
    string playlistName ;
    vector<Song*>playList;
    public : 
      PlayList(string name) {
        playlistName = name;
    }
    string getPlaylistName() {
        return playlistName;
    }
    const vector<Song*> getSongs() {
        return playList;
    }
    int getSize() {
        return (int)playList.size();
    }
    void addSongToList(Song* song) {
        if (song == nullptr) {
            throw runtime_error("Cannot add null song to playlist.");
        }
        playList.push_back(song);
    }
  
};