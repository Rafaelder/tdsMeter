#include "tds_sensor.h"

int bufferAnalogico[SCOUNT];
int bufferTemp[SCOUNT];
float temperatura = 23.0;       // temperatura atual para compensação
int indiceBuffer = 0;

void iniciarSensorTDS() {
  pinMode(TDS_SENSOR_PIN, INPUT);
}

void lerSensorTDS() {
  bufferAnalogico[indiceBuffer] = analogRead(TDS_SENSOR_PIN);   // lê o valor analógico e armazena no buffer
  indiceBuffer = (indiceBuffer + 1) % SCOUNT;
}

float calcularTDS() {
  for (int i = 0; i < SCOUNT; i++) {
    bufferTemp[i] = bufferAnalogico[i];
  }
  // leitura mais estável usando filtragem mediana, e conversão para tensão
  float tensaoMedia = getMediana(bufferTemp, SCOUNT) * VREF / 1024.0;
  // fórmula de compensação de temperatura: resultado(25°C) = resultadoAtual / (1.0 + 0.02 * (temperatura - 25.0))
  float coefCompensacao = 1.0 + 0.02 * (temperatura - 25.0);
  // compensação de temperatura
  float tensaoCompensada = tensaoMedia / coefCompensacao;

  // conversão da tensão para valor de TDS
  float valorTDS = (133.42 * pow(tensaoCompensada, 3)
                  - 255.86 * pow(tensaoCompensada, 2)
                  + 857.39 * tensaoCompensada) * 0.5;

  return valorTDS;
}

void bubbleSort(int arr[], int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

//filtragem de mediana
int getMediana(int arr[], int tamanho) {
  int copia[tamanho];
  memcpy(copia, arr, sizeof(int) * tamanho);
  bubbleSort(copia, tamanho);
  if (tamanho % 2 == 0)
    return (copia[tamanho / 2] + copia[tamanho / 2 - 1]) / 2;
  else
    return copia[tamanho / 2];
}


