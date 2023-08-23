//ANIMESH PANDEY
//FILE CREATED: 11TH SEPT 2022 9:46PM
//Helemt Ptype1
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(5,6,8,9,10,11);
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400;
int tempsense = A1;
int templimit=45;



void setup()
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}
int get_temperature(int pin)
{
int temperature = analogRead(pin);
float voltage = temperature * 5.0;
voltage = voltage / 1024.0;
return ((voltage - 0.5) * 100);
}


  
  
void loop()
{
  int analogValue = analogRead(sensor);
  int temparature = analogRead(tempsense);
  temparature= temparature * 0.48828125; //converting volatage sensed to temparature mapped
  Serial.print(analogValue);
  Serial.print(" ");
  if(analogValue>sensorThresh || get_temperature(tempsense)>templimit)
  {
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
    tone(buzzer,1000,10000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperature:");
    lcd.setCursor(0,1);
    lcd.print(get_temperature(tempsense));
    lcd.print("C");
    delay(1800);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("EVACUATE DANGER!");
    delay(1000);
  }
  else
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperature:");
    lcd.print(get_temperature(tempsense));
    lcd.print("C");
    delay(1800);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Safe");
    delay(1000);
  }  
     
}