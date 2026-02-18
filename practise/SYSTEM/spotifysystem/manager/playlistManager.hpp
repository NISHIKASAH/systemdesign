#pragma once
#include <iostream>
#include <map>
#include <string>
#include "../model/playlist.hpp"
#include <stdexcept>
using namespace std;

class PlayListManager
{
private:
    static PlayListManager* playlistManagerInstance;
    map<string, PlayList*> MP_playlist;
    PlayListManager() {}

public:
    static PlayListManager* getplayListManager()
    {
        if (playlistManagerInstance == nullptr)
        {
            playlistManagerInstance = new PlayListManager();
        }
        return playlistManagerInstance;
    }

    void addSongToPlaylist(string playlistname, Song* song)
    {
        if (!song) throw runtime_error("Cannot add null song to playlist.");
        if (!MP_playlist.count(playlistname))
            throw runtime_error("No playlist found with name: " + playlistname);

        MP_playlist[playlistname]->addSongToList(song);
    }

    void createPlayList(string playlistname)
    {
        if (MP_playlist.count(playlistname))
            throw runtime_error("Playlist already exists: " + playlistname);

        MP_playlist[playlistname] = new PlayList(playlistname);
    }

    PlayList* getPlaylist(string playlistname)
    {
        if (MP_playlist.count(playlistname))
            return MP_playlist[playlistname];

        throw runtime_error("Playlist not found: " + playlistname);
    }
};

PlayListManager* PlayListManager::playlistManagerInstance = nullptr;
