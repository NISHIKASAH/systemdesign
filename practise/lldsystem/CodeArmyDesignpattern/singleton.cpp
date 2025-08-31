#include <bits/stdc++.h>
#include <mutex>
using namespace std;

class Database
{

private:
    static Database *instance;
   // static mutex mtx;
    Database()
    {
        cout << "Object created " << endl;
    }

public:
    static Database *getInstance()
    {
        if (instance == nullptr)
        {
           // lock_guard<mutex>(mtx);
            if (instance == nullptr)
            {
                instance = new Database();
            }
            return instance;
        }
    }
};
Database *Database ::instance = nullptr;
//mutex Database ::mtx;
int main()
{
    Database *s1 = Database ::getInstance();
    Database *s2 = Database ::getInstance();
    cout << (s1 == s2) << endl;
}