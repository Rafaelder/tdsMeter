#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include <Arduino.h>

#define TDS_SENSOR_PIN A0
#define VREF 5.0        // tensão de referência analógica (Volts) do ADC
#define SCOUNT 30       // quantidade de amostras

extern int bufferAnalogico[SCOUNT]; // armazena os valores analógicos lidos do ADC
extern int bufferTemp[SCOUNT];
extern float temperatura;           

void iniciarSensorTDS();
void lerSensorTDS();
float calcularTDS();
void bubbleSort(int arr[], int tamanho);
int getMediana(int arr[], int tamanho);

#endif
