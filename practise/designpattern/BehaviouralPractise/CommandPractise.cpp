#include<bits/stdc++.h>
using namespace std;
stack<Command*>History ; 

class Command { 
    public : 
    virtual  void execute() = 0;
    virtual  void  undo() =0 ;

};

class TextEditor { 
    public : 
    string  elem ; 
   void writeText(){
        cout<<" Writing Text "<<endl;
    }
    void clearText(){
        cout<<"Clear Text "<<endl;
    }
    void undoText(){
       cout<<'msg has been undo';
    }

};
class WritingCommand : public Command {
    TextEditor *editor ; 
    public:
    WritingCommand(TextEditor * editor){
        this->editor = editor;
    }
    void execute() override {
        editor->writeText();
    }
    void undo() override {
      editor->undoText();
    }
    
};

class ClearCommand : public Command {
    TextEditor *editor ; 

   
    public : 
     ClearCommand(TextEditor * editor){
        this->editor = editor;
    }
    void execute() override {
        editor->clearText();
    }
    
     void undo() override {
      editor->undoText();
    }

};

class DeviceControl {
    Command * command;

     public : 
     void SetCommand(Command * cmd ){
        this->command = cmd;
        
     }
     void pressButton(){
        this->command->execute();
     }
    void pressUndo(){
        while(!History.empty()){
            Command * topCommand  = History.top();
            History.pop();
            topCommand->undo();
        }
       
     }


};



int main(){

    TextEditor * editor = new TextEditor();

    Command * writeCmd = new WritingCommand(editor);

    DeviceControl * control = new DeviceControl();

    control->SetCommand(writeCmd);
    control->pressButton();


   Command * UndoCmd = new ClearCommand(editor);

   control->SetCommand(UndoCmd);
   control->pressButton();



}