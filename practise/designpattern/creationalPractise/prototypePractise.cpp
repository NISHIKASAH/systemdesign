#include<iostream>
using namespace std;

class Cloneable {
    public : 
    virtual Cloneable* clone() const  =0 ;
    virtual void display() =0;

};

class NPC : public Cloneable {
    string name ;
    int defence;
    string attack;
    public : 
    NPC(string nam , string att , int def){
        this->name = nam;
        this->defence = def;
        this->attack  = att ; 
    }
    NPC (const NPC& other){
        name=  other.name;
        defence = other.defence;
        attack = other.attack;
    }
    Cloneable * clone() const override  { 
        return new NPC(*this);
    }
    
    void display() override {
        cout<<"Name : "<<name<<" Attack :"<<attack <<"Defence :"<<defence<<endl;
    }
    void setName(string nam){
        name = nam;

    }
};
int main(){
    NPC * alien = new NPC("alien" , "gunshot" , 2);
    NPC * clonealien = dynamic_cast<NPC*>(alien->clone());
    clonealien->setName("newalienclone");
    clonealien->display();


}
