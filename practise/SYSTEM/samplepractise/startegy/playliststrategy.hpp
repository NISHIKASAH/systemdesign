#pragma once 
#include<iostream>
#include "../model/playlist.hpp"
using namespace std;

class PlayListStrategy {
    public : 
   virtual void setPlayList(Playlist  *p) =0;
   virtual bool hasNext() = 0;
   virtual Song* next() = 0;
   virtual  bool hasPrevious () = 0;
   virtual  Song * previous() = 0;




};