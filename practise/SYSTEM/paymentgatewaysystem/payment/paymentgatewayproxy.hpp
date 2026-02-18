#pragma once
#include <iostream>
#include "../payment/paymentgateway.hpp"
using namespace std;

class PaymentGatewayProxy : public PaymentGateWay
{
private:
    int retries;
    PaymentGateWay *realgatway;

public:
    PaymentGatewayProxy(PaymentGateWay *gateway, int r)
    {
        realgatway = gateway;
        retries = r;
    }
    ~PaymentGatewayProxy()
    {
        delete realgatway;
    }
    bool processPayment(PaymentRequest *request) override
    {
          bool result = false;
        for (int attempt = 0; attempt < retries; ++attempt) {
            if (attempt > 0) {
                cout << "[Proxy] Retrying payment (attempt " << (attempt+1)
                          << ") for " << request->getSender() << ".\n";
            }
            result = realgatway->processPayment(request);
            if (result) break;
        }
        if (!result) {
            cout << "[Proxy] Payment failed after " << (retries)
                      << " attempts for " << request->getSender() << ".\n";
        }
        return result;
       
    }
    bool validate(PaymentRequest *request) override
    {
        return realgatway->validate(request);
    }
    bool initialProcess(PaymentRequest *request) override
    {
        return realgatway->initialProcess(request);
    }
    bool confirm(PaymentRequest *request) override
    {
        return realgatway->confirm(request);
    }
};