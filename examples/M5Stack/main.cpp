#include <M5Stack.h>
#include <WiFi.h>
#include <SSIDLoaderSD.h>

void setup()
{
  M5.begin();
  addAPfromSD();
  Serial.println("Connecting Wifi...");
  connectToAP();
  Serial.println("WiFi connected");
}

void loop()
{
  M5.update();
  if(M5.BtnB.wasPressed()){
    Serial.printf("IP address: ");
    Serial.println(WiFi.localIP());
  }
  delay(100);
}
