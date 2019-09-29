import time
import nxppy
import paho.mqtt.client as mqtt

mifare = nxppy.Mifare()

mqttsender = mqtt.Client('clientid123')
mqttsender.connect("localhost", 1883)
mqttsender.subscribe("/nfctest123")

while True:
   try:
      uid = mifare.select()
      print(mqttsender.publish("/nfctest123", uid))
      print(uid)
   except nxppy.SelectError:
      pass

   time.sleep(0.3)
   mqttsender.loop()