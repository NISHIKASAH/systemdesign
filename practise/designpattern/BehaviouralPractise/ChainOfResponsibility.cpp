#include<bits/stdc++.h>
using namespace std;

/*
ChainOfResponsibility :
- Used to process a request through a chain of handlers.
- Each handler has a specific responsibility.
- If it can't handle the request, it forwards it to the next handler (if present).
- All handlers are independent and loosely coupled.
- Promotes flexibility in assigning responsibilities without changing sender or receiver.
-promotes loose coupling - use composition , instead of inheritance .
 */
class Orderhandler {
    protected:
      Orderhandler * nexthandler;
    public : 
    Orderhandler(Orderhandler * order){
        this->nexthandler = order;
    }
  
    virtual void ProcessOrder(string order) = 0;


};
class OrderValidatingHandler : public Orderhandler {
    public : 
    OrderValidatingHandler(Orderhandler * order) : Orderhandler(order){};
    void ProcessOrder(string order ) override {
        cout<<"Order validating :"<<order<<endl;
         if(nexthandler){ //ONLY OF PRESENT , PASS TO NEXT HANDLER 
            nexthandler->ProcessOrder(order);

    }
    }
};

class OrderPaymentHandler : public Orderhandler {
    public : 
    OrderPaymentHandler(Orderhandler * order) : Orderhandler(order){};
    void ProcessOrder(string order ) override {
        cout<<"Order Payment :"<<order<<endl;
         if(nexthandler){
            nexthandler->ProcessOrder(order);

    }
    }
};
 

class OrderPreparationHandler : public Orderhandler {
    public : 
    OrderPreparationHandler(Orderhandler * order) : Orderhandler(order) {};
    void ProcessOrder(string order){
        cout<<"Order Preperation :"<<order<<endl;
        if(nexthandler){
            nexthandler->ProcessOrder(order);
        }
    }


};
class OrderDeliveryTrackHandler : public Orderhandler { 
    public : 
    OrderDeliveryTrackHandler(Orderhandler * order) : Orderhandler(order){};
    void ProcessOrder(string order){
        cout<<"Order delivery :"<<order<<endl;
        if(nexthandler){
            nexthandler->ProcessOrder(order);
        }
    }
};
int main(){
    cout<<"Implement chain of responsility"<<endl;
    Orderhandler * order = new OrderValidatingHandler(
        new OrderPaymentHandler(
            new OrderPreparationHandler(
                new OrderDeliveryTrackHandler(nullptr)
            )
        )
    );
    order->ProcessOrder("Butter Paneer");



}