#include <LCD_I2C.h>
#define pump 13
LCD_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int endled = 13;
int ledA=7;
int ledB=12;
                                                         
long duration;
int distance;

            
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(ledA,OUTPUT);
pinMode(ledB,OUTPUT);

pinMode(buzzer, OUTPUT);
pinMode(endled, OUTPUT);
pinMode(pump,OUTPUT);
Serial.begin(9600); 
lcd.begin();
lcd.backlight();
}
 
 
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
digitalWrite(pump,LOW);
duration = pulseIn(echoPin, HIGH);
distance= (duration/2)/29.1;
 
if (distance <= 8)   
{
  digitalWrite(buzzer, LOW);
  digitalWrite(endled, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(pump,LOW);
  lcd.setCursor(0,0);
  lcd.print("Tank is FULL");
  Serial.print("Capacity of tank has been reached!!");
}
else if(distance<=15){
  digitalWrite(buzzer, HIGH);
  digitalWrite(endled, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  digitalWrite(pump,HIGH);
  lcd.setCursor(0,0);
  lcd.print("Filling...");
}
else {
  digitalWrite(buzzer, HIGH);
  digitalWrite(endled, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(pump,HIGH);
  lcd.setCursor(0,0);
  lcd.print("---Empty---     ");
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
} 
