#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>
using namespace std;

class FilesystemItem { 
    public : 
    virtual string getName() = 0 ;
    virtual int getSize()= 0 ;
    virtual void ls( int intent=0)=0;
    virtual FilesystemItem* cd (string target) =0 ;
    virtual void openAll(int intent=0) = 0;
    virtual bool isFolder() =0;

    

};

class File : public FilesystemItem  {
    string name;
    int size;
    public :
    File(string nam){
    name=  nam;
    size = 0;
    }

    string getName(){
        return name;
    }
    int getSize() {
        return size;
    }
     void ls( int intent=0){
        cout<<string(intent, ' ')<<name<<endl;
     }
    FilesystemItem* cd (string target) {
        nullptr;
    }
    void openAll(int intent=0){
        cout<<string(intent, ' ')<<name<<endl;
    }
    bool isFolder(){
        return false;
    }





};

class Folder : public FilesystemItem{ 
    vector<FilesystemItem*>folders;
    string name;
    public : 
    Folder(string nam){
        name= nam;
    }
    void addItems(FilesystemItem * item){
        folders.push_back(item);
    }

    string getName() {
        return name;
    }
    int getSize() { 
        int total =0 ;
        for(auto child : folders){
            total += child->getSize();
        }
        return total;
    }
    void ls( int intent=0){
        for(auto child : folders){
            if(child->isFolder()){
                cout<<string(intent, ' ')<<"+ "<<child->getName()<<endl;
            }
            else{
                cout<<string(intent, ' ')<<child->getName() <<endl;
            }
        }
    }
    FilesystemItem* cd (string target){
        for(auto child : folders){
            if(child->isFolder() &&  child->getName() == target){
                return child;
            }
        }
        return nullptr; 
    }
    void openAll(int intent=0) { 
        cout<<string(intent, ' ') <<"+ "<<name<<endl;
        for(auto child : folders){
            child->openAll(intent+4);
        }
    }
    bool isFolder(){
        return true;
    }
    


};

int main(){
    File * file1 = new File("sample1.txt");
    File * file2 = new File("sample2.txt");
    File * file3 = new File("sample3.txt");

    Folder * folder1 = new Folder("samplepapers");
     Folder * folder2 = new Folder("recording");
      Folder * Mainfolder = new Folder("MainFolder");

     

    File * file4 = new File("sample4.txt");
    File * file5 = new File("sample5.txt");

     folder2->addItems(file4);
     folder2->addItems(file5);

    folder1->addItems(file1);
      folder1->addItems(file2);
        folder1->addItems(file3);
       
        Mainfolder->addItems(folder1);
        Mainfolder->addItems(folder2);

        Mainfolder->ls();
        Mainfolder->openAll();
            
    
}