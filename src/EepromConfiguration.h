#ifndef EEPROMCONFIGURATION_H_
#define EEPROMCONFIGURATION_H_

#include <EEPROM.h>
#include "HardwareSerial.h"

struct Configuration
{
    char ssid[32]; // WLAN ssid
    char password[32]; // WLAN password
    char identifier[32]; // Identifier of board
    int sleepInterval; // Deep Sleep interval (Minutes)
    char otaUrl[32]; // Url to download Over-the-Air firmware updates
    int otaUpdateInterval; // Interval of checking for ota updates (hours)
    char thingspeakApiKey[17]; // API Key for Thingspeak.com
};

class EepromConfiguration
{
    private:
        int eeStartAddress = 0;
        int eeSize = 512;

    public:
        EepromConfiguration();

        // Checks if EEPROM is empty ro not.
        bool isEepromEmpty();

	    // Erase data in EEPROM
        void eraseEeprom();

        // Creates and returns valid default configuration
        Configuration createDefaultConfiguration();

        // Reads and returns the configuration from EEPROM.
        Configuration readConfigurationFromEeprom();

        // Writes the configuration to EEPROM.
        void writeConfigurationToEeprom(Configuration config);
};

#endif
