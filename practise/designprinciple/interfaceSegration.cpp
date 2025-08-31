
#include<bits/stdc++.h>
using namespace std; 
 
/*
small interface are prefered over larger complex interface 
no client should be forced to depend on methods it does not use.
ISP is about segregation (interface design).
*/
 

class twoDimensional {
    public :
     virtual void area() = 0;
};
class threeDimensional  : public twoDimensional{
    public : 
    virtual void volume() = 0;

};
class  rectangle : public twoDimensional{
    public : 
    void area () override {
        cout<<"rectangle area implemented"<<endl;
    }

};
class  cube : public threeDimensional{
    public : 
    void area () override {
        cout<<"cube area implemented"<<endl;
    }
    void volume ()  override { 
        cout<<"cube voumne implemented " <<endl; 

    }

};

int main() { 
    rectangle * rect  = new rectangle();
    rect->area();

    cube * cubic = new cube();
    cubic->area();
    cubic->volume();

}