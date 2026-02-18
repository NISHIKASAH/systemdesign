#pragma once
#include<iostream>
#include<string>
using namespace std;

class PaymentRequest {
    private : 
    string sender;
    string receiver ;
    string currenyName;
    double amount ;

    public:
    PaymentRequest(string s , string r , string c , int a){
        sender = s;
        receiver = r;
        currenyName = c;
        amount = a;
    }
    void setSender(string s){
        sender = s;
    }
    string getSender(){
        return sender;
    }
  void setReceiver(string r){
        receiver = r;
    }
    string getReceiver(){
        return receiver;
    }
      void setCurrency(string c){
        currenyName = c;
    }
    string getCurreny(){
        return currenyName;
    }
  void setAmount(int a){
       amount =a;
    }
    int getAmount(){
        return amount;
    }

};