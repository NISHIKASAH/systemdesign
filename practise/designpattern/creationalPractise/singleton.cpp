#include<bits/stdc++.h>
using namespace std ; 


class DBConnection{
    private : 
    static DBConnection * Instance;
    DBConnection(){};
    public : 
   static DBConnection* getDBConnection(){
    if(Instance == nullptr){
        Instance = new DBConnection();
    }
    return Instance;
    }
    void MakeQuery(string query){
        cout<<"Query :"<<query<<"  is running"<<endl;
        
    }

};
    DBConnection * DBConnection ::Instance = nullptr;

int main(){
    cout<<"-----singleton implementation----"<<endl;
    DBConnection * obj1 = DBConnection::getDBConnection();
    DBConnection *obj2 =  DBConnection::getDBConnection();
    obj1->MakeQuery("obj1 creation");
    obj2->MakeQuery("obj2 creation");

    if(obj1 == obj2){
        cout<<"singleton implemented"<<endl;
    }
}