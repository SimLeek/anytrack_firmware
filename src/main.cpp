#include <Arduino.h>

#include <SoftwareSerial.h>
#include "sml.hpp"
//2 = Rx
//3 = Tx
SoftwareSerial bt_serial(2,3);
const int hc05_at_pin = 4;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);

pinMode(hc05_at_pin, OUTPUT);
  digitalWrite(hc05_at_pin, HIGH);

while(!Serial){
;
}
Serial.println("Starting Up");
bt_serial.begin(38400);
//delay(500);

}

void loop() {
if(bt_serial.available()) {
Serial.write(bt_serial.read());
}
if(Serial.available()){
    char c = Serial.read();
    bt_serial.write(c);
    Serial.write(c);
}
}