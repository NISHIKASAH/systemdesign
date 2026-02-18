#include<iostream>
#include<map>
using namespace std;

class HttpRequest {
    private : 
    map<string,string>queryParameters;
    map<string, string>Headers;
    string body;
    string url ; 

    HttpRequest(){};

    public : 

   friend class HttpRequestBuilder;
    void execute(){
        if(!url.empty()){
            cout<<"url = "<<url<<endl;

        }
        if(!body.empty()){
            cout<<"body = "<<body<<endl;
        }
        if(!queryParameters.empty()){
            cout<<"queryparameter : "<<endl;
            for(auto it : queryParameters){
                cout<<"Type ="<<it.first<<" "<<"Value ="<<it.second<<endl;
            }
        }
        if(!Headers.empty()){
            cout<<"Headers : "<<endl;
            for(auto it : Headers){
                cout<<"Type ="<<it.first<<" "<<"Value ="<<it.second<<endl;
            }
        }

    }
};

class HttpRequestBuilder {
    HttpRequest request ;
    public : 
    HttpRequestBuilder& withUrl(string urlstring) {
        request.url = urlstring;
        return *this;


    }
     HttpRequestBuilder& withBody(string bodystring) {
        request.body = bodystring;
        return *this;


    }
    HttpRequestBuilder& withHeader (string type  , string headername){
        request.Headers[type] = headername;
        return  *this;
    }
    HttpRequestBuilder& withQueryparamater(string querytype, string queryname){
        request.queryParameters[querytype] = queryname;
        return  *this;
    }
    HttpRequest  build (){
        if(request.body.empty()){
            cout<<"No body present"<<endl;
        }
        if(request.url.empty()){
            cout<<"No url present"<<endl;
        }
        if(request.queryParameters.empty()){
            cout<<"No queryParameters present"<<endl;
        }
        if(request.Headers.empty()){
            cout<<"No header present"<<endl;
        }
        return request;
    }



};

int main(){
    HttpRequest http= HttpRequestBuilder()
    .withUrl("https://www.google.com")
    .withBody("sending user details")
    .withHeader("content-type" , "application/json")
    .withQueryparamater("key" , "123456")
    .build();

    http.execute();
    
}