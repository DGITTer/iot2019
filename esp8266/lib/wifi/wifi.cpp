#include "wifi.h"

// Provides access point and web interface in case of new wlan configuration
WiFiManager wifiManager;

void WiFi::configure()
{
    wifiManager.autoConnect(DEFAULT_SSID);
}