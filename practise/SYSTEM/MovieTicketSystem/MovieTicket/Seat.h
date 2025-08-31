
#pragma once 
#include<bits/stdc++.h>
using namespace std;

class Seat {
 
     int seatId;
     bool isAvailable;
     public : 
       
     Seat(int id , int status);
     int getSeatnum();
     bool seatStatus();
     void setSeatStatus(bool status);
};