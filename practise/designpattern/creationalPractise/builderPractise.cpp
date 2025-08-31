#include<bits/stdc++.h>
using namespace std;

class Desktop {
    private : 
    string storage ; 
    string motherboard;
    string speaker ; 
    string processor ; 

    public  : 
    void setStorage(string s ){
        this->storage = s; 
        
    }
    void setSpeaker(string s){
        this->speaker  = s;
    
    }
    void setProcessor(string p ){
        this->processor = p;
      
    }
    void setMotherboard(string m){
        this->motherboard = m ;
        
    }
    void getFeatures(){
        
        cout << "Desktop Feature :\n";
        cout << "Processor : " << processor << "\n";
        cout << "Motherboard : " <<motherboard << "\n";
        cout << "Storage : " << storage << "\n";
        cout << "Speaker : " << speaker << "\n";
    
    }

};

class DesktopBuilder {
    protected : 
    Desktop * desktop ; 
    public : 
    DesktopBuilder(Desktop * desktop){
        this->desktop  = desktop ; 
    };
    virtual void BuildStorage() =0;
    virtual  void  BuildProcessor() = 0;
    virtual void BuildMotherBoard() =0;
    virtual void BuildSpeaker() = 0;
    Desktop * getDesktop(){
        return desktop;
    }
};
class GamingDesktopBuilder  : public DesktopBuilder {
    public : 
    GamingDesktopBuilder(Desktop * desktop) : DesktopBuilder(desktop){};

    void BuildStorage() override {
        desktop->setStorage("23GB");
    }
    void BuildProcessor() override {
        desktop->setProcessor("1 Terabytes");
    }
    void BuildMotherBoard() override {
        desktop->setMotherboard("2GB processor ");
    }
    void BuildSpeaker() override { 
        desktop->setSpeaker("16Mps");
    }
   
};

class DesktopDirectory {
    DesktopBuilder  * builder ; 
    public : 
    DesktopDirectory(DesktopBuilder * builder) {
        this->builder = builder;
    }
    Desktop * Build (){
        builder->BuildMotherBoard();
        builder->BuildProcessor();
        builder->BuildSpeaker();
        builder->BuildStorage();
        return builder->getDesktop();

    }
};

int main(){
    cout<<"Builder pattern implementation"<<endl;
    Desktop * desktop = new Desktop();

    GamingDesktopBuilder * gammingDesktop = new GamingDesktopBuilder(desktop);

    DesktopDirectory * director = new DesktopDirectory(gammingDesktop);
    Desktop * finishDesktop = director->Build();
    finishDesktop->getFeatures();
}