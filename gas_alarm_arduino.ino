#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(0, 1);
int greenLight = 8;
int buzzer = 10;
int smokeSensor = A5;
int sensorThres = 250;

void setup() {
  pinMode(greenLight, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeSensor, INPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600);
  digitalWrite(greenLight, HIGH);
}

void loop() {
  int analogSensor = analogRead(smokeSensor);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  Bluetooth.println(String(analogSensor));
  if (analogSensor >= sensorThres) {
    tone(buzzer, 1000, 200);
  }
  else {
    noTone(buzzer);
  }
  delay(300);
}
