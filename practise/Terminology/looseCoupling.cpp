
#include<bits/stdc++.h>
using namespace std;

// Classes depend on abstractions (interfaces), not concrete implementations.
// Easier to extend, modify, and test.
// Promotes flexibility and reusability.

class IEngine {
public:
    virtual void start() = 0;
    virtual ~IEngine() {}
};

class PetrolEngine : public IEngine {
public:
    void start() override {
        cout << "Petrol engine started\n";
    }
};

class ElectricEngine : public IEngine {
public:
    void start() override {
        cout << "Electric engine started\n";
    }
};

class Car {
    IEngine* engine;  // Depend on abstraction
public:
    Car(IEngine* e) : engine(e) {}
    void run() {
        engine->start();
        cout << "Car is running\n";
    }
};

int main() {
    PetrolEngine pe;
    ElectricEngine ee;

    Car car1(&pe);  // Inject PetrolEngine
    car1.run();

    Car car2(&ee);  // Inject ElectricEngine
    car2.run();
}
