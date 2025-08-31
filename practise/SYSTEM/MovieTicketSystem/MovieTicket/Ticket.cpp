
  
#include "Ticket.h"

    Ticket :: Ticket(int id ,int userid ,int showid , int price){
        this->ticketId = id;
        this->showId= showid;
        this->userId = userid;
        this->price = price;
    }
    void Ticket :: generateTicket(){
        cout<<"Showid : " <<this->showId;
        cout<<"   TicketId : "<<this->ticketId;
        cout<<"   price : "<<this->price;
        cout<<"   User :"<<this->userId ; 
        cout<<endl;
    }
    int Ticket :: getTicketId(){
        return this->ticketId;
    }
   