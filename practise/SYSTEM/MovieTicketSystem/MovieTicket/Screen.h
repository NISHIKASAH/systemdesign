
#pragma once 
#include <bits/stdc++.h>
using namespace std; 

class Show ;

class Screen {
     int screenId ; 
    vector<Show*>showList;
    public :
     
    Screen(int id );
    int getScreenId();
    void addShow(Show * show);
      void displayShowList();

};