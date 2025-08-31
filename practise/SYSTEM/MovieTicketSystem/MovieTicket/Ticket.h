#pragma once 
#include<bits/stdc++.h>
using namespace std; 


class Ticket{
    int ticketId;
   int userId;
   int showId;
   int price ;

    public : 
  
    Ticket(int id ,int userid ,int showid , int price);
    void generateTicket();
    int getTicketId();
   
};

