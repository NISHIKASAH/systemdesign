
#pragma once 
#include<bits/stdc++.h>
using namespace std;

class Ticket ;
class Show ;

class User {
     int userid;
    string name;
    vector<Ticket*>TicketList;
    public : 
   
    User (int id ,string name  );
     int bookTicket(Show * show , int stno ,int price);
    int CancelTicket(int ti);
    void getTicketList();
    
    
};
