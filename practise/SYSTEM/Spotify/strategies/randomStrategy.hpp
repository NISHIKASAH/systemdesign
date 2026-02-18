#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include "../strategies/playlistStrategy.hpp"
#include "../model/playlist.hpp"

class RandomStrategy : public PlayListStrategy {
    PlayList* currentPlayList;
    std::vector<Song*> remainingSongs;
    std::stack<Song*> history;

public:
    RandomStrategy() : currentPlayList(nullptr) {}

    void setPlayList(PlayList* playlist) override {
        if (!playlist) throw std::runtime_error("Invalid playlist provided.");
        currentPlayList = playlist;
        remainingSongs = playlist->getSongs();
        history = std::stack<Song*>();
    }

    Song* next() override {
        if (!currentPlayList || currentPlayList->getSize() == 0)
            throw std::runtime_error("No playlist or empty playlist.");
        if (remainingSongs.empty())
            throw std::runtime_error("No songs left to play.");

        int index = rand() % remainingSongs.size();

        std::swap(remainingSongs[index], remainingSongs.back());
        Song* selectedsong = remainingSongs.back();
        remainingSongs.pop_back();

        history.push(selectedsong);
        return selectedsong;
    }

    Song* previous() override {
        if (history.empty())
            throw std::runtime_error("No previous song to play.");

        Song* selectedSong = history.top();
        history.pop();
        return selectedSong;
    }

    bool hasnext() override {
        return currentPlayList && !remainingSongs.empty();
    }

    bool hasPrevious() override {
        return !history.empty();
    }

    void addToNext(Song* song) override {
        if (!song) throw std::runtime_error("Cannot add null song.");
        remainingSongs.push_back(song);
    }
};
