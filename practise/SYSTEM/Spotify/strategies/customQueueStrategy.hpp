#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include "../model/playlist.hpp"
#include "../strategies/playlistStrategy.hpp"

class CustomQueueStrategy : public PlayListStrategy {
    std::queue<Song*> queuePlaylist;
    PlayList* currentPlaylist;
    std::stack<Song*> history;
    int currentIdx;

    Song* nextSequence() {
        if (!hasnext())
            throw std::runtime_error("No next song available.");
        currentIdx++;
        return currentPlaylist->getSongs()[currentIdx];
    }

    Song* previousSequence() {
        if (!hasPrevious())
            throw std::runtime_error("No previous song available.");
        currentIdx--;
        return currentPlaylist->getSongs()[currentIdx];
    }

public:
    CustomQueueStrategy() : currentPlaylist(nullptr), currentIdx(-1) {}

    void setPlayList(PlayList* playlist) override {
        if (!playlist) throw std::runtime_error("Invalid playlist provided.");
        currentPlaylist = playlist;
        currentIdx = -1;
        while (!queuePlaylist.empty()) queuePlaylist.pop();
        while (!history.empty()) history.pop();
    }

    Song* next() override {
        if (!currentPlaylist || currentPlaylist->getSize() == 0)
            throw std::runtime_error("No playlist loaded or empty.");

        if (!queuePlaylist.empty()) {
            Song* selectedSong = queuePlaylist.front();
            queuePlaylist.pop();
            history.push(selectedSong);

            // Update index to match playlist
            auto songsList = currentPlaylist->getSongs();
            for (int i = 0; i < songsList.size(); i++) {
                if (songsList[i] == selectedSong) {
                    currentIdx = i;
                    break;
                }
            }
            return selectedSong;
        }
        return nextSequence();
    }

    Song* previous() override {
        if (!currentPlaylist || currentPlaylist->getSize() == 0)
            throw std::runtime_error("No playlist loaded or empty.");

        if (!history.empty()) {
            Song* selectedSong = history.top();
            history.pop();
            return selectedSong;
        }
        return previousSequence();
    }

    bool hasnext() override {
        return currentPlaylist && (currentIdx + 1) < currentPlaylist->getSize();
    }

    bool hasPrevious() override {
        return currentPlaylist && (currentIdx - 1) >= 0;
    }

    void addToNext(Song* song) override {
        if (!song) throw std::runtime_error("Cannot enqueue null song.");
        queuePlaylist.push(song);
    }
};
