#include<bits/stdc++.h>
using namespace std;

class Worker {
    public :
   virtual void getDescription() =0 ;

};
class Employees : public Worker  {
    string designation ;
    public :
    Employees(string s){
        this->designation =s;
    }
    void getDescription() override {
        cout<<"designation :"<<this->designation;
    }
    
};
class Manager : public Worker {
    string designation;
    vector<Worker*>workerList;
    public : 
    Manager(string s) :designation(s){};
    void addWorker(Worker * w)  {
        workerList.push_back(w);

    }
    void getDescription() override{
        for(auto &it :  workerList){
            it->getDescription();
        }
    }


};

int main(){

    Worker * w1 = new Employees("worker");
    Worker *m1 = new Manager("manager");

    Manager * superior = new Manager("managerHead");
    superior->addWorker(m1);
    superior->addWorker(w1);
    superior->getDescription();


}