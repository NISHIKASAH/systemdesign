#include<bits/stdc++.h>
using namespace std;

/*
Separates operations from the object structure to keep classes clean.
Enables adding new actions (like TaxCalculator, DiscountApplier) without changing existing object code.
Improves maintainability by moving logic out of data classes and into dedicated visitor classes.
*/
class Visitor;
class Book;
class Fruit;
class ItemType {
    public :
     virtual int accept(Visitor * visitor) =0; //each item  , delegate action to visitor

};
class Visitor { // actions for individual objects
    public:
    virtual int visit(Book* item ) = 0;
    virtual int visit(Fruit* fruit ) = 0;
    
   
};

class Book : public ItemType {
    int price;
    int gst;
    public :
    Book(int price , int gst){
        this->price = price;
        this->gst = price;
    }
    int getPrice(){
        return price;
        
    }
    int getGst(){
        return gst;
    }
    int accept(Visitor * visitor) override{
       return  visitor->visit(this);
    }
    //rather then write operation here  , write it seperatly in visitor class  
    //seperate operation from object
};
class Fruit : public ItemType {
    int price;
    int gst;
    public :
    Fruit(int price, int gst){
        this->price= price;
        this->gst = gst;
    }
    int getPrice(){
        return price;
        
    }
    int getGst(){
        return gst;
    }
    int accept(Visitor * visitor) override {
       return visitor->visit(this);
    }
};
class DiscountVistior  : public Visitor {
    public:
    int visit(Book * book  ) override {
       int totalprice = book->getPrice() + book->getGst() ;
       if(totalprice >200){
        return totalprice- 50;
       }
       return totalprice;
        
    }
    int visit(Fruit * fruit) override {
         int totalprice = fruit->getPrice() + fruit->getGst() ;
       if(totalprice >300){
        return totalprice- 100;
       }
       return totalprice;
    }
};
int main(){
    ItemType * Cart[] = {
        new Fruit(200 , 20) , new Fruit(100 , 30) , new Book(400 , 30)
    };
    DiscountVistior *visitor  = new DiscountVistior();
    for(ItemType * it :  Cart){
       int ans = it->accept(visitor);
       cout<<ans<<endl;
       
    }

}
