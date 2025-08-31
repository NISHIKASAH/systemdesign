#include<bits/stdc++.h>
using namespace std;

class ProductPrototype {

    public : 
    virtual ProductPrototype * Clone() = 0;
    virtual void display() = 0 ;
    virtual ~ProductPrototype() {};

};

class Product1  : public ProductPrototype {
        string name ; 
    int price; 
    public : 
    Product1(string name , int price ) {
        this->name = name;
        this->price  = price;
        
    }
    ProductPrototype * Clone() override {
        return new Product1(*this);
    }
    void display(){
        cout<<this->name <<" : "<<this->price<<endl;
    }
};
class Product2 : public ProductPrototype { 
    string name ; 
    int price; 
    public : 
    Product2(string name , int price ){
        this->name = name ; 
        this->price = price ;
    }
    ProductPrototype * Clone(){
        return new Product2(*this);
    }
    void display (){
         cout<<this->name <<" : "<<this->price<<endl;
    }
};
int main(){

    ProductPrototype * p1 = new Product1("lakme" , 345);// original product
    ProductPrototype * lakme =  p1->Clone(); // clone product
    lakme->display();
    
    ProductPrototype * p2 = new Product2("Ponds" , 349);
    ProductPrototype* ponds = p2->Clone(); 
    ponds->display();

    delete p1 ;
    delete lakme;
    delete p2;
    delete ponds;

}