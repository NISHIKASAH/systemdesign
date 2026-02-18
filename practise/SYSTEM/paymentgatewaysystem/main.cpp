#include<iostream>
#include <ctime>
#include "./clientcoordinator.hpp"
#include "./payment/paymentgateway.hpp"
#include "./enum/paymenttype.hpp"
using namespace std;

int main(){

    srand(static_cast<unsigned>(time(0)));
    Clientcoordinator*client =  Clientcoordinator ::getCoordinatorinstance();
   PaymentRequest * paymentRequest  = new PaymentRequest("nishika" , "dolly" , "INR",2400 );
    client->gatewayforPaymentProcessing(paymentRequest , PaymentType ::PAYTM);


}