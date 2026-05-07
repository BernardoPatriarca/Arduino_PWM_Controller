#include <Arduino.h>

// Pinos NodeMCU (GPIO)
#define MOTOR_PIN 1    // GPIO5 - conectado ao EN1/IN do L293D
#define BUTTON_PIN 2   // GPIO4 - conectado ao botão com pull-down 10k

bool motorRunning = false;
bool lastButtonState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);  // Pull-down externo (R1 10k já no circuito)
  analogWrite(MOTOR_PIN, 0);
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Detecta borda de subida (botão pressionado)
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    motorRunning = !motorRunning;  // Alterna estado do motor
    Serial.println(motorRunning ? "Motor ON" : "Motor OFF");
    delay(50); // Debounce
  }

  lastButtonState = currentButtonState;

  if (motorRunning) {
    // Ciclo de velocidades crescentes
    analogWrite(MOTOR_PIN, 64);
    delay(1000);
    analogWrite(MOTOR_PIN, 127);
    delay(1000);
    analogWrite(MOTOR_PIN, 191);
    delay(1000);
    analogWrite(MOTOR_PIN, 255);
    delay(1000);
    analogWrite(MOTOR_PIN, 0);
    delay(1000);
  } else {
    analogWrite(MOTOR_PIN, 0);  // Motor parado
  }
}