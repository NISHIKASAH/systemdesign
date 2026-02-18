#include <bits/stdc++.h>
using namespace std;

class IdataService {
    public : 
    virtual void fetchData() = 0;

};

class RealDataService : public IdataService{ 
    string serverData; 
    public : 
    RealDataService(string data){ 
        //creating this operation is heavy , since server might beatremote or loads
        //heavy resources .
        serverData = data ; 
       cout << "[RealDataService] Initialized (simulating remote setup) : "<<serverData;
    }
    void fetchData() override {
        cout<<"heavy data  fetched and loaded"<<serverData<<endl;
        
    }
};

class ProxyDataService : public IdataService {
    string serverdata ;
    RealDataService * realservice; 
    public : 
    ProxyDataService(string data){
        serverdata  = data ; 
        realservice = new RealDataService(serverdata);

    }
    void fetchData() override {
        realservice->fetchData();
      
    }

};
int main(){

    IdataService * service = new ProxyDataService("amzDatacenter");
    service->fetchData();
}