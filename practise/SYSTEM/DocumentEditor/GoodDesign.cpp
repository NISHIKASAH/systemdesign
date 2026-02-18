#include<bits/stdc++.h>
using namespace std;

class DocumentElement {
    public : 
    virtual string render() = 0;


};
class TextElement : public DocumentElement {
        private: 
    string text;
    public : 
    TextElement(string str){
        text= str;
    }
    string render() override { 
        return text;
    }


};
class ImageElement : public DocumentElement {
    string imagePath ;
    public : 
    ImageElement(string str){
        imagePath = str;
    }
    string render(){
         imagePath = "[" + imagePath + "]  " ;
        return imagePath;
    }


};
class TabSpaceElement : public DocumentElement {

    public : 

    string render(){
        return "\t";
    }
   

};
class BreakLineElement : public DocumentElement { 
    public : 
       string render(){
        return "\n";
    }


};
class Document {
    vector<DocumentElement*>EditorBoard ; 
    string AllInformation ;
    public : 

    void addElement(DocumentElement * element) {
        EditorBoard.push_back(element);
    }
    string getAllDocument(){
        if(!AllInformation.empty()) return AllInformation;
        for(auto& data : EditorBoard){
           AllInformation  = AllInformation  +  data->render() ;
           
        }
       return AllInformation;
    }

};
class Persistance { 
    public : 
    virtual  void Save(string ) =0;
};
class Mongodb  : public Persistance {

    public : 
    void Save(string editorData){
       cout<<"Save data to mongodb";
    
    }

};
class File  : public Persistance {

    public : 
    void Save(string editorData){
        ofstream file("xyz.txt");
        if(file.is_open()){
            file<<editorData;
            file.close();
            cout<<"Data save to File";
        }
        else{
            cout<<"failed to save data to File ";
        }
    
    }
    
};
class DocumentEditor {
    public : 
    Document * document;
    Persistance * persistance;
    string AllRenderDoc; 
    DocumentEditor(Document * doc , Persistance * per){
        document  = doc;
        persistance = per;
    }
    
    void addText(string elem ){
        document->addElement(new TextElement(elem));

    }
    void addImages(string path){
        document->addElement(new ImageElement(path));
    }
    void addBreakLine(){
        document->addElement(new BreakLineElement());
    }
    void tabspace(){
        document->addElement(new TabSpaceElement());
    }
    string renderAllEditorElem(){
        if(AllRenderDoc.empty()){
            AllRenderDoc = document->getAllDocument();
        }
        return AllRenderDoc;

    }
    void save(){
        persistance->Save(AllRenderDoc);
    }

};

int main(){
    Document * doc =  new Document();
    Persistance * per = new File();
    DocumentEditor * editor = new DocumentEditor(doc , per);
    editor->addImages("gadha akash ka photo h.png");
    editor->addBreakLine();
    editor->addText("Akash Sah");
    // editor->tabspace();
    editor->addText("Budhu nakayak ladka ");
    // editor->addBreakLine();
    editor->addText("sdkjhxksdjckjc");
    string elem = editor->renderAllEditorElem();

    per->Save(elem);
}
