#include <ArduinoJson.h>
#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);

void setup() {
  miBT.begin(38400);
}

void loop() {
  const int capacity = JSON_OBJECT_SIZE(2);
  StaticJsonDocument<capacity> json;

  json["waterTank"] = random(1, 3);
  json["level"] = random(1, 4);

  String parseJson;

  serializeJson(json, parseJson);

  miBT.println(parseJson);

  delay(4000);
}