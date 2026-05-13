#include <Arduino.h>

const int pinoBotao = 2;
const int pinoPWM   = 7;

int velocidade = 0;
bool ultimoEstadoBotao = LOW;

void setup() {
  pinMode(pinoBotao, INPUT);
  pinMode(pinoPWM, OUTPUT);

  analogWrite(pinoPWM, 0);
}

void loop() {
  int leitura = digitalRead(pinoBotao);

  if (leitura == HIGH && ultimoEstadoBotao == LOW) {
    velocidade += 64; 

    if (velocidade > 255) {
      velocidade = 0;
    }
    analogWrite(pinoPWM, velocidade);
  }
  ultimoEstadoBotao = leitura;
}