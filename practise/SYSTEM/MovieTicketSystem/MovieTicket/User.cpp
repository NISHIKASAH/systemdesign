#include "User.h"
#include "Ticket.h"
#include "Show.h"

    User :: User (int id ,string name  ){
        this->name = name;
        this->userid = id;
    }
     int  User :: bookTicket(Show * show , int stno ,int price){

        int value = show->showSeatStatus(stno);

        if(value == 1 ){
            cout<<"---Ticket booked----"<<endl;
            int tid = rand()%1000 +1 ;
            Ticket * t1 = new Ticket( tid,this->userid ,show->getShowId() , price );
            t1->generateTicket();
            TicketList.push_back(t1);
           return tid;
        } 
        else{
            cout<<"----No seat Available---"<<endl;
            return 0;
        }
    }
    int  User ::  CancelTicket(int ti){
        int flag = false;
        for(int i=0;i<TicketList.size() ; i++){
            if(TicketList[i]->getTicketId() == ti){
                cout<<"---Your ticket is Cancelled ---"<<endl;
                flag  = true;
                TicketList.erase(TicketList.begin()+i);
            }
        }
        if(flag == true){
            cout<<"ticket found"<<endl;
        }
        else{
            cout<<"no ticket found"<<endl;
        }
    }
    void  User :: getTicketList(){
        cout<<"---List of Ticket---"<<endl;
        for(int i=0;i<TicketList.size() ; i++){
          TicketList[i]->generateTicket();
           cout<<endl;
        }
    }
    
