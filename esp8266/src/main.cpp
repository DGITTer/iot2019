#include "WiFi.h"
#include "MQTT.h"
#include "LCD.h"

int previousButtonState = 1;

String convertBytePtrToString(byte* bytes, unsigned int length)
{
  // 0453446A643481
  String s = "Tag not recognized!";

  if (length >= 7) {
    s = String((char*)bytes).substring(0, 14);
  }

  return s;
}

void callback(char *topic, byte *payload, unsigned int length)
{
  String message = convertBytePtrToString(payload, length);
  Serial.println(message);
  LCD::print(message);
}

void checkButton()
{
  int state = digitalRead(D2);

  if (state == 0 && previousButtonState == 1)
  {
    MQTT::publish("TOGGLE");
  }

  previousButtonState = state;
}

void setup()
{
  Serial.begin(115200);
  Serial.println();

  pinMode(D2, INPUT);

  WiFi::configure();
  LCD::configure();
  MQTT::configure(callback);
}

void loop()
{
  MQTT::checkConnection();
  checkButton();
  delay(250);
}
