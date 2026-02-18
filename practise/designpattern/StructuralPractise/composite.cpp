#include<bits/stdc++.h>
using namespace std;
/*
Composite patterns : in a herirachy ,keeping object as individual or group of object.
considering both use the same interface 
i.e file and folder object using same interface 
note : composite override interface func and call same function for indivual obj
*/
class Document {
    public : 
    virtual void  getDetails() = 0;
};
class File : public Document {
    string name ;
    public : 
    File(string n){
        this->name = n;
    }
    void getDetails() override {
        cout<<"File :"<<this->name<<endl;
    }

};
class Folder : public Document {
    string name ; 
    vector<Document*>folderList; // refer to other folder / files i.e y Document not File
    public : 
    Folder(string n ) : name(n){};
    void addFileToFolder(Document * doc){
        
        folderList.push_back(doc);

    }
    void getDetails() override {
        for(auto &it : folderList){ // this print only subordinate object 
            it->getDetails();
        }
    }
};
int main(){
    File * file1 = new File("identification paper");
    File * file2 = new File("marksheet ");
    Folder * folder = new Folder("college document");
    folder->addFileToFolder(file1);
    folder->addFileToFolder(file2);

    folder->getDetails();

}
















#include<bits/stdc++.h>
using namespace std;

class Worker {
    public :
   virtual void getDescription() =0 ;

};
class Employees : public Worker  {
    string designation ;
    public :
    Employees(string s){
        this->designation =s;
    }
    void getDescription() override {
        cout<<"designation :"<<this->designation;
    }
    
};
class Manager : public Worker {
    string designation;
    vector<Worker*>workerList;
    public : 
    Manager(string s) :designation(s){};
    void addWorker(Worker * w)  {
        workerList.push_back(w);

    }
    void getDescription() override{
        for(auto &it :  workerList){
            it->getDescription();
        }
    }


};

int main(){

    Worker * w1 = new Employees("worker");
    Worker *m1 = new Manager("manager");

    Manager * superior = new Manager("managerHead");
    superior->addWorker(m1);
    superior->addWorker(w1);
    superior->getDescription();


}