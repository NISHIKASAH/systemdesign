#pragma once 
#include<bits/stdc++.h>
using namespace std;

class Movie;
class Seat; 
class Show {
    int showId ; 
    Movie * movieDetails ; 
    string timing ;
    vector<Seat*>SeatList;
    public : 
    Show(int id , Movie * movie , string time);
    int getShowId();
    void addSeat(Seat * seat);
    void displaySeatList();
     int showSeatStatus( int stno);
    

};