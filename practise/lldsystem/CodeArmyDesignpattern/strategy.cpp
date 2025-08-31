#include<bits/stdc++.h>
using namespace std ;

class Talkable {
    public : 
    virtual  void talk() = 0;
};
class NormalTalk: public Talkable { //inhertance 
    public : 
    void talk() override {
        cout<<"normally Talking" <<endl;
    }
};

class NoTalk: public Talkable {
    public : 
    void talk() override {
        cout<<"could not talk" <<endl;
    }
}; 

class Walkable {
    public : 
    virtual  void walk() = 0;
};
class NormalWalk: public Walkable {
    public : 
    void walk() override {
        cout<<"normally Walking" <<endl;
    }
};

class NoWalk: public Walkable {
    public : 
    void walk() override {
        cout<<"could not walk " <<endl;
    }
}; 

class Flyable {
    public : 
    virtual  void fly() = 0;
};
class NormalFly : public Flyable {
    public : 
    void fly() override { //dynamic polymorphism implemented 
        cout<<"normally flying" <<endl;
    }
};

class NoFly: public Flyable {
    public : 
    void fly() override {
        cout<<"no flying" <<endl;
    }
}; 

class JetFly : public NormalFly { //implemented new feature without effecting previous structure and without voilating ocp 
    public : 
    void fly () override {
        cout<<"New Feature of fly implement , flying with jet ";
    }
};
class Robot {
    Walkable * walkBehaviour ; // composition  has -a rln (reference of class walkable )
    Flyable *flyBehaviour;
    Talkable * talkBehaviour;
    public : 
    Robot (Walkable * w , Flyable*f , Talkable* t ) {
        walkBehaviour =w;
        flyBehaviour = f;
        talkBehaviour = t;
    }
    void Walking() {
        walkBehaviour->walk(); 
    }
    void Talking(){
        talkBehaviour->talk();
    }
    void Flying(){
        flyBehaviour->fly();
    }
    virtual  void Apperance() = 0;
};

class WorkerRobot : public Robot {
    public : 
     WorkerRobot(Walkable * w , Flyable*f , Talkable* t ) : Robot(w , f, t) {};
    void Apperance() override {
        cout<<"Worker robot"<<endl;
    }

};

class CompanionRobot: public Robot  {
    public : 
      CompanionRobot(Walkable * w , Flyable*f , Talkable* t ) : Robot(w , f, t) {};
    void Apperance() override {
        cout<<"Worker robot"<<endl;
    }

};

int main(){
    Robot * robot = new WorkerRobot(new NormalWalk() ,  new JetFly(),new NormalTalk());
    robot->Talking();// runtime call 
    robot->Flying();
    robot->Walking();
    robot->Apperance();

};