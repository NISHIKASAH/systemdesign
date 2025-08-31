#include<bits/stdc++.h>
using namespace std;

class DocumentEditor { 
    vector<string>Editor; 
    string Data;
    public : 
    void addImage(string path) {
        Editor.push_back(path);
        
    }
    void addText(string text){
        Editor.push_back(text);
    }

    string render(){
        if(! Data.empty()) return Data;
          string element  ; 
        for(auto& data : Editor){
          
            if(data.size()>= 4 && (data.substr(data.size() - 4) == ".jpg" )|| (data.substr(data.size() - 4) == ".png" )){
                element += "[Image : " + data.substr(0, data.size()-4) + "]\n" ;


            }
            else{
                element += data + "\n";
            }
        }
        return element;
    }
    void SaveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file<<render();
            file.close();
            cout<<"data save to document successfully"<<endl;
        }
        else{
            cout<<"Unable to open file"<<endl;
        }


    }


};

int main(){
    DocumentEditor * editor = new DocumentEditor();
    editor->addText("hello world");
    editor->addImage("oishcoidihcocc.jpg");
    editor->render();
    editor->SaveToFile();
}