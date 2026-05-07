#include <Arduino.h>
void setup() {
}
void loop() {
analogWrite(7, 64);
delay(1000);
analogWrite(7, 127);
delay(1000);
analogWrite(7, 191);
delay(1000);
analogWrite(7, 255);
delay(1000);
analogWrite(7, 0);
delay(1000);
}