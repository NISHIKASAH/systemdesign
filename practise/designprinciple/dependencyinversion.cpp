#include<bits/stdc++.h>
using namespace std;

/*
higher level class depends on abstract class , not concreate class , 
encourage loose coupling 
*/
class Database {
    public : 
    virtual void save ()  = 0;
};

class MongoDb  : public Database { 
    public : 
    void save () override {
        cout<<"saving to mongodb"<<endl;
    }
};
class SqlDb  : public Database { 
    public : 
    void save () override {
        cout<<"saving to sqldb"<<endl;
    }
};

class User {
    Database * database ;// we are using pointer bcoz we dont know which object is refering to ;
    public : 
    User (Database * d){
        database = d; // we are initilizing pointer to object here , which clien pass 
    }

    void savingtoDb(){
        database->save();
    }
};

int main(){
    Database * db  = new MongoDb();
    User * user = new User(db);
    user->savingtoDb();
}