#pragma once
#include <iostream>
#include <stdexcept>
#include "../device/outputdevice.hpp"
#include "../enum/deviceType.hpp"
#include "../factories/deviceFactory.hpp"
using namespace std;

class DeviceManager {
    static DeviceManager* deviceInstance;
    OutPutDevice* audioOutputdevice;

    DeviceManager() {
        audioOutputdevice = nullptr;
    }

public:
    static DeviceManager* getDeviceManager() {
        if (deviceInstance == nullptr) {
            deviceInstance = new DeviceManager();
        }
        return deviceInstance;
    }

    void connect(DeviceType devicetype) {
        if (audioOutputdevice) {
            delete audioOutputdevice;
        }
        audioOutputdevice = DeviceFactory::createDevice(devicetype);

        switch (devicetype) {
            case DeviceType::BLUETOOTH:
                cout << "Bluetooth device connected\n";
                break;
            case DeviceType::HEADPHONES:
                cout << "Headphone device connected\n";
                break;
            case DeviceType::WIRED:
                cout << "Wired device connected\n";
                break;
            default:
                cout << "Unknown device type\n";
                break;
        }
    }

    OutPutDevice* getAudioDevice() {
        if (!audioOutputdevice) {
            throw runtime_error("Audio device not connected");
        }
        return audioOutputdevice;
    }

    bool hasAudioDevice() {
        return audioOutputdevice != nullptr;
    }

    ~DeviceManager() {
        delete audioOutputdevice;
    }
};

DeviceManager* DeviceManager::deviceInstance = nullptr;
