#include<bits/stdc++.h>
using namespace std;

/*
 We are storing the actual value of the state, NOT a reference to it.
- This ensures that even if the editor's content changes later,
  our saved Memento remains unchanged.
- This makes it possible to reliably "undo" changes by restoring
  to a previous snapshot without affecting other saved states. 
 */

class Memento {
    string content ;
    public : 
    Memento(string content){
        this->content = content;
    }
    string getState(){
        return this->content;
    }
};
class TextEditor {
    string content ; 
    public : 
    void type(string word ){
        content += word + " ";
    }
    void show(){
        cout<<content<<endl;
    }
    void restore(Memento * memento){
        content = memento->getState();
    }
    Memento * save (){
        return new Memento(content);
    }
};
class SnapShotHistory {
    vector<Memento*>history;
    public : 
    void saveState(Memento * memento){
        history.push_back(memento);
    }
    Memento * restoreState(int idx ){
       if(idx< history.size()){
            return history[idx];
        }
        return nullptr;
    }
};
int main(){
    TextEditor * editor =  new TextEditor();
    editor->type("hello ji");
    Memento * state =  editor->save();
    SnapShotHistory * history = new SnapShotHistory();
    history->saveState(state);


     editor->type("Good morning");
    Memento * state2 =  editor->save();
      history->saveState(state2);


         editor->type("Have a good day!");
    Memento * state3 =  editor->save();
    history->saveState(state3);


    editor->restore(history->restoreState(2));
    editor->show();

}