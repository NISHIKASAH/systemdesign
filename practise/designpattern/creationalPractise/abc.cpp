#include<bits/stdc++.h>
using namespace std;

class Pizza {
    string base ; 
    string topping ; 
    string sause ; 
    bool hasCheese ; 

    public : 
   void setBase(string base ){
        this->base = base; 
    }
    void setTopping(string topping){
        this->topping = topping;
    }
    void setSause(string sause){
        this->sause = sause;
    }
    void setCheese(bool cheese){
        this->hasCheese= cheese; 
    }
    void getPizzaDetails() { 
        cout << "Pizza Feature :\n";
        cout << "base: " << base << "\n";
        cout << "topping: " << topping << "\n";
        cout << "sause: " << sause << "\n";
        cout << "hasCheese : " << (hasCheese ? "Yes" : "No") << "\n";
    }

};
class PizzaBuilder {
    protected : 
    Pizza * pizza ; 
    public :
    PizzaBuilder(Pizza * pizza){
        this->pizza = pizza; 
    }
    virtual void buildingBase() = 0;
     virtual void buildingSause() = 0 ;
     virtual void buildingTopping ()= 0;
     virtual void buildingCheese() = 0 ;
     Pizza * getPizza(){
        return this->pizza;
    }

};

class VeggiePizzaBuilder : public PizzaBuilder {
    public : 
    VeggiePizzaBuilder(Pizza * p) : PizzaBuilder(p){};
    void buildingBase(){
        pizza->setBase("Thick Base ");
    }
     void buildingSause(){
        pizza->setSause(" Tomato ");
    }
     void buildingTopping (){
        pizza->setTopping(" Paneer ");
    }
     void buildingCheese(){
        pizza->setCheese(true);
    }
    

};
class CheeseLoverBuilder : public PizzaBuilder {
    public : 
     CheeseLoverBuilder(Pizza * p) : PizzaBuilder(p){};
    void buildingBase(){
        pizza->setBase("Thick Base ");
    }
     void buildingSause(){
        pizza->setSause(" Chillies ");
    }
     void buildingTopping (){
        pizza->setTopping(" Paneer ");
    }
     void buildingCheese(){
        pizza->setCheese(true);
    }
    

};
class SpicyPizzaBuilder : public PizzaBuilder {
    public : 
    SpicyPizzaBuilder(Pizza * p) : PizzaBuilder(p){};
    void buildingBase(){
        pizza->setBase("Thick Base ");
    }
     void buildingSause(){
        pizza->setSause(" Pesto ");
    }
     void buildingTopping (){
        pizza->setTopping(" Paneer ");
    }
     void buildingCheese(){
        pizza->setCheese(true);
    }

};

class PizzaDirectory {
    PizzaBuilder * Builder; 
    public: 
    PizzaDirectory(PizzaBuilder* builder){
        this->Builder = builder;
    }
      Pizza * Build(){
        this->Builder->buildingBase();
        this->Builder->buildingCheese();
        this->Builder->buildingSause();
        this->Builder->buildingTopping();
        return this->Builder->getPizza();   

    }
};

int main(){
    Pizza * pizza = new Pizza();
    PizzaBuilder * spicypizza = new SpicyPizzaBuilder(pizza);
    
    PizzaDirectory * directory = new PizzaDirectory(spicypizza);
    Pizza* yourPizza = directory->Build();
    yourPizza->getPizzaDetails();

}


//through process 
 /*
 pizza - base , topping , sauce , cheese , function for setting all properties 
 pizzaBuilder  - base to take pizza and build   ,create  abstract class here , 
 do actual  implementation in concreete class 
 ChesseSpicyPizza :  build each properties of pizza  , does the actual building . 
directory - has builder control , does the execution part of build. 
client  , get the product  .
 */