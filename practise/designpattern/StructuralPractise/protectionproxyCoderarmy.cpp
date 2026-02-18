#include <bits/stdc++.h>
using namespace std;

class IdocReader
{
public:
    virtual void unlock() = 0;
};
class RealdocReader : public IdocReader
{
    string username;
    string password;

public:
    RealdocReader(string n, string p)
    {
        username = n;
        password = p;
    }
    void unlock() override
    {
        cout << username << " You have access to document" << endl;
    }
};

class User
{

public:
    string name;
    bool isPremium;
    User(string n, bool p)
    {
        name = n;
        isPremium = p;
    }
};
class ProxydocReader : public IdocReader
{
    string username;
    string password;
    RealdocReader *realdoc;
    User *user;

public:
    ProxydocReader(string n, string p, User *userdetail)
    {
        username = n;
        password = p;
        realdoc = nullptr;
        user = userdetail;
    }
    void unlock() override
    {
        if (realdoc == nullptr)
        {
            if (user->isPremium)
            {
                realdoc = new RealdocReader(username , password);
            }
            else{
                cout<<username <<" your dont have premium "<<endl;
            }
        }
        realdoc->unlock();
    }
};

int main(){
    User * user = new User("nishika" , false);
    IdocReader * doc = new ProxydocReader("Nisa" , "helloji" , user
    );

    doc->unlock();

}