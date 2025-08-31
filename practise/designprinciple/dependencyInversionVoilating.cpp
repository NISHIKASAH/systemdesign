#include<bits/stdc++.h>
using namespace std;

class MongoDb { // lower class 
    public : 
   void saveToMongoDb() {
        cout<<"Saving to mongodb "<<endl;
    }

};
class SQLDb  { 
    public : 
    void saveToSql() {
        cout<<"saving to sql"<<endl;
    }

}; 
class User {  // high class 
    MongoDb  mongdb; // tight coupling  , pointer not use here , bcoz we know which object it refer 
    SQLDb  sqldb ;
    public : 
    void  userdetailstoMongdb (){

        mongdb.saveToMongoDb();

    }
    void userdetailsToSQL(){
        sqldb.saveToSql();
    }

    
};
int main(){
     MongoDb * db  = new MongoDb();
    User * user = new User();
    user->userdetailstoMongdb();

}