#include<iostream>
#include<vector>
using namespace std;


class Worker { 
    public : 
    virtual string getworkername()=0;
    virtual bool isManager()=0;
    virtual string getDegination() = 0;
    virtual void showHerirachy(int level) =0;

};

class Employeer  : public Worker {
    string name; 
    string degination ; 
    public : 
    Employeer(string n , string deg){
        name = n;
        degination = deg;
    }
    string getworkername() override {
        return name;
    }
    bool isManager(){
        return false;
    }

    string getDegination() override {
        return degination;
    }
    void showHerirachy(int level){
        cout<<string(level*2 , ' ') + '-' + degination<<endl;
    }
};

class Manager : public Worker {
     string name; 
    string degination ; 
    vector<Worker*>workerList;
    public : 
    Manager(string n , string deg){
        name = n;
        degination = deg;
    }
    string getworkername() override {
        return name;
    }
    void addEmployees(Worker * worker){
        workerList.push_back(worker);

    }
    bool isManager(){
        return true;
    }

    string getDegination() override {
        return degination;
    }
    void showHerirachy(int level) override {
        cout<<string(level*2 , ' ') + degination<<endl;
        for(auto it : workerList){
           
                it->showHerirachy(level+1);
            
           
        }
    }


};

int main(){
    Manager* manager = new Manager("depash" , "subordinate manager");
     Manager* seniormanager = new Manager("nishika" , "senior manager");
     Worker* worker1 = new Employeer("trisha" , "3yrsde"); 
     Worker* worker2 = new Employeer("krisha" , "2yr sde");
     Worker* worker3= new Employeer("krisha" , "1yr sde");
    manager->addEmployees(worker1);
    manager->addEmployees(worker2);
    // manager->showHerirachy(1);
    seniormanager->addEmployees(worker3);
    seniormanager->addEmployees(manager);
    seniormanager->showHerirachy(1);


     


}