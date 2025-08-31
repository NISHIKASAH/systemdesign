
#include "Seat.h"

Seat :: Seat(int id , int status){
        this->seatId = id;
        this->isAvailable = status;
}

int Seat ::  getSeatnum(){
        return this->seatId;
     }

bool Seat ::  seatStatus(){
        return this->isAvailable;
     }
 
 void Seat ::  setSeatStatus(bool status){
        this->isAvailable = status;
     }