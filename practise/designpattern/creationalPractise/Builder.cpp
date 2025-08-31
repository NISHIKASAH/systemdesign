#include<bits/stdc++.h>
using namespace std;

class Laptop {
    string storage ;
    string processor ;
    string rom;
    bool graphicCard;
    public : 
     void setStorage (string s){
        this->storage = s;
     }
    void setProcessor (string p){
        this->processor = p;
    }
    void setRom(string r){
        this->rom = r;
    }
    void hasGraphicCard (bool g){
        this->graphicCard = g;
    }


    void showFeatures () {
        cout << "Laptop Feature :\n";
        cout << "Processor: " << processor << "\n";
        cout << "RAM: " << rom << "\n";
        cout << "Storage: " << storage << "\n";
        cout << "Graphics Card: " << (graphicCard ? "Yes" : "No") << "\n";
    }
   
};

class LaptopBuilder {
    protected : 
    Laptop * laptop ;
    public : 
    LaptopBuilder(Laptop * l){
        this->laptop = l;
    }
   virtual  ~LaptopBuilder(){};
   virtual void buildStorage () = 0;
    virtual void buildProcessor () = 0;
    virtual void buildRom()=0;
    virtual void buildGraphicCard () = 0;

    Laptop* getLaptop(){
        return laptop;

    }
};
class GamingLaptop : public LaptopBuilder {
    public : 
    GamingLaptop(Laptop * l) : LaptopBuilder(l) {};
     void buildStorage () override {
        laptop->setStorage("64 GB");
     }
   void buildProcessor () override {
    laptop->setProcessor("245");
   }
   void buildRom()  override {
    laptop->setRom("4 GB");
   }
    void buildGraphicCard () override {
        laptop->hasGraphicCard(true);
    }

};

class LaptopDirectory { 
    LaptopBuilder  * builder; 
    public :
    LaptopDirectory(LaptopBuilder * builder ) {
        this->builder = builder; 
    }
    Laptop * Build () {
        builder->buildStorage();
        builder->buildRom();
        builder->buildProcessor();
        builder->buildGraphicCard();
        return builder->getLaptop();
    }
}; 

int main(){
   
    Laptop * laptop = new Laptop();

    GamingLaptop * gaminglaptop = new GamingLaptop(laptop);


    LaptopDirectory * directory = new LaptopDirectory(gaminglaptop);
    Laptop * l = directory->Build();
    l->showFeatures();

    delete laptop;
    delete gaminglaptop;
    delete directory ; 



    
}