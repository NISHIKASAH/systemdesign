#include<bits/stdc++.h>
using namespace std;

/*
Iterator Pattern:
- Provides a way to access elements without exposing internal structure.
- Useful when you want different ways to traverse a collection.
- Promotes separation of concern: Collection logic vs Traversal logic.
*/
 
class Product {
    string name ; 
    int price;
    public :
    Product(string name , int price){
        this->name=  name; 
        this->price = price;
    } 
    ~Product(){};
    string getName(){
        return this->name;
    }

    int getPrice(){
        return this->price;
    }
};
class Iterator {
    public : 
    virtual  Product * next() = 0;
    virtual  bool hasnext() =0 ;
    virtual Product * first() = 0;
    virtual  ~Iterator(){};
};
class ProductIterator : public Iterator {
    vector<Product*>productList;
    int idx ;
    public : 
    ProductIterator(vector<Product*>product , int i=0) {
        this->productList = product;
        this->idx =i;

    }
     bool hasnext() override {
        return idx <  productList.size();
    }
    Product* next () override {
        if(hasnext()){
            return productList[idx++];
        }
    }
    Product * first() override {
        if(productList.empty()){
            return nullptr;
        }
        idx = 0;
        return productList[idx];
        
    }
   
};
class ProductCollection {
    vector<Product*>productCollection;
    public : 

    void addProduct(Product * product){
        productCollection.push_back(product);
        
    }
    Iterator * createIterator(){
        return new ProductIterator(productCollection);
    }


};
int main(){
    Product * dress =  new Product("dress" , 1200);
     Product * shirt =  new Product("shirt" , 890);
      Product * pant =  new Product("pant" , 900);

      ProductCollection * stock  = new ProductCollection();
      stock->addProduct(dress);
      stock->addProduct(shirt);
      stock->addProduct(pant);

      Iterator * iterator = stock->createIterator();

      while(iterator->hasnext()){
       Product* ans = iterator->next();
       cout<<ans->getName()<<" : "<<ans->getPrice();
       cout<<endl;
       

      }
      delete dress;
      delete shirt;
      delete pant;
      delete stock ;
      delete iterator;
      
}