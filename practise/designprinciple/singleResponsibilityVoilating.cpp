#include<bits/stdc++.h>
using namespace std;

/*
Performing every functionality  in single class 
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
    int CalculateTotal (){
         int total = 0;
        for(auto it : productList){
            total += it->getPrice();
        }
        return total;
    }
   void printInvoice(){
        for(auto it : productList){
            cout<<it->getName()<<endl;
            cout<<it->getPrice()<<endl;
        }
    }
    void saveToDb(){
        cout<<"Saved order details to db "<<endl;
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
   cout<< cart->CalculateTotal();
    cart->printInvoice();
    cart->saveToDb();


}