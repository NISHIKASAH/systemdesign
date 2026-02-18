#include<bits/stdc++.h>
using namespace std;

class Document {
    public:
    virtual Document* Clone() = 0;
    virtual  void Display () =0 ;

};

class Resume : public Document { 
    public : 
    Document * Clone() override  {
        return new Resume(*this); 
    }

    void Display(){
        cout<<"created a  Resume "<<endl;
    }
};

class Report : public Document { 
    public : 
    Document * Clone(){
        return new Report(*this);
    }
   void Display(){
        cout<<"created a  Report "<<endl;
    }

};
int main(){
    Document * obj  =  new Resume(); 
    obj->Clone();
    obj->Display();


    Document *obj2 = new Report();
    obj2->Clone();
    obj2->Display();


}

