#include<bits/stdc++.h>
using namespace std;

class Visitor ;
class Lion ;
class Elephant ;
class Monkey ; 
class ItemType {
    public : 
    virtual string accept(Visitor * visitor) = 0;
};
class Visitor { 
    public: 
    virtual  string visit(Lion * lion) =0;
     virtual  string visit(Elephant * elephant) =0;
      virtual  string visit(Monkey * monkey) =0;
};
class Lion : public ItemType {
    string name ;
    string food;
    public : 
    Lion(string n, string f){
        this->name = n;
        this->food = f;

    }
    string getName(){
        return name;
    }
    string getFoodStatus(){
        return food;
    }
    string accept(Visitor * visitor) override {
       return visitor->visit(this);
    }

};
class Monkey : public ItemType {
    string name;
    string food;
    public : 
      Monkey (string n, string f){
        this->name = n;
        this->food = f;

    }
    string getName(){
        return name;
    }
     string getFoodStatus(){
        return food;
    }
    string accept(Visitor * visitor) override  {
       return visitor->visit(this);
    }

};
class Elephant : public ItemType {
    string name ;
    string food;
    public : 

     Elephant (string n , string f){
        this->name = n;
        this->food = f;

     }
      string getName(){
        return name;
    }
     string getFoodStatus(){
        return food;
    }
    string accept(Visitor * visitor) override  {
       return  visitor->visit(this);
    }

};
class FeedingReportvisitor : public Visitor {
    public :
    string visit(Monkey * monkey){
       return  monkey->getFoodStatus();
    }
    string visit(Elephant* ele){
       return ele->getFoodStatus();
    }
     string visit(Lion* lion){
       return lion->getFoodStatus();
    }
};
class MedicalCheckupvisitor : public Visitor {
    public :
    string visit(Monkey * monkey){
       return  monkey->getName();
    }
   string visit(Elephant* ele){
       return ele->getName();
    }
     string visit(Lion* lion){
       return lion->getName();
    }
};
int main(){
    ItemType * zoo[] = {
        new Lion("lion" , "flesh") , new Elephant("elephant" , "grass") , 
        new Monkey("monkey" , "banana")
    };
    FeedingReportvisitor visitor ; 
    for(ItemType * item : zoo){
         string ans  = item->accept(&visitor);
         cout<<ans<<endl;
    }
    cout<<"-----------------"<<endl;
    MedicalCheckupvisitor visitor2 ; 
    for(ItemType * item : zoo){
         string ans  = item->accept(&visitor2);
         cout<<ans<<endl;
    }

}