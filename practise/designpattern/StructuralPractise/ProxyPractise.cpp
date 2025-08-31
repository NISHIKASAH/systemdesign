#include <bits/stdc++.h>
using namespace std;

class Hotel
{

    protected :
    string name;
    string location;
    string rooms;

public:
    Hotel(string name, string location, string rooms)
    {
        this->name = name;
        this->location = location;
        this->rooms = rooms;
    }
    virtual ~Hotel(){};
    virtual void booking() = 0;
    virtual void getRoomDetails() = 0;
};

class RealHotel : public Hotel
{
public:
    RealHotel(string name, string location, string rooms) : Hotel(name, location, rooms) {};
    ~RealHotel(){};
    void booking() override
    {
        cout << "Your room is booked" << endl;
    }
    void getRoomDetails()
    {
        cout << "Name : " << name << endl;
        cout << "Location : " << location << endl;
        cout << "Rooms : " << rooms << endl;
    }
};

class ProxyHotel : public Hotel
{
    RealHotel *realhotel = nullptr;

public:
    ProxyHotel(string name, string location, string rooms) : Hotel(name, location, rooms) {};
    ~ProxyHotel(){
        delete realhotel;
    };
     void getRoomDetails()
    {
        cout << "Name : " << name << endl;
        cout << "Location : " << location << endl;
        cout << "Rooms : " << rooms << endl;
    }
    void booking(){
        if(realhotel == nullptr){
            realhotel =new RealHotel(name , location , rooms);
        }
        realhotel->booking();
    }

};

int main(){
    ProxyHotel* proxyHotel  = new ProxyHotel("Natraj" , "Eden Rd" , "105");
    proxyHotel->getRoomDetails();
    proxyHotel->booking();

     proxyHotel->booking();
    

    delete proxyHotel;

}