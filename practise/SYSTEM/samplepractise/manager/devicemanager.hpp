#pragma once
#include <iostream>
#include "../factory/outputdevice.hpp"
#include "../factory/createconnection.hpp"
#include "../enum/deviceType.hpp"
using namespace std;

class DeviceManager
{
    ConnectonFactory *factory;
    static DeviceManager *instance;
    Outputdevice * currentdevice;

    DeviceManager() {
currentdevice = nullptr;
    };

public:
    static DeviceManager *getdeviceinstance()
    {
        if (instance == nullptr)
        {
            instance = new DeviceManager();
        }
        return instance;
    }

    Outputdevice *connect(deviceType type)
    {
        factory = new ConnectonFactory();
    currentdevice =    factory->createconnection(type);
        if (type == deviceType ::BLUETOOTH)
        {
            cout << "bluetooth connected successfully" << endl;
        }
        else if (type == deviceType ::SPEAKER)
        {
            cout << "speaker connected  successfully" << endl;
        }
        return currentdevice;
    }
    Outputdevice * getoutputdevice(){
        return currentdevice;
    }
};

DeviceManager *DeviceManager ::instance = nullptr;