#include<bits/stdc++.h>
using namespace std;

class Seat {
 
     int seatId;
     bool isAvailable;
     public : 
       
     Seat(int id , int status){
        this->seatId = id;
        this->isAvailable = status;
     }
     int getSeatnum(){
        return this->seatId;
     }
     bool seatStatus(){
        return this->isAvailable;
     }
     void setSeatStatus(bool status){
        this->isAvailable = status;
     }
};
class Movie {
    int movieId;
    string movieDescription ;
   public:
    Movie(int id , string description){
        this->movieId = id;
        this->movieDescription = description;
    }
};
class Show {
    int showId ; 
    Movie * movieDetails ; 
    string timing ;
    vector<Seat*>SeatList;
    public : 
    Show(int id , Movie * movie , string time){
        this->showId = id;
        this->timing = time;
        this->movieDetails = movie;
    }
    int getShowId(){
        return this->showId;
    }
    void addSeat(Seat * seat){
        cout<<endl;
        cout<<"----add seat to show ----"<<endl;
       SeatList.push_back(seat);
    }
    void displaySeatList(){
        cout<<endl;
        cout<<"----Display list of seats-----"<<endl;
        for(int i=0;i<SeatList.size();i++){
            cout<<SeatList[i]->getSeatnum()<<endl;
        }
        cout<<endl;
    }
     int showSeatStatus( int stno){
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
    

};

class Screen {
     int screenId ; 
    vector<Show*>showList;
    public :
     
    Screen(int id ){
        this->screenId = id;
    }
    int getScreenId(){
        return this->screenId;
    }
    void addShow(Show * show){
        cout<<endl;
        cout<<"----show add to screens ------"<<endl;
        showList.push_back(show);
    }
      void displayShowList(){
        cout<<endl;
        cout<<"----Display list of seats-----"<<endl;
        for(int i=0;i<showList.size();i++){
            cout<<showList[i]<<endl;
        }
        cout<<endl;
    }

};
class Threater {
    int ThreaterId ;
    string location;
 
    vector<Screen*>ScreenList;
    public: 
       string name;
    Threater(int id , string loc,string name){
        this->ThreaterId = id;
        this->location = loc;
        this->name = name;
    }
    void addScreen(  Screen * screen){

        ScreenList.push_back(screen);
        cout<<"---Screen Added---"<<endl;
    }
    void displayScreenList(){
        cout<<"-----Screen List--------"<<endl;
        for(int i=0;i<ScreenList.size();i++){
            cout<<i+1<<"  " <<ScreenList[i]->getScreenId()<<endl;
        }
        cout<<endl;
    }



};
class Ticket{
    int ticketId;
   int userId;
   int showId;
   int price ;

    public : 
  
    Ticket(int id ,int userid ,int showid , int price){
        this->ticketId = id;
        this->showId= showid;
        this->userId = userid;
        this->price = price;
    }
    void generateTicket(){
        cout<<"Showid : " <<this->showId;
        cout<<"   TicketId : "<<this->ticketId;
        cout<<"   price : "<<this->price;
        cout<<"   User :"<<this->userId ; 
        cout<<endl;
    }
    int getTicketId(){
        return this->ticketId;
    }
   
};

class User {
     int userid;
    string name;
    vector<Ticket*>TicketList;
    public : 
   
    User (int id ,string name  ){
        this->name = name;
        this->userid = id;
    }
     int bookTicket(Show * show , int stno ,int price){

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
    int CancelTicket(int ti){
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
    void getTicketList(){
        cout<<"---List of Ticket---"<<endl;
        for(int i=0;i<TicketList.size() ; i++){
          TicketList[i]->generateTicket();
           cout<<endl;
        }
    }
    
    
};


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