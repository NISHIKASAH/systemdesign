
#include<bits/stdc++.h>
using namespace std; 
 

class shape {
    public : 
    virtual void area() = 0;
    virtual void volume() = 0;
};

class  rectangle : public shape{
    public : 
    void area () override {
        cout<<"rectangle area implemented"<<endl;
    }
    void volume ()  override { 
       throw logic_error("rectangle is 2d , no volume "); // voilating Liskov substiution principle 

    }

};
class  cube : public shape{
    public : 
    void area () override {
        cout<<"cube area implemented"<<endl;
    }
    void volume ()  override { 
        cout<<"cube area implemented " <<endl; 

    }

};

int main() { 
    rectangle * rect  = new rectangle();
    rect->area();

    try{
        rect->volume();
    }
    catch(logic_error & e){
        cout<<"exception : "<<e.what();
    }

}