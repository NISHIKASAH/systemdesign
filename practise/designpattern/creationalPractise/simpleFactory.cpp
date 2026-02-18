
#include<iostream>
using namespace std;

/*
Factory method - factory class create object based on user demand (factory method has static method )
no object creation by client  , factory to handle the creation part 
follows open -close principle 
 you don’t care how it’s created.

*/
class Food {
    public : 
    string name;
    Food(string name){
        this->name = name;

    }
    virtual void Eat() =0;
};
class Pasta : public Food  {
    public : 
    Pasta(string name) : Food(name){};
    void Eat() override{
        cout<<this->name<<" is yummy!"<<endl;


    }
};

class Pizza :public Food  {
    public : 
    Pizza(string name) : Food(name){};
    void Eat() override{
        cout<<this->name<<" is yummy!"<<endl;


    }
};

class Burger:public Food  {
    public : 
    Burger(string name) : Food(name){};
    void Eat() override{
        cout<<this->name<<" is yummy!"<<endl;


    }
};

class FoodFactory {
    public :
   static Food* createFood(string type){
        if(type == "Pizza"){
            return new Pizza("pizza");
        }
        else if(type == "Pasta"){
            return new Pasta("pasta");
        }
        else if(type == "Burger"){
            return new Burger("burger");
        }
        else{
            return new Pizza("pizza");
        }

    }
};

int main(){
    Food * pasta = FoodFactory :: createFood("Pasta");
    pasta->Eat();
      Food * sandwich = FoodFactory :: createFood("Sandwich");
    sandwich->Eat();
   
}