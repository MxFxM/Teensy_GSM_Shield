#include <Arduino.h>

#include <GSM_Shield.h>

#define cellSerial Serial2
GSM_Shield cell(&cellSerial);

void setup() {
  // communication to pc
  Serial.begin(9600);

  // initialize the module
  cell.Init();
  cellSerial.begin(9600); // serial has to be started from here
}

void loop() {
  // put your main code here, to run repeatedly:
}