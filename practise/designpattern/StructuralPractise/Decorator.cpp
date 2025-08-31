#include<bits/stdc++.h>
using namespace std;

/*
Decorator Pattern

- Used for wrapping new features or functionalities on a base object,
  without changing the base object itself.

- Decorator = *composition over inheritance*.
  It adds new behaviors dynamically by wrapping objects,
  avoiding subclass explosion.

- Each decorator holds a reference to the same base type,
  so multiple decorators can be stacked on top of each other.

- Example: 
  Pizza* order = new Cheese(new Olives(new PlainPizza()));
  Here, Cheese wraps Olives, which wraps PlainPizza.
*/
 
class Coffee {
    public : 
    virtual int price() = 0;
    virtual  string getDescription() = 0;

};

class PlainCoffee : public Coffee  {
    public : 
    int price() override {
        return 40;
    }
    string getDescription() override {
        return "It's a plain Coffee" ;
    }
};

class CoffeeDecorator : public Coffee {
    protected : 
    Coffee * coffee ; 
    public :
    CoffeeDecorator(Coffee * coff) {
        this->coffee = coff ;
    }

};

class Caramel : public CoffeeDecorator {
    public : 
    Caramel(Coffee * c)  : CoffeeDecorator(c) {};

      string getDescription() override{
        return coffee->getDescription() + " + Caramel"; // dont access description  , using this(refer to current class) , access using 
        //composite obj use - here l coffee 
    }
    int price() override {
        coffee->price() + 40 ;
    }

};

class Milk : public CoffeeDecorator{
    public : 
    Milk(Coffee * c) : CoffeeDecorator(c){};
      string getDescription() override {
       return coffee->getDescription() + " + Milk";
    }
    int price() override {
        return coffee->price() + 20;
    }


};

class Sugar : public CoffeeDecorator { 
    public : 
    Sugar (Coffee * c) : CoffeeDecorator(c){};

     string getDescription(){
       return coffee->getDescription() + " + Sugar";
    }
    int price(){
        return coffee->price() + 10;
    }
};


int main(){
    // Coffee * BasicCoffee = new PlainCoffee();
    // Coffee* BasicCoffeewithMilk = new Milk(BasicCoffee);
    
    // Coffee * caramel = new Caramel(BasicCoffeewithMilk);
    // cout<<caramel->getDescription();
    // cout<<endl;
    // cout<<caramel->price();

    Coffee * coffee = new Milk( new Caramel(new PlainCoffee()));

    cout<<coffee->getDescription();
    cout<<endl;
    cout<<coffee->price();



}