#include<bits/stdc++.h>
using namespace std;
/* 
Observer  pattern : When one object (subject) changes state, it notifies 
all dependent objects (observers) so they can update themselves automatically.

*/
 class User {
    public : 
    string username ; 
    User(string name){
        this->username = name;
    }
    void update(string notify){
        cout<<this->username<< "  is notify with new expenses "<<notify<<endl;
    }
 };
class Expenses {
    public : 
    string name ; 
    int amount ; 
    Expenses(string nm , int am){
        this->name = nm;
        this->amount = am;
    }
    
};

class Group {
    private : 
    vector<User*>MemberList;
    string groupName;
 string expenseName;
    public : 
    Group(string name){
        this->groupName = name;
    }
    void addUser(User * user){
        this->MemberList.push_back(user);
    }
    void UpdateExpenses(string exp){
     this->expenseName = exp;
      notifyAll();
        
    } 

    void notifyAll(){
        for(auto it : MemberList){
           
                it->update(this->expenseName);
            
        }
    }
};
int main(){
    cout<<"Observer implemented in splitwise system"<<endl;
    User * user1 = new User("nishika");
       User * user2 = new User("nitesh");
    Group* g1= new Group("dhol jhol");
    Group * g2 = new Group("peka boo");

    g1->addUser(user1);
    g1->addUser(user2);

   g1->UpdateExpenses("lunch");
   g1->UpdateExpenses("shopping");


}
