
#include "Show.h" 
#include "Seat.h"

    Show :: Show(int id , Movie * movie , string time){
        this->showId = id;
        this->timing = time;
        this->movieDetails = movie;
    }
    int  Show :: getShowId(){
        return this->showId;
    }
    void Show :: addSeat(Seat * seat){
        cout<<endl;
        cout<<"----add seat to show ----"<<endl;
       SeatList.push_back(seat);
    }
    void Show ::  displaySeatList(){
        cout<<endl;
        cout<<"----Display list of seats-----"<<endl;
        for(int i=0;i<SeatList.size();i++){
            cout<<SeatList[i]->getSeatnum()<<endl;
        }
        cout<<endl;
    }
     int  Show :: showSeatStatus( int stno){
        for(int i=0;i<SeatList.size();i++){
            if(SeatList[i]->getSeatnum() == stno && SeatList[i]->seatStatus() == true){
                cout<<" Seat "  <<stno <<"is available !"<<endl;
                SeatList[i]->setSeatStatus(false);
                return 1;
            }
        }
        cout<<" Seat "  <<stno <<" is already booked!"<<endl;
        return 0;

    }
    
