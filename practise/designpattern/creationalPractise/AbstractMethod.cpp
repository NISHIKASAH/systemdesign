
#include<bits/stdc++.h>
using namespace std;

class Sofa { 
    public : 
   virtual void display() =0;
};

class Chair { 
    public : 
    virtual void display() =0;
};

class ModernSofa : public Sofa{
     public : 
    void display(){
        cout<<"its a modern sofa "<<endl;
    }
};

class ModernChair : public Chair{
     public : 
    void display(){
        cout<<"its a modern chair "<<endl;
    }
};

class TraditionalSofa : public Sofa{
     public : 
    void display(){
        cout<<"its  a traditional sofa "<<endl;
    }
};

class TraditionalChair : public Chair{
     public : 
    void display(){
        cout<<"its a traditional chair "<<endl;
    }
};

class FurnitureFactory {
    public : 
    virtual Sofa * createSofa() =0;
    virtual Chair * createChair() = 0;
};

class ModernFurnitureFactory : public FurnitureFactory {

    public :
Sofa * createSofa() override {
        return new ModernSofa();
    }
   Chair* createChair() override {
        return new ModernChair();
    }
};

class TraditionalFurnitureFactory  : public  FurnitureFactory{

    public :
    Sofa * createSofa() override {
        return new TraditionalSofa();
    }
    Chair * createChair() override {
        return new TraditionalChair();
    }
};
int main(){
    FurnitureFactory * modern = new ModernFurnitureFactory();
   Sofa* msofa = modern->createSofa();
     Chair* mchair =  modern->createChair();
   msofa->display();
   mchair->display();


     FurnitureFactory * traditional = new TraditionalFurnitureFactory();
   Sofa * tsofa = traditional->createSofa();
   Chair * tchair =  traditional ->createChair();
   tsofa->display();
   tchair->display();


    

}