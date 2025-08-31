#include<bits/stdc++.h>
using namespace std;

// Classes or modules depend directly on each other.
// If one class changes, the other may break.
// Difficult to reuse or test.

class Engine {
public:
    void start() {
        cout << "Engine started\n";
    }
};

class Car {
    Engine engine;  // Direct dependency (tight coupling)
public:
    void run() {
        engine.start(); // this break  , if engine classis changed 
        cout << "Car is running\n";
    }
};

int main() {
    Car c;
    c.run();
}




