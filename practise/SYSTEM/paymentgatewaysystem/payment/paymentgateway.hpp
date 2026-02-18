#pragma once
#include <iostream>
#include "./paymentrequest.hpp"
#include "../external/bankingsystem.hpp"
#include "../external/paytmbankingsystem.hpp"
#include "../external/razorbankingsystem.hpp"

using namespace std;

class PaymentGateWay
{
protected:
    BankingSystem *bankingsystem;

    

public:

PaymentGateWay()
    {
        bankingsystem = nullptr;
    }
    virtual ~PaymentGateWay(){
        delete bankingsystem;
    }

    virtual bool validate(PaymentRequest *request) = 0;
    virtual bool initialProcess(PaymentRequest *request) = 0;
    virtual bool confirm(PaymentRequest *request) = 0;
  virtual bool processPayment(PaymentRequest *request)
    {
        if (!validate(request))
        {
            if (!request)
            {
                cout << "\n validation request failed \n";
            }
            return false;
        }
        if (!initialProcess(request))
        {
            if (!request)
            {
                cout << "\n validation request failed \n";
            }
            return false;
        }
        if (!confirm(request))
        {
            if (!request)
            {
                cout << "\n confirmation request failed \n";
            }
            return false;
        }
        return true;
    }
};

class PaytmPaymentGateWay : public PaymentGateWay
{
public:
    PaytmPaymentGateWay()
    {
        bankingsystem = new PaytmBankingSystem();
    }
    bool validate(PaymentRequest *request) override
    {
        cout << "\n validating sender on Paytm :" << request->getSender();
        if (request->getAmount() <= 0 || request->getCurreny() != "INR")
        {
            return false;
        }
        return true;
    }
    bool initialProcess(PaymentRequest *request) override
    {
        cout << "\n initial process start on Paytm" << endl;
        if (request->getAmount() <= 0 || request->getCurreny() != "INR")
        {
            return false;
        }
        return bankingsystem->paymentProcessing(request->getAmount());
    }
    bool confirm(PaymentRequest *request) override  {
        cout<<"\n confirmation payment on Paytm ,amount " <<request->getAmount() <<" transfer to "<<request->getReceiver();
        return true;
    }
};

class RazorPaymentGateWay : public PaymentGateWay
{
public:
    RazorPaymentGateWay()
    {
        bankingsystem = new RazorBankingSystem();
    }
    bool validate(PaymentRequest *request) override
    {
        cout << "\n validating sender on Razorpay :" << request->getSender();
        if (request->getAmount() <= 0 || request->getCurreny() != "INR")
        {
            return false;
        }
        return true;
    }
    bool initialProcess(PaymentRequest *request) override
    {
        cout << "\n initial process start on Razorpay " << endl;
        if (request->getAmount() <= 0 || request->getCurreny() != "INR")
        {
            return false;
        }
        return bankingsystem->paymentProcessing(request->getAmount());
    }
    bool confirm(PaymentRequest *request) override  {
        cout<<"\n confirmation payment  on Razorpay ,amount transfer to "<<request->getReceiver();
        return true;
    }
};