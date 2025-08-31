#include<bits/stdc++.h>
using namespace std;

/*
Proxy Pattern:
- This pattern provides a surrogate or placeholder for another object to control access to it.
- Acts as an interface between the client and the real object.
- Useful for lazy loading, access control, logging, or caching.
*/
class Video{
    protected : 
    string title; 
    public:
    Video(string t){
        this->title = t;
    }
    virtual void getMetaData() = 0;
    virtual void Play() = 0;
    
};

class RealVideo : public Video {
    public : 
    RealVideo(string title) : Video(title){};
    void getMetaData() override {
      cout << "Metadata: Video title is " << title << endl;
    }
    void Play() override {
        cout<<"Streaming Movie : "<<title<<endl;
    }
    
};

class ProxyVideo : public Video {
    RealVideo * realvideo  = nullptr ; 
    public : 
    ProxyVideo(string title) : Video(title){};
    void getMetaData() override {
        cout << "Metadata of : " << title << endl;
    }
    void Play() override {
        if(realvideo == nullptr){
            realvideo = new RealVideo(title); // lazy loading / on demand creation 
        }
        realvideo->Play(); // access controll of class RealVideo 
    }
    
};

int main(){
    ProxyVideo * proxy = new ProxyVideo("Saiyaara");

    proxy->getMetaData();
    proxy->Play();




}



