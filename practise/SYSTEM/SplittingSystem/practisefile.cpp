#include<bits/stdc++.h>
using namespace std;

class User {
    public : 
    string name ; 
    User(string na){
        this->name = na;
    }
};

class Split {
    public : 
    User *user ;
    double amount ; 
    Split(User *user , int am){
        this->user = user ; 
        this->amount  = am;
    }
};

class Expenses { 
    public : 
    string expName ; 
    double amount;
    vector<Split*>SplitList;

    Expenses(string ex , int am , vector<Split*>sp){
        this->expName = ex;
        this->amount = am;
        this->SplitList = sp;

    }
   
};
class Group{
    public : 
    string groupName ; 
    vector<Expenses*>expenseList;
    vector<User*>memberList;
    Group(string name){
        this->groupName = name;
    }
    void addExpenses(Expenses * ex){
        cout<<"New expense add to group"<<this->groupName<<endl;
        this->expenseList.push_back(ex);
    }
    void addMember(User * user){
        cout<<"New Memeber add to group"<<user->name<<endl;
        this->memberList.push_back(user);
    }

};


class BalanceSheet{
    public : 
    unordered_map<User* , unordered_map<User* ,int >>Balance;

    void addTransaction(User* paidBy , User *paidTo , double amount){
               Balance[paidBy][paidTo] += amount;
        Balance[paidTo][paidBy] -= amount;

    }
    void showBalance(){
        for(auto balance : Balance){
            auto &paidBy = balance.first ; 
            for(auto &paidTo : balance.second){
                if(paidTo.second >0){
                    cout<<paidTo.first->name  <<" "<<"Own "<<paidTo.second<< " money from " << paidBy->name<<endl;
                }
            }
        }
    }
};

int main(){
    User * u1 = new User("nishika");
    User* u2 = new User("nitesh");

    Split * sp1 = new Split(u1 , 1000);
    Split* sp2 = new Split(u2 , 1000);

    vector<Split*>splitList1= {sp1 , sp2};
    Expenses * exp1 = new Expenses("lunch" , 2000 , splitList1);

    Split * sp3 = new Split(u1 , 4000);
    Split* sp4 = new Split(u2 , 4000);
     vector<Split*>splitList2= {sp3 , sp4};

    Expenses *exp2 = new Expenses("Travel" , 8000 , splitList2);

    Group* g1 = new Group("adha kanun");

    g1->addExpenses(exp1);
    g1->addExpenses(exp2);

    g1->addMember(u1);
    g1->addMember(u2);
    

    BalanceSheet * balance  = new BalanceSheet();
    for(auto it : splitList1){
        if(it->user != u1){
            balance->addTransaction(u1, it->user , it->amount);
        }
    }
    balance->showBalance();
    


}