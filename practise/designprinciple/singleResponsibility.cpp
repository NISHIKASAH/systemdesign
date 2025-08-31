
#include<bits/stdc++.h>
using namespace std; 

/*
class handle single responsibility  , that does not mean 1 function , similar responsibilty 
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
    void saving(){
        cout<<"saving to db"<<endl;
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
    save->saving();

}