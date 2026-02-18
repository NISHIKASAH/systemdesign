#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<typename T>
class Iterator {
    public: 
    virtual bool hasNext() = 0 ;
    virtual T next() = 0;
};

template<typename T>
class Iterable {
    public :
    virtual Iterator<T>* getIterator() = 0;
};

class LinkedList : public Iterable<int> {
    public:
    int data;
     LinkedList* nextnode ; 
   
    LinkedList(int val){
        data = val;
        nextnode = nullptr;
    } 
    Iterator<int>*getIterator() override ;

};
class BinaryTree : public Iterable<int>{
    public:
    int data;
    BinaryTree * left;
    BinaryTree * right;

    BinaryTree(int val){
        data = val;
        left = nullptr;
        right = nullptr;

    }
    Iterator<int>*getIterator() override;
    
};

class Song {
    public:
    string title;
    string artist ;
    Song(string t, string a){
        title = t;
        artist = a;
    }

};

class PlayList : public Iterable<Song>{ 
    vector<Song>songList;

    public: 
    void addSong(Song song){
       songList.push_back(song);

    }
    Iterator<Song>*getIterator() override;
};

class LinkedListIterator : public Iterator<int>{
    LinkedList * currentlist;
    public : 
    LinkedListIterator(LinkedList * list){
        currentlist = list;
    }
    bool hasNext() override {
        return currentlist != nullptr;
    }
    int next()override {
        int val  = currentlist->data;
        currentlist = currentlist->nextnode;
        return val;
    } 
};

class BinaryTreeIterator : public Iterator<int>{
public:
    BinaryTree * btree;
    stack<BinaryTree*>st;
    void pushLeft(BinaryTree * root){
        while( root){

            st.push(root);
            root= root->left;
        }

    }
    BinaryTreeIterator(BinaryTree * tree){
        btree = tree;
        pushLeft(tree);


    }
    bool hasNext()  override {
        return !st.empty();
    }
    int next() override {
        BinaryTree * currentTree= st.top();
        int val = currentTree->data;
        st.pop();

        if(currentTree->right){
            st.push(currentTree->right);
        }

        return val;
    }

};

class PlayListIterator  : public Iterator<Song>{
    vector<Song>currentList;
    int idx ;
    public:
    
    PlayListIterator(vector<Song>v){
        idx = 0;
        currentList = v;
    }

    bool hasNext() override {
        return idx < currentList.size();
    }
    Song next() override {
        return currentList[idx++];
        
    }

};

Iterator<int>* LinkedList ::getIterator() {
    return new LinkedListIterator(this);
}
Iterator<int>*BinaryTree ::getIterator(){
    return new BinaryTreeIterator(this);

}

Iterator<Song>*PlayList ::getIterator(){
    return  new PlayListIterator(songList);
}

int main(){

    BinaryTree * tree = new BinaryTree(1);
    tree->left = new BinaryTree(2);
    tree->left->left = new BinaryTree(3);
    tree->left->right = new BinaryTree(4);

   Iterator<int>*rootnode =  tree->getIterator();
   while(rootnode->hasNext()){
    cout<<rootnode->next()<<" "<<endl;
   }

   
    
    cout<<"\n----------------\n"<<endl;
    LinkedList * list = new LinkedList(10);
    list->nextnode = new LinkedList(20);
    list->nextnode->nextnode = new LinkedList(30);

    Iterator<int>*head = list->getIterator();
    while(head->hasNext()){
        cout<<head->next()<<" "<<endl;
    }

  cout<<"\n----------------\n"<<endl;
    PlayList * playlist = new PlayList();

    playlist->addSong(Song("tum hi ho" , "arijit singh"));
     playlist->addSong(Song("keshariya" , "pritam"));
      playlist->addSong(Song("pehali dafa" , "atif"));

      Iterator<Song>*elem = playlist->getIterator();
      while(elem->hasNext()){
        Song s = elem->next();
        cout<<s.title<<" "<<s.artist<<endl;
      }






}
