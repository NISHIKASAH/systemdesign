#include<bits/stdc++.h>
using namespace std;

/*
it create a intermediate , through which  interaction , 
across all users are carried out .
*/
class User ; 
class Mediator {
    public :
    virtual void sendMessage(User * sender , string msg ) = 0;
    virtual void addUser(User * user ) = 0;
};
class User {
    protected : 
    Mediator * mediator ; 
    string name ; 
    public : 
    User(Mediator * mediator ,string username){
        this->mediator = mediator;
        this->name = username; 
    }
    virtual  void send(string msg) = 0;
    virtual void receive(string msg ) =0 ;
    void getName(){
        cout<<"Username : "<<name<<endl;
    }
};

class ConcreteUser  : public User {
    public : 
    ConcreteUser(Mediator * mediator , string username ) : User (mediator , username ) {};
   void send(string msg) override {
    cout<<"User : "<<this->name<<" sending msg : "<< msg <<endl;
    mediator->sendMessage(this, msg);

   }
   void receive(string msg) override { 
    cout<<"User :"<<this->name << " receive msg : "<<msg<<endl;
   }

};
class ChatRoom : public Mediator {
    vector<User*>Users;
    public : 
    void addUser(User * user ) override {
        Users.push_back(user);

    }
    void sendMessage(User * sender , string msg ) override {
        for(auto user : Users){
            if(user != sender){
                user->receive(msg);
            }
        }

    }
};
int main(){
   Mediator* chatroom = new ChatRoom();
   User * user1 = new ConcreteUser(chatroom , "diksha");
      User * user2 = new ConcreteUser(chatroom , "parth");
         User * user3 = new ConcreteUser(chatroom , "smrith");

        chatroom->addUser(user1);
        chatroom->addUser(user2);
        chatroom->addUser(user3);
        
        chatroom->sendMessage(user2 , "lets meet at 4pm today! ");
        cout<<endl<<"-----------------"<<endl;
        user1->send("hello guys , shall we study together? ");
}