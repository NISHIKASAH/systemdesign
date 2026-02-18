#include<bits/stdc++.h>
using namespace std;

/*
Command just perform the action , 
a controller  ,set the command and invoke the action
*/
class Command { 
    public : 
    virtual void execute() = 0;
};
class Printer {
    public :

     void Scanning(){
        cout<<"Scanning done"<<endl;
    } 
    void printing(){
        cout<<"Printing done"<<endl;
    }
   

};

class ScanningCommand : public Command { 
    Printer * printer;
    public : 
    ScanningCommand(Printer * p){
        
        this->printer = p;
    }
    void execute() override {
        printer->Scanning();
    }

};
class PrintingCommand : public Command { 
    Printer * printer ; 
    public : 
    PrintingCommand(Printer * p){
        this->printer = p;
    }
    void execute() override {
        printer->printing();
    }
};

class DeviceControl {
    Command * cmd ;
    public : 
    void SetCommand(Command * c){
        this->cmd =c ;

    }
    void pressButton(){
        this->cmd->execute();
    }

};


int main(){
    cout<<"Command Behavioual implementation"<<endl;

    Printer * printer = new Printer();

    ScanningCommand * scanningcmd = new ScanningCommand(printer);
    PrintingCommand * printingcmd = new PrintingCommand(printer);

    DeviceControl * button1 = new DeviceControl();
    button1->SetCommand(scanningcmd);
     DeviceControl * button2 = new DeviceControl();
    button2->SetCommand(printingcmd);
    
    button1->pressButton();
    button2->pressButton();



}