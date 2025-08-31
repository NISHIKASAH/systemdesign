
#include<bits/stdc++.h>
using namespace std; 

/*
open for extention  , close for modification  i .e 
can extend a class , but should not add new feature to existing class 
-do this by abstraction 
*/

class Product {
    string name ; 
    int price;
    public:
    Product(string n , int p){
        this->name = n ;
        this->price = p;

    }
    int getPrice(){
        return price;
    }
    string getName(){
        return name;
    }
    

};
class ShoppingCart {
     vector<Product * > productList;
    public: 
    void addProduct(Product  *p){
        productList.push_back(p);
    }
    vector<Product* > getProduct(){
        return productList;
        
    }

};

class PrintInvoice{ 
    ShoppingCart * cart ;
    public : 
    PrintInvoice(ShoppingCart *cart ){
        this->cart = cart ;
    };
     void printInvoice(){
        for(auto it : cart->getProduct()){
            cout<<it->getName()<<endl;
            cout<<it->getPrice()<<endl;
        }
    }

};
class ProductTotal{
    ShoppingCart * cart; 
    public : 
    ProductTotal(ShoppingCart *cart){
        this->cart = cart;
    }
    int CalculateTotal (){ 
        int total = 0;
        for(auto it : cart->getProduct()){
            total += it->getPrice();
        }
        return total;
    }

};
class SaveToDb {
    ShoppingCart * cart ;
    public : 
    SaveToDb(ShoppingCart * cart){
        this->cart = cart;
    }
    void savingToSQL(){
        cout<<"saving to sql "<<endl;
    }
    void savingToMongoDb(){
        cout<<"saving to mongodb"<<endl;
    }
    void savingtofILE (){
        cout<<"saving to file"<<endl; // we are modifying existing class
    }

};
int main(){
       Product * dress  = new Product("dress" , 200);
    Product * shorts  = new Product("shorts" , 400);
    Product * pant  = new Product("pant" , 250);
    ShoppingCart * cart = new ShoppingCart();
    cart->addProduct(dress);
    cart->addProduct(shorts);
    cart->addProduct(pant);

    ProductTotal * total = new ProductTotal(cart);
   cout<< total->CalculateTotal();

    PrintInvoice * invoice = new PrintInvoice(cart);
    invoice->printInvoice();

    SaveToDb * save = new SaveToDb(cart);
    save->savingToSQL();

    save->savingtofILE();
}