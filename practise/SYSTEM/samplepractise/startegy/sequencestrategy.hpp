#pragma once
#include <iostream>
#include "./playliststrategy.hpp"
#include <stack>
using namespace std;

class SequenceStrategy : public PlayListStrategy
{
    Playlist *playlist;
    int curridx ;
    vector<Song*>remaining;

public:
  

    void setPlayList(Playlist *p)
    {
        playlist = p;
        curridx = -1;
        remaining= playlist->getPlayList();
    }
    bool hasNext() override
    {
        return (curridx + 1)<= remaining.size();
    }
    Song *next() override
    {
      Song * song =  remaining[ curridx + 1 ];
      curridx++;
      return song;


    }
    bool hasPrevious() override
    {
        return (curridx -1) >=0;
    }
    Song *previous() override
    {
        Song *song = remaining[curridx-1];
        curridx--;
        
        return song;
    }
};