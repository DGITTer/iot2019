#include "mqtt.h"

// MQTT-Client
WiFiClient espClient;
PubSubClient client(espClient);

void MQTT::configure(MQTT_CALLBACK_SIGNATURE)
{
  client.setServer(HIVE_MQ_IP, HIVE_MQ_PORT);
  client.setCallback(callback);
}

void MQTT::checkConnection()
{
  if (!client.connected())
  {
    MQTT::reconnect();
  }

  client.loop();
}

void MQTT::publish(const char *payload)
{
  if (client.connected())
  {
    client.publish(PUBLISH_TOPIC, payload);
  }
}

void MQTT::reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    // Create a random client ID
    String clientId = CLIENT_PREFIX;
    clientId += String(random(0xffff), HEX);

    // Attempt to connect
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
      // ... and resubscribe
      client.subscribe(SUBSCRIBE_TOPIC);
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");

      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}