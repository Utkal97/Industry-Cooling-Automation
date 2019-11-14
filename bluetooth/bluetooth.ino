#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // connect Rx to 11 and Tx to 10

void setup() {
  Serial.begin(9600);       //Serial monitor baud rate
  mySerial.begin(9600);     //Sending baud rate
}

void loop() {
    long int value = random(500);
    mySerial.println(String(value));
    Serial.println(value);
    delay(2000);
}
