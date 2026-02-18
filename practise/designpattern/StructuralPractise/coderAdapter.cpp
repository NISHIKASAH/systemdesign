#include <bits/stdc++.h>
using namespace std;

class IJsonReportProvider { 
    public : 
    virtual string getJsonReport(string data) = 0;
};

class IXmlReportProvider {
    public : 
    virtual string getXmlReport(string data) = 0;
};

class XmlReportProvider : public IXmlReportProvider {
    public : 
    string getXmlReport(string data) override {
        int idx = data.find(":");
        string name = data.substr(0 , idx);
        string id = data.substr(idx+1);
        return "<user>"
               "<name>" + name + "</name>"
               "<id>"   + id   + "</id>"
               "</user>";
    }
};
class Adapter : public IJsonReportProvider {
    IXmlReportProvider * xmlprovider; 
    public : 
    Adapter(IXmlReportProvider *xml ) {
        xmlprovider  = xml;

    }
    string getJsonReport(string rawdata) override {
       string data =  xmlprovider->getXmlReport(rawdata);

       int startnameidx = data.find("<name>") + 6 ;
       int endnameidx = data.find("</name>");
       string name = data.substr(startnameidx , endnameidx - startnameidx);

       int startidx = data.find("<id>") + 4;
       int endidx = data.find("</id>");
       string id = data.substr(startidx , endidx - startidx);

      return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }

};

class Client {
    public : 
    string getreport(IJsonReportProvider * adapter , string rawdata){
       return adapter->getJsonReport(rawdata);

    }

};

int main(){
    IXmlReportProvider * xmlprovider = new XmlReportProvider();
    IJsonReportProvider * adapter = new Adapter(xmlprovider);

    string rawdata = "Nisika:34";
    Client * client = new Client();
   string ans =  client->getreport(adapter , rawdata);
   cout<<"string : "<<ans<<endl;


}