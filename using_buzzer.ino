
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
Serial.begin(9600); 
}
 
 
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= (duration/2)/29.1;
 
if (distance <= 20)   
{
  digitalWrite(buzzer, LOW);
  digitalWrite(endled, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  Serial.print("Capacity of tank has been reached!!");
}
else if(distance<=30){
  digitalWrite(buzzer, LOW);
  digitalWrite(endled, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
}
else {
  digitalWrite(buzzer, HIGH);
  digitalWrite(endled, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
} 
