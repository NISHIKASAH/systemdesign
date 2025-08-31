#include<bits/stdc++.h>
using namespace std;

class Book{
    private: 
    string name ; 
    string author ; 
    bool isAvailable; 

    public :
    Book(string name , string author , bool status){
        this->name = name ;
        this->author = author ; 
        this->isAvailable = status ;

    }
    bool isBookAvailabe(){
       if(isAvailable){
        return true;
       }
       return false;
    }
    void borrowBook(){
        if(isAvailable){
            cout<<"borrow book"<<endl;
            isAvailable = false;
        }
        else{
            cout<<"book not availabe"<<endl;
        }
    }
   void returnBook(){
       isAvailable = true;
    }
    void getBookDetails(){
        cout<<endl;
        cout<<"-----------Book Details ---------"<<endl;
        cout<<"Book : "<<this->name << " "<<"Author : " <<this->author << " "<<endl;
        cout<<"Available :"<<this->isAvailable<<endl;

    }

};

class Library {
  private : 
    vector<Book*>BookList ; 
    int bookNumber ; 
public : 
Library(){
    this->bookNumber = this->BookList.size();
}

void getBookListDetails(){
    cout<<"------All Books Available---------"<<endl;
    for(int i=0; i<this->BookList.size() ; i++ ){
        cout<<i+1<<"."<<this->BookList[i]<<" "<<endl;
    }
}

void addbook(Book *book){
    this->BookList.push_back(book);
    cout<<"book added to library"<<endl;
}

void findbook(Book *book){
 auto idx = std::find(BookList.begin() , BookList.end() , book);
 if(idx != BookList.end()){
      cout<<"book found! "<<endl;
 }
 else{
     cout<<"book not found !"<<endl;
 }

    
}


};


class Member {
    protected : 
    string name ; 
    string role ; 
    public : 
    Member(string nam , string rol){
        this->name = nam ; 
        this->role = rol ; 

    }
    virtual void displayRole(){
         cout<<"Name : "<<name <<endl;
        cout<<"Role : "<<role<<endl;
    }
}; 


class Student  : public Member {
    public :
    Student(string nam , string rol): Member(nam , rol){
    }
    void displayRole() override {
        cout<<"Name : "<<this->name <<endl;
        cout<<"Role : "<<this->role<<endl;
    }

    void borrowedBook(Book *book){ // passing as pointer
        book->borrowBook();

    }
    void returnedBook(Book *book){ //passing as reference
       book->returnBook();
    }
    

};

class Librarian : public Member {
    public : 
    Librarian(string nam , string rol) : Member(nam , rol){
        
    }
    void displayRole() override{
         cout<<"Name : "<<this->name <<endl;
        cout<<"Role : "<<this->role<<endl;
    }
    
    void addBookToLibrary( Library *lib , Book *book){ 
        lib->addbook(book);
    }
   void issueBook(Book *book){
       if(book->isBookAvailabe()){
           cout<<"Issue book " <<endl;
           
       }
       else{
           cout<<"book  not available"<<endl;
       }
        
    }
};



int main(){
  cout<<"Hey! , welcome to my library"<<endl;
  Book* book1 = new Book("harry potter" , "jk rowling" , true);
  Book* book2 = new Book("da vanci code" , "xyz" , true);
  Book* book3 = new Book("sapien" , "narroh samuel" , true);
  Book* book4 = new Book("naggas" , "amish" , true);
  
  Library* lib = new Library();
  lib->addbook(book1);
  lib->addbook(book2);
  lib->addbook(book3);
  
  
  
  Librarian* libp = new Librarian("shyam singh" , "librarian");
   libp->addBookToLibrary(lib ,book4);
   
   Student* st1 = new Student("nish" ,"student");
      libp->issueBook(book1);
   st1->borrowedBook(book1);
//   st1->returnedBook(book1);


    Student* st2 = new Student("dips" ,"student");
      
       
       lib->findbook(book1);
       
         st2->borrowedBook(book1);
         
   book1->getBookDetails();
    

  
  
  
  
  
}
