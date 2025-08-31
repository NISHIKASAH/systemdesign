
#include<bits/stdc++.h>
#include "Threater.h"
#include "Screen.h" 
#include "Movie.h"
#include "Seat.h"
#include "Show.h"
#include "Ticket.h"
#include "User.h"
using namespace std;


int main(){
    cout<<"-------Movies system-------"<<endl;
    Threater* th1 = new Threater(1 , "chennai" , "pvr");

    Screen * sc1 = new Screen(121);
    Screen * sc2 = new Screen(122);
    th1->addScreen(sc1);
    th1->addScreen(sc2);
    th1->displayScreenList();

    Movie * m1 = new Movie(111 , "sci-fi movie");
    Movie * m2 = new Movie(112 , "drama movie");
    Movie * m3 = new Movie(113 , "real life based movie");

    Show *sh1 = new Show(200 ,m1 , "12:30");
    Show *sh2 = new Show(201 ,m2 , "5:30");
    Show *sh3 = new Show(202 ,m3 , "8:30");


    Seat * st1 = new Seat(1 , true);
    Seat * st2 = new Seat(2 , true);

        sh1->addSeat(st1);
        sh1->addSeat(st2);
        sh1->displaySeatList(); 

    User * u1 = new User(1110 , "nishika" );
    User * u2 = new User(1111 , "nitu");

  
    int ticketid1 = u1->bookTicket(sh1, 1, 250);
      int ticketid2 = u2->bookTicket(sh1, 2 ,300);

    //   int ticketid3 = u1->bookTicket(sh2 , 1 , 300);
      u1->CancelTicket(ticketid1);
      
      


    
    
    
    
}