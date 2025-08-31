
#include<bits/stdc++.h>
using namespace std;

/*
So the client picks a factory, and each factory knows how to create a specific product
subclasses decide which class to instantiate . 
user don't know  , what factory produce . 
***	Decides which factory to use, not which product.***
scenerio :  you choose expensiveshowroom ,you dont know what is product , 
expensive factory create it product , and you just use the product .


*/
class Furniture{
    public:
    virtual void display() =0; 

};

class Sofa : public  Furniture {
    public : 
    void display () override {
        cout<<"its a sofa"<<endl;
    }
};

class Table : public  Furniture {
    public : 
    void display () override {
        cout<<"its a table "<<endl;
    }
};

class Chair : public  Furniture {
    public : 
    void display () override {
        cout<<"its a chair"<<endl;
    }
};

class FurnitureFactory {
    public : 
    virtual Furniture* createFurniture() = 0;
};

class LuxuryFactory : public FurnitureFactory {
    public : 
    Furniture * createFurniture() override {
        return new Sofa();
    }
};

class OfficeFactory : public FurnitureFactory {
    public : 
    Furniture * createFurniture() override {
        return new Table();
    }
};
class CafeFactory : public FurnitureFactory {
    public : 
    Furniture * createFurniture() override {
        return new Chair();
    }
};

int main(){
    FurnitureFactory * luxuryShowroom = new LuxuryFactory();

    Furniture * sofaset = luxuryShowroom->createFurniture();
    sofaset->display();

     FurnitureFactory * cafeShowroom = new CafeFactory();

    Furniture * chairset = cafeShowroom->createFurniture();
    chairset->display();
    

}