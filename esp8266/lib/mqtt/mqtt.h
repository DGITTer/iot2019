// MQTT.h
#ifndef MQTT_H
#define MQTT_H

#include <WiFiManager.h>
#include <PubSubClient.h>

#define HIVE_MQ_IP "10.0.1.48"
#define HIVE_MQ_PORT 1883
#define SUBSCRIBE_TOPIC "/nfctest123"
#define PUBLISH_TOPIC "/lampe21Status"
#define CLIENT_PREFIX "ESP8266Client-"

class MQTT {
public:
    static void configure(MQTT_CALLBACK_SIGNATURE);
    static void checkConnection();
    static void publish(const char* payload);
private:
    static void reconnect();
};

#endif