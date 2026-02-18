#pragma once
#include <iostream>
#include "../model/playlist.hpp"

class PlayListStrategy {
public:
    virtual ~PlayListStrategy() = default;

    virtual void setPlayList(PlayList* playlist) = 0;
    virtual Song* next() = 0;
    virtual Song* previous() = 0;
    virtual bool hasnext() = 0;
    virtual bool hasPrevious() = 0;
    virtual void addToNext(Song* song) = 0;  // force implementation
};
