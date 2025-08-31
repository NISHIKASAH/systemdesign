#include<bits/stdc++.h>
using namespace std;

class Product {
    private : 
    string name ; 
    int price ;
    public : 
    Product(string name , int price){
        this->name = name; 
        this->price = price;
    }
    string getName(){
        return name;
    }
    int getPrice(){
        return price;
    }
};
class Iterator {
    public : 
    virtual Product * next() =0 ;
    virtual  bool  hasnext() =0 ;
    virtual Product *first() = 0;
};

class ProductIterator  :  public Iterator {
    vector<Product*>productList;
    int idx ;
    public : 
    ProductIterator(vector<Product*>product , int i  =0){
        this->productList = product;
        this->idx  = i;
    }
    Product * first() override {
        if(productList.empty()){
            return nullptr;
        }
        idx= 0;
        return productList[idx];
    }
    bool hasnext() override {
        return idx < productList.size();
    }
    Product * next() override {
        if(hasnext()){
            return productList[++idx];
        }
        return nullptr;
    }
};
class ProductCollection {
    vector<Product*>ProductCollection;
    int idx;
    public:
    void addProduct(Product * product){
        ProductCollection.push_back(product);
    }
    Iterator * createIterator(){
        return new ProductIterator(ProductCollection);
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
      cout<<"First : " << stock->createIterator()->first()->getName()<<endl;
      while(iterator->hasnext()){
        Product * item = iterator->next();
        cout<<item->getName()<<" : "<< item->getPrice() <<endl;
      }
      

}