#include<bits/stdc++.h>
using namespace std;

class TreeType { 
    string name ; 
    string color ; 
    string texture ;
    public : 
    TreeType(string name ,string color , string texture){
        this->name= name;
        this->color= color;
        this->texture = texture;
    }
    void display(int x , int y){
        
        cout << "Draw " << name << " tree at (" << x << ", " << y 
             << ") with color " << color << " and texture " << texture << endl;
    }
    

};
class TreeFactory {
       unordered_map<string , TreeType*>Types ;
    public : 

   TreeType * getTreeType(string name , string color , string texture){
     string key = name + color + texture ; 
     if(Types.find(key) == Types.end()){
        Types[key] = new TreeType(name , color ,texture);


     }
     return Types[key];

   }

   

};

class Tree {
   
    TreeType * treetype ; 
    int x_plane ; 
    int y_plane ; 
     public : 
    
    Tree(int x , int y ,TreeType * type ){
        this->x_plane =x;
        this->y_plane = y ;
        this->treetype = type;
        
    }
    void displayIndividualTree(){
        treetype->display(x_plane , y_plane);
    }

};

class Forest { 
    vector<Tree*>ListOfTree ; 
    TreeFactory  factory; // this is very imp , passing by value not reference 
    public : 
    
    void plantTree(int x , int y , string name ,string color  , string texture){
         TreeType * type = factory.getTreeType(name , color , texture);
         ListOfTree.push_back(new Tree(x, y , type));
        
    }
    void viewAllTree(){
        for(auto it : ListOfTree){
            it->displayIndividualTree();
        }

    }

};

int main(){
    Forest * forest = new Forest();
    forest->plantTree(0 ,1 ,"oak" , "brown" , "rough" );
      forest->plantTree(1 ,1 ,"pulm" , "pink" , "smooth" );
        forest->plantTree(2 ,1 ,"coconut" , "green" , "smooth" );
    
        forest->viewAllTree();


}

