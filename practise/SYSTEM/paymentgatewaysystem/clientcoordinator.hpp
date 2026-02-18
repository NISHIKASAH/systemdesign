#pragma once
#include <iostream>
#include "./factories/paymentgatewayfactory.hpp"
#include "./manager/paymentgatewaymanager.hpp"
using namespace std;

class Clientcoordinator
{

   static  Clientcoordinator *controllerinstance;
    Clientcoordinator() {};
    Clientcoordinator (Clientcoordinator * controller) = delete;
    Clientcoordinator * operator = ( const Clientcoordinator*) = delete ; 

public:
    static Clientcoordinator *getCoordinatorinstance()
    {
        if (controllerinstance == nullptr)
        {
            controllerinstance = new Clientcoordinator();
        }
        return controllerinstance;
    }

    void gatewayforPaymentProcessing(PaymentRequest *req, PaymentType type)
    {
        PaymentgatewayFactory *factory = PaymentgatewayFactory ::getPaymentfactory();
        PaymentGateWay *paytm = factory->createPaymentgateway(type);

        PaymentgateManager *manager = PaymentgateManager ::getManagerInstance();
        manager->setPaymentgateway(paytm);

        paytm->processPayment(req);
    }
};
Clientcoordinator * Clientcoordinator :: controllerinstance = nullptr;
