#include <bits/stdc++.h>
using namespace std;

class Vehcile
{
public:
    string name;
    Vehcile(string name)
    {
        this->name = name;
    }
    virtual void travel(int amount) = 0;
};

class Bus : public Vehcile
{
public:
    Bus(string name) : Vehcile(name)
    {
    }
    void travel(int amount) override
    {
        cout << "Travel cost by bus : " << amount;
    }
};

class Train : public Vehcile
{
public:
    Train(string name) : Vehcile(name)
    {
    }
    void travel(int amount) override
    {
        cout << "Travel cost by Train : " << amount;
    }
};

class Car : public Vehcile
{
public:
    Car(string name) : Vehcile(name)
    {
    }
    void travel(int amount) override
    {
        cout << "Travel cost by Car : " << amount;
    }
};

class TravelStrategy
{

    Vehcile *vehcileType;

public:
    TravelStrategy(Vehcile *type)
    {
        this->vehcileType = type;
    }

    void generateTravelCost(int amount)
    {
        vehcileType->travel(amount);
    }
};

int main()
{
    Vehcile *car = new Car("car");
    TravelStrategy *t1 = new TravelStrategy(car);
    t1->generateTravelCost(200);

    Vehcile *bus = new Bus("bus");
    TravelStrategy *t2 = new TravelStrategy(bus);
    t2->generateTravelCost(50);
}