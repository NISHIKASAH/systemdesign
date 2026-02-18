#pragma once 
#include<bits/stdc++.h>
using namespace std;

class Song { 
    private : 
    string name ; 
    string artist ; 
    string pathName ; 
    public : 
    Song(string n , string a, string path){
        name = n ; 
        artist = a ; 
        pathName = path ; 

    }
    string getName (){
        return name ; 
    }
    string getArtist (){
        return artist;

    }
    string getPathName(){
        return pathName;
    }

};