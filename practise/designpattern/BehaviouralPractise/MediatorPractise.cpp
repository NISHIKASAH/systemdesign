#include<iostream>
#include<vector>
using namespace std ;

class Collegue ;
class Mediator {
    public : 
    virtual void registerCollegue(Collegue * user) = 0;
    virtual void broadCastMsg(string sender , string msg) = 0;
    virtual void unicastingMsg(string sender , string reciver ,  string msg)  = 0;
};

class Collegue {
    protected :
    Mediator * mediator;
    public : 
    Collegue (Mediator * medi ){
        mediator = medi;
        mediator->registerCollegue(this);
    }
    virtual void sendMessage( string msg) =0 ;
    virtual void sendPrivate(string reciever , string msg) =0;

    virtual void reciveMsg(string sender , string msg) = 0;
    virtual string getName() =0 ;
};

class User : public Collegue {
    string name; 
    public : 
    User(Mediator * m , string nam) : Collegue (m) {
        name = nam;
    }
    void sendMessage( string msg)  override {
        mediator->broadCastMsg(name ,  msg);

    }
   void sendPrivate(string reciever , string msg)  override {
    mediator->unicastingMsg( name , reciever , msg );
   }

    void reciveMsg(string sender , string msg){
        cout<<"Msg send from " << sender<<" to reciever "<<name <<" \n";
        cout<<"Message : "<<msg<<endl;
    }
    string getName() override {
        return name;
    }

};
class ChatRoom : public Mediator {
    vector<Collegue*>userList;
    public : 
    void registerCollegue(Collegue * user) override {
        userList.push_back(user);
    }
    void broadCastMsg(string sender , string msg) override { 
        for(auto user : userList){
           if(user->getName() != sender){
            user->reciveMsg(sender, msg);
           }
        }
    }
   void unicastingMsg( string sender, string reciver ,  string msg)  override {
     for(auto user : userList){
        if(user->getName() == reciver){
            user->reciveMsg(sender , msg);
        }
     }
   }
};  

int main(){
    Mediator * meetingroom = new ChatRoom();
    User * user1 = new User(meetingroom , "nishika");
     User * user2 = new User(meetingroom , "nitesh");
      User * user3 = new User(meetingroom , "nitesha");
      user1->sendMessage( "hello everyone");
      user2->sendPrivate( user1->getName() ,  "hello , i'm  " + user2->getName());


}