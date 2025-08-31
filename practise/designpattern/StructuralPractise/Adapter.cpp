
#include<bits/stdc++.h>
using namespace std ; 

/*
Adapter is used to make two incompatible systems work together.

- IndianPlug is an INTERFACE (no definition, only expected behavior: supply110v).

- UsSocket is an EXISTING CLASS that supplies 220v.

To make IndianPlug compatible with UsSocket,
we create an Adapter (UsSocketAdapter) that implements IndianPlug,
and internally uses UsSocket to fulfill the request.

Thus, the adapter translates calls from supply110v() to supply220v().
*/
 
class IndianPlug {
    public : 
    virtual void supply110v() =0 ;
};

class UsSocket{
    public : 
    void supply220v(){
        cout<<"Supply 220v"<<endl;
    }
};

class UsSocketAdapter : public IndianPlug { 
    UsSocket * ussocket ; //reference of usSocket
    public : 
    UsSocketAdapter(UsSocket * ussocket){
        this->ussocket = ussocket; // dep.inj via constructor 
    }
    void supply110v() override {
       ussocket->supply220v();
    }

};

int main(){
    UsSocket * socket = new UsSocket();
    IndianPlug * adapter  = new UsSocketAdapter(socket);
    adapter->supply110v();

}