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
 
class FoodItem { // base class 
    public :
    virtual int price() = 0;
    virtual  string getDescription() = 0;

};

class PlainPizza  : public FoodItem {
    public :
    int price() override {
        return 120;
    }
    string getDescription() override {
        return "It's a plain pizza";
    }
};


class PlainBurger  : public FoodItem {
    public :
    int price() override {
        return 90;
    }
    string getDescription() override {
        return "It's a plain burger";
    }
}; 
class Decorator : public FoodItem {
    protected :
    FoodItem * fooditem;
    public :
    Decorator(FoodItem * p){
        this->fooditem = p;
    }
};

class Olive : public Decorator {
    public: 
    Olive(FoodItem * p) : Decorator(p){};

    string getDescription(){
        return fooditem->getDescription() + " + Olive";
    }
    int price(){
        return fooditem->price() + 30 ;
    }

};
class Cheese  : public Decorator{
    public : 
    Cheese(FoodItem * p) : Decorator(p){}; // added decorator to PlainPizza

      string getDescription(){
        return fooditem->getDescription() + " + Cheese";
    }
    int price(){
        return fooditem->price() + 50 ;
    }
    
};

int main(){

    // Pizza * basicPizza = new PlainPizza();
    // Pizza * basicPizzawithCheese = new Cheese(basicPizza);
    // Pizza * basicPizzaWithCheeseAndOlive = new Olive(basicPizzawithCheese);
    // cout<<basicPizzaWithCheeseAndOlive->getDescription();
    // cout<<endl;
    // cout<<basicPizzaWithCheeseAndOlive->price();


    FoodItem * pizza  =  new Olive(new Cheese(new PlainPizza()));
    cout<<pizza->getDescription();
    cout<<endl;
    cout<<pizza->price();
   cout<<endl<<"---------"<<endl;
    FoodItem * burger = new Cheese(new PlainBurger());
    cout<<burger->getDescription();
    cout<<endl;
    cout<<burger->price();

}