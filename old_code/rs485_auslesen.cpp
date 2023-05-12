#include "Arduino.h"
#include <SoftwareSerial.h>  // https://github.com/PaulStoffregen/SoftwareSerial

#define RX        D2    //Serial Receive pin
#define TX        D3    //Serial Transmit pin
#define RTS_pin   D0    //RS485 Direction control
#define RS485Transmit    HIGH
#define RS485Receive     LOW

SoftwareSerial RS485Serial(RX, TX);

void setup() {

  pinMode(RTS_pin, OUTPUT);  
  
  // Start the built-in serial port, for Serial Monitor
  Serial.begin(19200);
  Serial.println("Wattmeter"); 

  // Start the Modbus serial Port, for Wattmeter
  RS485Serial.begin(4800);   
  delay(1000);
}

void loop() {
/*
  digitalWrite(RTS_pin, RS485Transmit);     // init Transmit
  byte Wattmeter_request[] = {0x01, 0x03, 0x00, 0x16, 0x00, 0x01, 0x65, 0xCE}; // inquiry frame
  RS485Serial.write(Wattmeter_request, sizeof(Wattmeter_request));
  RS485Serial.flush();
  */
  digitalWrite(RTS_pin, RS485Receive);      // Init Receive
  byte Wattmeter_buf[8];
  RS485Serial.readBytes(Wattmeter_buf, 8);

    Serial.print("Wattausgabe -> ");

 /*
  
  for( byte i=0; i<7; i++ ) {
  Serial.print(Wattmeter_buf[i], HEX);
  Serial.print(" ");
  }
  */
 
  Serial.print(" -> ");
  Serial.print(Wattmeter_buf[5]);
  Serial.print(" Watt");


  Serial.println();                  
  delay(100);

}