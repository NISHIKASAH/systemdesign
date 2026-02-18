#pragma once 
#include<iostream>
#include "../enum/paymenttype.hpp"
#include "../payment/paymentgateway.hpp"
#include "../payment/paymentgatewayproxy.hpp"

using namespace std;

class PaymentgatewayFactory {
    private : 
    static PaymentgatewayFactory * instance;
    PaymentgatewayFactory(){}
    PaymentgatewayFactory(PaymentGateWay * gateway) = delete;
     PaymentgatewayFactory* operator=(const PaymentgatewayFactory*) = delete;
    public : 
    static PaymentgatewayFactory * getPaymentfactory(){
        if(instance == nullptr){
            instance = new PaymentgatewayFactory();
        }
        return instance;
    }

    PaymentGateWay* createPaymentgateway(PaymentType type){
        if(type == PaymentType ::PAYTM){
            return new PaymentGatewayProxy(new PaytmPaymentGateWay() , 3);
        }
        else {
            return new PaymentGatewayProxy(new RazorPaymentGateWay() ,1);
        }
    }
    

};

PaymentgatewayFactory * PaymentgatewayFactory::instance = nullptr;