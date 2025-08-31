
#include<bits/stdc++.h>
using namespace std; 

/*
open for extention  , close for modification  i .e 
can extend a class , but should not add new feature in  already present class  
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
class StoringDetails {
    public : 
    virtual void saving() =0;
};
class SaveToSQL : public StoringDetails  {
    public : 
    void saving() override {
        cout<<"saving to sql "<<endl;
    }

};
class SaveToMongoDb : public StoringDetails  {
    public : 
    void saving() override {
        cout<<"saving to MongoDb "<<endl;
    }

};
class SaveToFile : public StoringDetails  {
    public : 
    void saving() override {
        cout<<"saving to File "<<endl;
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

    SaveToMongoDb * mongdb = new SaveToMongoDb();
    mongdb->saving();

    SaveToFile * file = new SaveToFile(); // new added feature 
    file->saving();

}