#pragma once
#include<iostream>
using namespace std;

class Song {
    string title;
    string artist;

    public : 
    Song(string t, string a){
        title = t;
        artist = a;

    }
    string gettitle(){
        return title;
    }
    string getartist(){
        return artist;
    }


};