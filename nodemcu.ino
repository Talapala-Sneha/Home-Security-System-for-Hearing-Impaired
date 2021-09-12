#include <SoftwareSerial.h>
#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <ESP8266WiFi.h>  

#define FIREBASE_HOST "sensordata-d3f3f-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "IIY832eDxDxZEHwKtSjZl0DAAHVmmGhGai6KWkls"
#define WIFI_SSID "sneha"                                          
#define WIFI_PASSWORD "12345678"

SoftwareSerial s(D6,D5);
 
void setup() {
  Serial.begin(9600);
  s.begin(9600);
  while (!Serial) continue;

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                               
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
 
  Firebase.setFloat("co",0);
  Firebase.setInt("ultrasonic",0); 
  Firebase.setInt("door",0);     
  Firebase.setInt("water",0); 
  Firebase.setInt("smoke",0);
  Firebase.setInt("fire",0);  
}
 
void loop() {
  int a1 = s.parseInt();
  Serial.println("Vibration");
  Serial.println(a1);
  
  int a2 = s.parseInt();
  Serial.println("Fire");
  Serial.println(a2); 
  
  float f1 = s.parseFloat();
  Serial.println("CO level:");
  Serial.println(f1);

  int a3 = s.parseInt();
  Serial.println("Water level:");
  Serial.println(a3);

  int a4 = s.parseInt();
  Serial.println("Smoke level:");
  Serial.println(a4);

  int a5 = s.parseInt();
  Serial.println("Distance:");
  Serial.println(a5);

  Firebase.setFloat("co",f1);
  Firebase.setInt("ultrasonic",a5); 
  Firebase.setInt("door",a1);     
  Firebase.setInt("water",a3); 
  Firebase.setInt("smoke",a4);
  Firebase.setInt("fire",a2); 
  
  delay(3000);
  Serial.println(""); 
}
