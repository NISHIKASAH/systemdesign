#pragma once 
#include <iostream>
#include "../enum/deviceType.hpp"
#include "../device/bluetoothadapter.hpp"
#include "../device/headphoneadapter.hpp"
#include "../device/wireadapter.hpp"
#include "../device/outputdevice.hpp"
#include "../external/BluetoothApi.hpp"

using namespace std;

class DeviceFactory
{
public:
   static OutPutDevice *createDevice(DeviceType devicetype)
    {
        if (devicetype == DeviceType ::BLUETOOTH)
        {
            return new BlueToothDevice(new BlueToothApi());
        }
        else if (devicetype == DeviceType ::HEADPHONES)
        {
            return new HeadPhoneDevice(new HeadPhoneApi());
        }
        else
        {
            return new WiredDevice(new WiredApi());
        }
    }
};