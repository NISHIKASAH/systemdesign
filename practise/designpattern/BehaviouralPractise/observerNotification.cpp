#include<bits/stdc++.h>
using namespace std;

class Subscribe{
    private :
    string name; 
    public:
    virtual void Update(string videoName) =0;
};
class User : public Subscribe {
    private : 
    string name; 
    public : 
    User(string nam) {
        this->name = nam;
    }
    void Update(string videoName){
            cout<<name<<"  is notified with "<<videoName<<endl;
    }
    
};

class YoutubeChannel {
    
private : 
vector<Subscribe*>SubscriberList;
string videoName ; 
    public:
   void addSubscriber( Subscribe* user){
        this->SubscriberList.push_back(user);
    }
    void UploadVideo(string name){
        this->videoName = name;
        cout<<"Video is uploaded"<<endl;
        NotifyAll();
    }

    void NotifyAll(){
        for(auto it : SubscriberList){
            it->Update(videoName);
        }
    }



};

int main(){
    cout<<"Observer Implementation"<<endl;
    User* user = new User("nishika");
    YoutubeChannel * yt = new YoutubeChannel();
    yt->addSubscriber(user);
    yt->UploadVideo("Japan Vlog Upload");
    yt->NotifyAll();


}