#pragma once
#include<bits/stdc++.h>
using namespace std;

class Screen;
class Threater {
    int ThreaterId ;
    string location;
 
    vector<Screen*>ScreenList;
    public: 
       string name;
    Threater(int id , string loc,string name);
    void addScreen(  Screen * screen);
    void displayScreenList();



};