#pragma once
#include <iostream>
#include "./playliststrategy.hpp"
#include <stack>
using namespace std;

class RandomStrategy : public PlayListStrategy
{
    Playlist *playlist;
    stack<Song *> history;
    vector<Song *> remaining;

public:

    void setPlayList(Playlist *p)
    {
        playlist = p;
        remaining = playlist->getPlayList();
        history = stack<Song*>();
    }
    bool hasNext() override
    {
        return remaining.size() != 0;
    }
    Song *next() override
    {
        int idx = rand() % remaining.size();
        Song *song = remaining[idx];
        swap(remaining[idx], remaining.back());
        return song;
    }
    bool hasPrevious() override
    {
        return history.empty() != 0;
    }
    Song *previous() override
    {
        Song *song = history.top();
        history.pop();
        return song;
    }
};