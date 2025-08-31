#include<bits/stdc++.h>
using namespace std;

class User ;
class chatRoom {
    public : 
    virtual void addUser(User * user) = 0;
    virtual void sendMessage (User * sender , string msg ) =0 ;
};

class User {
    protected:
    chatRoom * ChatRoom ; 
    string name; 
    public : 
    User(chatRoom *chatroom , string username) {
        this->ChatRoom = chatroom;
        this->name = username;
    }
    virtual void send(string sentmsg ) =0;
    virtual  void recieve (string getmsg) = 0;


}; 
class ChatRoomConcrete : public chatRoom {
    vector<User*>Users;
    public : 
    void addUser (User * user) override { 
        Users.push_back(user);
    }

    void sendMessage (User * sender , string msg ) override { 
        for(auto user : Users){
            if(user != sender){
                user->recieve(msg);
            }
        }
    }
};

class ConcreateUser : public User {
    public: 
    ConcreateUser(chatRoom *chatroom , string username) : User(chatroom , username) {};

    void send(string sentmsg) override {
        cout<<this->name<<" sends msg :  "<<sentmsg<<endl;
        this->ChatRoom->sendMessage(this, sentmsg);
    }
    void recieve(string getmsg) override {
        cout<<this->name <<" recieve msg : " <<getmsg<<endl;
    }


};
int main(){
     chatRoom* chatroom = new ChatRoomConcrete();
   User * user1 = new ConcreateUser(chatroom , "diksha");
      User * user2 = new ConcreateUser(chatroom , "parth");
         User * user3 = new ConcreateUser(chatroom , "smrith");

        chatroom->addUser(user1);
        chatroom->addUser(user2);
        chatroom->addUser(user3);
        
        chatroom->sendMessage(user2 , "lets meet at 4pm today! ");
        cout<<endl<<"-----------------"<<endl;
        user1->send("hello guys , shall we study together? ");

}