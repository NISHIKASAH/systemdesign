
#include "Threater.h"
#include "Screen.h"


    Threater :: Threater(int id , string loc,string name){
        this->ThreaterId = id;
        this->location = loc;
        this->name = name;
    }
    void Threater :: addScreen(  Screen * screen){

        ScreenList.push_back(screen);
        cout<<"---Screen Added---"<<endl;
    }
    void Threater ::  displayScreenList(){
        cout<<"-----Screen List--------"<<endl;
        for(int i=0;i<ScreenList.size();i++){
            cout<<i+1<<"  " <<ScreenList[i]->getScreenId()<<endl;
        }
        cout<<endl;
    }