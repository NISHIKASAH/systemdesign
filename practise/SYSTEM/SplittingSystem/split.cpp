
#include <bits/stdc++.h>
using namespace std;

class User
{
public:
    string name;

    User(string nm)
    {
        this->name = nm;
    }
};

class Split
{
public:
    User *name;
    int eachSplit;
    Split(User *nm, int split)
    {
        this->name = nm;
        this->eachSplit = split;
    }
};
class Expenses
{
public:
    string expName;
    int amount;
    vector<Split> splitList;
    Expenses(int am, string exp, vector<Split> split)
    {
        this->expName = exp;
        this->amount = am;
        this->splitList = split;
    }
};

class Group
{
public:
    string groupName;
    vector<User *> memberList;
    vector<Expenses *> expenseList;

    Group(string gname)
    {
        this->groupName = gname;
     
    }
    void addExpenses(Expenses *exp)
    {
        cout << "Expenses created for : " << exp->expName << endl;
        expenseList.push_back(exp);
    }
    void addUser(User *user)
    {
        cout << "New Member add to group" << groupName << endl;
        memberList.push_back(user);
    }
};

class BalanceSheet
{
public:
    unordered_map<User *, unordered_map<User *, double>> Balance;

    void addTransaction(User *paidBy, User *paidTo, int amount)
    {
        Balance[paidBy][paidTo] -= amount;
        Balance[paidTo][paidBy] += amount;
    }
    void showBalance()
    {
        for (auto &it : Balance)
        {
            User *userWhoPay = it.first;
            for (auto &i : it.second)
            {
                if (i.second > 0)
                {
                    cout << i.first << "owns " << i.second << "from "  << userWhoPay->name << endl;
                }
            }
        }
    }
};

int main()
{
    User *u1 = new User("nishika");
    User *u2 = new User("nitesh");
    User *u3 = new User("tenish");

    vector<User*>member= {
        u1 , u2 , u3
    };

    Split *sp1 = new Split(u1, 2000);
    Split *sp2 = new Split(u2, 3000);

    vector<Split> split = {
        sp1, sp2};

    Expenses *Lunch = new Expenses(5000, "Lunch", split);

    Expenses *Dinner = new Expenses(3000, "Dinner", split);


    Group *g1 = new Group("chaddi mere baddi" );
    g1->addExpenses(Lunch);
    g1->addExpenses(Dinner);

    BalanceSheet* balance = new BalanceSheet();
    balance->addTransaction(u1 , u2 , 1000);
    balance->showBalance();

}