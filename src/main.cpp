#include <Arduino.h>
#include <tds_sensor.h>

void setup() {
  Serial.begin(115200);
  iniciarSensorTDS();
}

void loop() {
  static unsigned long tempoAmostragem = millis();
  static unsigned long tempoImpressao = millis();

  if (millis() - tempoAmostragem > 40) {  // lê o ADC a cada 40 milissegundos
    tempoAmostragem = millis();
    lerSensorTDS();
  }

  if (millis() - tempoImpressao > 800) {
    tempoImpressao = millis();
    float tds = calcularTDS();
    Serial.print("TDS: ");
    Serial.print(tds);
    Serial.println(" ppm");
  }
}