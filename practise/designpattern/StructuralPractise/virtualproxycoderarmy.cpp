#include <bits/stdc++.h>
using namespace std;


class Iimage {
    public :
    virtual void display() =0 ;

};
class RealImage : public Iimage {
    private : 
    string data ; 
    public : 
    RealImage(string path){
        data = path;
    }

    void display(){
        cout<<"data to be displayed : " <<data<<endl;
    }

};

class ProxyVirtualImage : public Iimage {
    RealImage * realimg;
    string data; 
    public : 
    ProxyVirtualImage(string datapath){
        realimg = nullptr;
        data = datapath ;
    }
    void display () override {
        if(realimg == nullptr){
            realimg = new RealImage(data);
        }
        realimg->display();
        
    }
};

int main (){
    Iimage * img = new ProxyVirtualImage("data/xyz.txt");
    img->display();
}