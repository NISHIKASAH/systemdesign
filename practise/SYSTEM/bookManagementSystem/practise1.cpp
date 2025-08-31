#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    string name;
    string author;
    bool isAvailable;

public:
    Book(string nam, string auth)
    {
        this->name = nam;
        this->author = auth;
    }
    void getBookDetails()
    {
        cout << "------Book details -----" << endl;
        cout << "Name : " << this->name;
        cout << "Author : " << this->author;
    }
    void borrowBook()
    {
        if (isAvailable)
        {
            isAvailable = false;
            cout << "Book is Available , you can borrow" << endl;
        }
        else
        {
            cout << "Book not Available" << endl;
        }
    }
    void returnBook()
    {
        isAvailable = true;
        cout << "Book has been returned" << endl;
    }
    bool checkAvailability()
    {
        if (isAvailable)
        {
            return true;
        }
        else
            return false;
    }
};
class Library
{
private:
    vector<Book *> BookList;

public:
    Library() {}
    void addBook(Book *book)
    {
        this->BookList.push_back(book);
        cout<<"new book added"<<endl;
    };
    Book *findBook(Book *book)
    {
        auto idx = find(BookList.begin(), BookList.end(), book);
        if (idx != BookList.end())
        {
            cout << "Book found !" << endl;
            book->getBookDetails();
        }
        else
        {
            cout << "Book not found !" << endl;
        }
    }
    void getBookList()
    {
        cout << "Here is List of All Book Available in Library" << endl;
        for (int i = 0; i < BookList.size(); i++)
        {
            BookList[i]->getBookDetails();
            cout << endl;
        }
    }
};

class Member
{
protected:
    string name;
    string hasRole;

public:
    Member(string nam, string role)
    {
        this->name = nam;
        this->hasRole = role;
    }
    virtual void displayRole()
    {
        cout << "User can be Librarian / Student" << endl;
    }
};

class Librarian : public Member
{
public:
    Librarian(string nam, string rol) : Member(nam, rol) {};
    void addBookToLibrary(Library *lib, Book *book)
    {
        cout << "Issued book Returned" << endl;
        lib->addBook(book);
        
    }
    void displayRole() override { 
        cout<<"I'm a Librarian"<<endl;
    }
    void issueBook(Book *book)
    {
        if (book->checkAvailability())
        {
            cout << "Issue by Librarian" << endl;
        }
        else
        {
            cout << "Book not available" << endl;
        }
    }
};

class Student : public Member {
    public : 
    Student (string nam , string rol) : Member (nam , rol){}
    void borrowBook(Book *book){
        if(book->checkAvailability()){
            cout<<"borrowed book"<<endl;
            book->borrowBook();
           
        }

    }
    void displayRole() override{
        cout<<"I'm a student"<<endl;
    }
    void returnBook(Book *book){
        cout<<"Book Returned"<<endl;
        book->returnBook();

    }

};

int main(){
    cout<<"-------------WelCome! , To my Library-------------"<<endl;
    Book* book1 = new Book("harry potter" , "jk rowling" );
    Book* book2 = new Book("da vanci code" , "xyz" );
    Book* book3 = new Book("sapien" , "narroh samuel" );
    Book* book4 = new Book("naggas" , "amish");


    Library* lib = new Library();
    lib->addBook(book1);
    lib->addBook(book2);
    lib->addBook(book3);
    lib->getBookList();
    lib->findBook(book2);

    Librarian *libp1 = new Librarian("shyam" , "librarian");
    libp1->addBookToLibrary(lib , book4);
    libp1->displayRole();

    Student* st1 = new Student("nish" , "student");
    Student* st2 = new Student("dips" , "student");
    libp1->issueBook(book1);
    st1->borrowBook(book1);
    st1->displayRole();

    st1->returnBook(book1);

    st2->borrowBook(book1);
    


}