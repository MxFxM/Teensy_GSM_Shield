#include <Arduino.h>

#include <hidden.h>

#include <GSM_Shield.h>

#define cellSerial Serial2
GSM_Shield cell(&cellSerial, 6);

void pushout();

void setup() {
  // communication to pc
  Serial.begin(9600);

  // initialize the module
  cell.Init();
  cellSerial.begin(115200); // serial has to be started from here

  Serial.println("Reset done");
  delay(1000);
  pushout();

  cell.EnterPin(pin);
  Serial.println("Pin entered");
  delay(3000);
  pushout();

  cell.EnterAPN(address, "", "");
  Serial.println("APN entered");
  delay(3000);
  pushout();

  cell.ActivateGPRS();
  Serial.println("GPRS active");
  delay(5000);
  pushout();

  cell.TestIP();
  Serial.println("IP received");
  delay(3000);
  pushout();

  cell.ConnectToServer("TCP", ip, port);
  Serial.println("Connected to mxfxm.com");
  delay(4000);
  pushout();

  cell.SendBytes(&connect[0], con_len);
  Serial.println("Send connect");
  delay(3000);
  pushout();

  cell.SendBytes(&publish[0], pub_len);
  Serial.println("Send publish");
  delay(3000);
  pushout();

  cell.DisconnectFromServer();
  Serial.println("All done");
  pushout();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void pushout() {
  while (cellSerial.available()) {
    Serial.write(cellSerial.read());
  }
}