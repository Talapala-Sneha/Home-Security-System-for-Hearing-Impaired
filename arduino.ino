#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(5,6);

int copin = 0; 
int epin = 2;
int tpin = 3;
int fpin = 4;
int vibpin = 7;

int wpin = A1; 
int spin = A2;  
    
void setup() {
  s.begin(9600);
  Serial.begin(9600);
  pinMode(vibpin, INPUT);
  pinMode(fpin, INPUT);
  pinMode(copin, INPUT);
  pinMode(spin, INPUT);
  pinMode(epin, INPUT); 
  
  pinMode(tpin, OUTPUT); 
}
 
void loop() 
{
  int v = digitalRead(vibpin);
  s.println(v);
    
  int f = digitalRead(fpin);
  s.println(!f);
  delay(100);

  float co = analogRead(copin);
  float coppm = co/1000;
  s.println(coppm);
  
  int w = analogRead(wpin); 
  s.println(w);

  int sm = analogRead(spin);
  s.println(sm);

  digitalWrite(tpin, LOW);
  delayMicroseconds(2);
  digitalWrite(tpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tpin, LOW);
  long duration = pulseIn(epin, HIGH);
  int distance = duration * 0.034 / 2; 
  s.print(distance);
  
  delay(1000);
}
