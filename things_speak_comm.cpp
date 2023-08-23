#include <MQ135.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include<MFRC522.h>
#include "ThingSpeak.h"

const char* ssid = "your wifi";//
const char* password = "your wifi password";
char server[] = "api.thingspeak.com"; //eg: 192.168.0.222

WiFiClient client;
#define PIN_MQ135 A0 // MQ135 Analog Input Pin
#define DHTPIN 2 // DHT Digital Input Pin
#define DHTTYPE DHT11 // DHT11 or DHT22, depends on your sensor
unsigned long myChannelNumber = //your channel number here;
const char * myWriteAPIKey = //your unique API key here;
MQ135 mq135_sensor(PIN_MQ135);
DHT dht(DHTPIN, DHTTYPE);
float temperature, humidity, correctedPPM,h; // Temp and Humid floats, will be measured by the DHT
void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  ThingSpeak.begin(client);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  //Server.begin();
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float rzero = mq135_sensor.getRZero();
  float correctedRZero =
  mq135_sensor.getCorrectedRZero(temperature, humidity);
  float resistance = mq135_sensor.getResistance();
  float ppm = mq135_sensor.getPPM();
  correctedPPM = mq135_sensor.getCorrectedPPM(temperature,humidity);
  h = analogRead(A0);
  Sending_To_thingspeak();
  delay(10000);
  Serial.println("Waiting...");
}

void Sending_To_thingspeak() //CONNECTING WITH MYSQL
{
  if (client.connect(server, 80)) {
  Serial.println("connected");
  // Make a HTTP request:
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(F("%"));
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(F("°C"));
  Serial.print("PPM: ");
  Serial.println(correctedPPM);
  Serial.print("Gas Level: ");
  Serial.println(h/1023*100);
  Serial.println("Data Send to Thingspeak");
  ThingSpeak.writeField(myChannelNumber, 1, temperature,
  myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, humidity,
  myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 3, correctedPPM,
  myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 4, h/1023*100,
  myWriteAPIKey);
  client.print(" "); //SPACE BEFORE HTTP/1.1
  client.print("HTTP/1.1");
  client.println();
  client.println("Host: api.thingspeak.com");
  client.println("Connection: close");
  client.println();
  } else {
  // if you didn't get a connection to the server:
  Serial.println("connection failed");
  }
}