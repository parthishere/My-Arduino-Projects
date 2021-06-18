#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

HTTPClient temp_req;
String url;
int httpCode = 0;
const char * json;

const char* host = "http://temprozen.pythonanywhere.com";
const char* robot_api = "/set_temperature/";

const char *ssid     = "pi11";
const char *password = "raspberry";

void set_wifiSetup()
{
  WiFi.begin(ssid, password);
  delay(100);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
}

void send_data(String mac, String tim, float tem, float bat, int mod, int del)
{
  url = host;
  url += robot_api;
  url += mac;
  url += ",";
  url += tim;
  url += ",";
  url += String(tem);
  url += ",";
  url += String(bat);
  url += ",";
  url += String(mod);
  url += ",";
  url += String(del);
//  Serial.println(url);
  temp_req.begin(url);
  httpCode = temp_req.GET();
//  Serial.println(httpCode);
  if (httpCode > 0)
  {
    const size_t bufferSize = JSON_OBJECT_SIZE(1) + 370;
    DynamicJsonBuffer jsonBuffer(bufferSize);
    JsonObject& root = jsonBuffer.parseObject(temp_req.getString());
    //json = root["Status"];
    //Serial.println(temp_req.getString());
  }
  temp_req.end();
  httpCode = 0;
}
