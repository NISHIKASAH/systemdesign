#include <bits/stdc++.h>
using namespace std;

/*
Power* power  : 
It does not create a Power object by itself.
You must manually allocate it (power = new Power();) before using.
This is closer to aggregation/association, not strict composition.
Because the object can exist without owning the actual Power.
*/
/*
Power power : 
This creates a Power object directly inside the class.
When the parent object (like Facade) is created, the Power object is also created.
When the parent is destroyed, the Power object is also destroyed.
This is composition , because the lifecycle of Power is tied to Facade.

*/

class Power{
    public : 
    void supplyPower(){
        cout<<"Power supply is on"<<endl;
    }


};
class Cpu {
    public : 
    void initilization () {
        cout<<"Cpu got initlize"<<endl;
    }

};
class Memory {
    public : 
    void memoryCheck(){
        cout<<"memory check done"<<endl;
    }
};
class CoolingFan {
    public : 
    void startFan() {
        cout<<"Start fan"<<endl;
    }

};
class OperatingSystem {
    public : 
    void Load(){
        cout<<"loading has been started"<<endl;
    }
};
class Bios {
    OperatingSystem  os ; 
    Cpu  cpu ;
    public : 
    void BootSystem (){
        cpu.initilization();
        os.Load();
    }

};

class Facade {
    Power power;
    Memory memory ;
    CoolingFan fan ; 
    Bios  bios; 
    public : 

    void startComputer() {
        power.supplyPower();
        memory.memoryCheck();
        fan.startFan();
        bios.BootSystem();

    }
    

};


int main(){
    Facade  facade ;
    facade.startComputer();
}