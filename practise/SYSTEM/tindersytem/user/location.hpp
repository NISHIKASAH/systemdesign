#pragma once
#include<iostream>
using namespace std;

class Location {
    int xaxis;int yaxis;
    public : 
    Location(){
        
    }
    Location(int x,int y){
        xaxis = x;
        yaxis=y;
    }

    int getxaxis(){
        return xaxis;
    }
    int getyaxis(){
        return yaxis;
    }
    void setxaxis(int x){
        xaxis=x;
    }
    void setyaxis(int y){
        yaxis = y;
    }
   int getDistanceinKm(int targetx, int targety){
           int dis = (targetx - xaxis) *(targetx - xaxis)  - (targety - yaxis ) *(targety- yaxis);
           return dis;
    }
};