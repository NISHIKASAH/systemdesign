// #include<bits/stdc++.h>
// using namespace std;

// /*
// ChainOfResponsibility :
// - Used to process a request through a chain of handlers.
// - Each handler has a specific responsibility.
// - If it can't handle the request, it forwards it to the next handler (if present).
// - All handlers are independent and loosely coupled.
// - Promotes flexibility in assigning responsibilities without changing sender or receiver.
// -promotes loose coupling - use composition , instead of inheritance .
//  */
// class Orderhandler {
//     protected:
//       Orderhandler * nexthandler;
//     public : 
//     Orderhandler(Orderhandler * order){
//         this->nexthandler = order;
//     }

//     virtual void ProcessOrder(string order) = 0;


// };
// class OrderValidatingHandler : public Orderhandler {
//     public : 
//     OrderValidatingHandler(Orderhandler * order) : Orderhandler(order){};
//     void ProcessOrder(string order ) override {
//         cout<<"Order validating :"<<order<<endl;
//          if(nexthandler){ //ONLY OF PRESENT , PASS TO NEXT HANDLER 
//             nexthandler->ProcessOrder(order);

//     }
//     }
// };

// class OrderPaymentHandler : public Orderhandler {
//     public : 
//     OrderPaymentHandler(Orderhandler * order) : Orderhandler(order){};
//     void ProcessOrder(string order ) override {
//         cout<<"Order Payment :"<<order<<endl;
//          if(nexthandler){
//             nexthandler->ProcessOrder(order);

//     }
//     }
// };
 

// class OrderPreparationHandler : public Orderhandler {
//     public : 
//     OrderPreparationHandler(Orderhandler * order) : Orderhandler(order) {};
//     void ProcessOrder(string order){
//         cout<<"Order Preperation :"<<order<<endl;
//         if(nexthandler){
//             nexthandler->ProcessOrder(order);
//         }
//     }


// };
// class OrderDeliveryTrackHandler : public Orderhandler { 
//     public : 
//     OrderDeliveryTrackHandler(Orderhandler * order) : Orderhandler(order){};
//     void ProcessOrder(string order){
//         cout<<"Order delivery :"<<order<<endl;
//         if(nexthandler){
//             nexthandler->ProcessOrder(order);
//         }
//     }
// };
// int main(){
//     cout<<"Implement chain of responsility"<<endl;
//     Orderhandler * order = new OrderValidatingHandler(
//         new OrderPaymentHandler(
//             new OrderPreparationHandler(
//                 new OrderDeliveryTrackHandler(nullptr)
//             )
//         )
//     );
//     order->ProcessOrder("Butter Paneer");



// }


#include<iostream>
using namespace std;

class AtmDispenser {
   
    public : 
    virtual  int  Dispense( int amount ) = 0;
    virtual void sethandler(AtmDispenser * next) = 0;

};

class thousandRupeedispenser : public AtmDispenser {
     AtmDispenser * handler;
     int thousandnote ;
    public : 
    thousandRupeedispenser(int num){
        thousandnote = num ;
        handler = nullptr;
    }
    void sethandler(AtmDispenser * next){
        handler = next;
        
        
    }
    int Dispense(int amount) {
        int amountavailable = thousandnote * 1000 ;
        int remaining = amountavailable - amount;
        if(remaining >0){
            cout<<"Amount cannot be fulfilled"<<endl;
            handler->Dispense(remaining);
        }
        else{
            int remainingnotes = remaining / 1000;
            thousandnote -= remainingnotes;
            cout<<"Amount filled"<<endl;

        }

    }
};

class fiftyRuppenotedispenser : public AtmDispenser {
     AtmDispenser * handler;
     int fiftynote ;
    public : 
    fiftyRuppenotedispenser(int num){
        fiftynote = num ;
        handler = nullptr;
    }
    void sethandler(AtmDispenser * next){
        handler = next;
        
        
    }
      int Dispense(int amount) {
        int amountavailable = fiftynote* 50;
        int remaining = amountavailable - amount;
        if(remaining >0){
            cout<<"Amount cannot be fulfilled"<<endl;
            handler->Dispense(remaining);
        }
        else{
            int remainingnotes = remaining / 50;
           fiftynote -= remainingnotes;
           cout<<"Amount fulfilled sucessfully"<<endl;
           

        }

    }
};

class hundredRuppenotedispenser : public AtmDispenser {
     AtmDispenser * handler;
     int hundrednote ;
    public : 
    hundredRuppenotedispenser(int num){
        hundrednote = num ;
        handler = nullptr;
    }
    void sethandler(AtmDispenser * next){
        handler = next;
        
        
    }
      int Dispense(int amount) {
        int amountavailable = hundrednote* 100;
        int remaining = amountavailable - amount;
        if(remaining >0){
            cout<<"Amount cannot be fulfilled"<<endl;
            handler->Dispense(remaining);
        }
        else{
            int remainingnotes = remaining / 100;
           hundrednote -= remainingnotes;
            cout<<"Amount filled"<<endl;

        }

    }
};


int main(){

    AtmDispenser * thousandRupee = new thousandRupeedispenser(3);
     AtmDispenser * hundredRupee = new hundredRuppenotedispenser(2);
      AtmDispenser * fiftyRupee = new fiftyRuppenotedispenser(4);

     thousandRupee->sethandler(hundredRupee);
     hundredRupee->sethandler(fiftyRupee);
     thousandRupee->Dispense(1150);
      



}