#pragma once
#include <iostream>
#include "../strategies/playlistStrategy.hpp"
#include "../model/playlist.hpp"

class SequenceStrategy : public PlayListStrategy {
    PlayList* currentPlaylist;
    int currIndex;

public:
    SequenceStrategy() : currentPlaylist(nullptr), currIndex(-1) {}

    void setPlayList(PlayList* playlist) override {
        if (!playlist) throw std::runtime_error("Invalid playlist provided.");
        currentPlaylist = playlist;
        currIndex = -1;
    }

    Song* next() override {
        if (!currentPlaylist || currentPlaylist->getSize() == 0)
            throw std::runtime_error("Playlist not loaded or empty.");
        if (!hasnext())
            throw std::runtime_error("No next song available.");

        currIndex++;
        return currentPlaylist->getSongs()[currIndex];
    }

    Song* previous() override {
        if (!currentPlaylist || currentPlaylist->getSize() == 0)
            throw std::runtime_error("Playlist not loaded or empty.");
        if (!hasPrevious())
            throw std::runtime_error("No previous song available.");

        currIndex--;
        return currentPlaylist->getSongs()[currIndex];
    }

    bool hasnext() override {
        return currentPlaylist && (currIndex + 1) < currentPlaylist->getSize();
    }

    bool hasPrevious() override {
        return currentPlaylist && (currIndex - 1) >= 0;
    }

    void addToNext(Song* song) override {
        throw std::runtime_error("SequenceStrategy does not support queueing songs.");
    }
};
