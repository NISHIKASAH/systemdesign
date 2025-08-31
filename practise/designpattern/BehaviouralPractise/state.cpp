#include<bits/stdc++.h>
using namespace std ;

/*
Allow object to alter it behaviour when its internal state change.
appear as if object change it class
*/
class AtmState {
    public:
    virtual void handleRequest() =0 ;
    virtual void  handleCancel() = 0;
};

class EnterCardState : public AtmState  {
    public : 
    void handleRequest() override {
        cout<<"Enter card request has been made "<<endl;
    }
    void handleCancel () override {
        cout<<"Enter card  request has been cancelled "<<endl;
    }


};
class EnterPinState : public AtmState  {
    public : 
    void handleRequest() override {
        cout<<"Enter pin request has been made "<<endl;
    }
    void handleCancel () override {
        cout<<"Enter pin request has been cancelled "<<endl;
    }


};
class WithDrawState : public AtmState  {
    public : 
    void handleRequest() override {
        cout<<"Withdraw request has been made "<<endl;
    }
    void handleCancel () override {
        cout<<"Withdraw request has been cancelled "<<endl;
    }


};

class Atm {
    AtmState *state ; 
    public : 
    Atm(){
        this->state =  new EnterCardState(); //initilaizing to enter card

    }
    void setState(AtmState  *newstate ){
        state = newstate;

    }
    void requestToAtm(){
        state->handleRequest();

    }
    void cancelRequestToAtm(){
        state->handleCancel();
    }


};
int main(){
    Atm atm ; 
    atm.requestToAtm();
    atm.cancelRequestToAtm();

    atm.setState(new EnterPinState());
    atm.requestToAtm();
    atm.cancelRequestToAtm();

    atm.setState(new WithDrawState());
    atm.requestToAtm();
    atm.cancelRequestToAtm();


}