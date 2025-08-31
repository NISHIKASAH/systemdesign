
#include "Screen.h"
#include "Show.h"


    Screen :: Screen(int id ){
        this->screenId = id;
    }
    int Screen :: getScreenId(){
        return this->screenId;
    }
    void Screen ::  addShow(Show * show){
        cout<<endl;
        cout<<"----show add to screens ------"<<endl;
        showList.push_back(show);
    }
      void Screen::  displayShowList(){
        cout<<endl;
        cout<<"----Display list of seats-----"<<endl;
        for(int i=0;i<showList.size();i++){
            cout<<showList[i]<<endl;
        }
        cout<<endl;
    }