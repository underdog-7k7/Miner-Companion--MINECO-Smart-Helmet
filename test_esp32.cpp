// //ANIMESH PANDEY
// //20BCT0114
// AD-Hoc network implementation
// File created: 14th September 2022
// Last Modified: 11th November 2022
// Include Libraries
#include <WiFi.h> //to enable comms via wifi
#include <esp_now.h> //to include esp now protocol
#include <MQ135.h>
// Define LED and pushbutton state booleans
bool danger=false; //false state means initially there's no danger
to the miner
bool ledOn = false; //led is initially off
int gas_threshold=400;
int gas_reading;
// Define LED and pushbutton pins
#define STATUS_LED 15 // linking pin 15 on esp32 to Led
void formatMacAddress(const uint8_t *macAddr, char *buffer, int
maxLength) // a prebuilt function to format the MAC Address
correctly
// Formats MAC Address
{
snprintf(buffer, maxLength, "%02x:%02x:%02x:%02x:%02x:%02x",
macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4],
macAddr[5]);
}
void receiveCallback(const uint8_t *macAddr, const uint8_t *data,
int dataLen)
// Called when data is received -- Runs on the recieving board
{
// Basic checking of data
// Only allow a maximum of 250 characters in the message + a null
terminating byte
char buffer[ESP_NOW_MAX_DATA_LEN + 1]; // ESP_NOW_MAX_DATA_LEN=
250 characters
int msgLen = min(ESP_NOW_MAX_DATA_LEN, dataLen); //storing the
message length in a variable
strncpy(buffer, (const char *)data, msgLen); //char *strncpy(char
*dest, const char *src, size_t n)
// Make sure we are null terminated
buffer[msgLen] = 0;
// Format the MAC address
char macStr[18];
formatMacAddress(macAddr, macStr, 18); //macStr now stores the
properly formatted MAC Address of the reciever
// Send Debug log message to the serial port
Serial.printf("Received message from: %s - %s\n", macStr,
buffer);
// Check switch status
if (strcmp("on", buffer) == 0)
{
ledOn = true;
}
else
{
ledOn = false;
}
digitalWrite(STATUS_LED, ledOn);
}
void sentCallback(const uint8_t *macAddr, esp_now_send_status_t
status)
// Called when data is sent --Runs on the sending board
{
char macStr[18];
formatMacAddress(macAddr, macStr, 18);
Serial.print("Last Packet Sent to: ");
Serial.println(macStr);
Serial.print("Last Packet Send Status: ");
Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery
Success" : "Delivery Fail");
}
void broadcast(const String &message)
// Emulates a broadcast
{
// Broadcast a message to every device in range
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF}; //same as unsigned int 8bits // 0xFF Is 255
esp_now_peer_info_t peerInfo = {}; //an empty array at the start
of the communication , we discover the neighbours we have near to
the helmet
memcpy(&peerInfo.peer_addr, broadcastAddress, 6);
//memcpy(dest,src,size)
if (!esp_now_is_peer_exist(broadcastAddress))
{
esp_now_add_peer(&peerInfo);
}
// Send message
esp_err_t result = esp_now_send(broadcastAddress, (const uint8_t
*)message.c_str(), message.length()); //esp_now_send sends the data
// Print results to serial monitor
if (result == ESP_OK)
{
Serial.println("Broadcast message success!");
}
else
{
Serial.println("Unknown error!");
}
}
void setup()
{
// Set up Serial Monitor
Serial.begin(115200);
delay(1000);
// Set ESP32 in station mode to begin with
WiFi.mode(WIFI_STA); //The Station mode (STA) is used to connect
the ESP32 module to a WiFi access point. The ESP32 behaves like a
computer that is connected to our router
Serial.println("Helmet is now active");
// Print MAC address
Serial.print("The helmet ID is: ");
Serial.println(WiFi.macAddress());
// Disconnect from WiFi
WiFi.disconnect(); //to operate correctly in Station mode
// Initialize ESP-NOW
if (esp_now_init() == ESP_OK)
{
Serial.println("Communication successful!"); //cue to start the
callback functions
esp_now_register_recv_cb(receiveCallback);
esp_now_register_send_cb(sentCallback);
}
else
{
Serial.println("Communication failed!");
delay(3000);
ESP.restart(); //restarting the board
}
// LED Output
pinMode(STATUS_LED, OUTPUT);
}
void loop()
{
gas_reading=analogRead(A0);
if (gas_reading>gas_threshold)
{
ledOn = !ledOn;
digitalWrite(STATUS_LED, ledOn);
// Send a message to all devices
if (ledOn)
{
broadcast("on");
}
else
{
broadcast("off");
}
// Delay to avoid bouncing
delay(500);
}
else
{
// Reset the button state
ledOn=!ledOn;
}
}