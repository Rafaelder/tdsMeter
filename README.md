# 💧 Leitura de Sensor TDS com Arduino (PlatformIO)

Projeto desenvolvido para realizar a **leitura de um sensor TDS (Total Dissolved Solids)** utilizando um microcontrolador compatível com Arduino.  
O código foi estruturado com o **PlatformIO** no **VS Code**, organizado em arquivos `.h` e `.cpp` para melhor modularização e manutenção.

---
## ⚙️ Funcionamento

O sensor TDS mede a **quantidade de sólidos dissolvidos em uma solução** em partes por milhão (ppm).  
Este projeto faz:

- Leitura analógica do sensor TDS;  
- Filtragem dos dados por **método de mediana** para reduzir ruídos;  
- **Compensação de temperatura** na medição;  
- Cálculo do valor de TDS em **ppm**;  
- Exibição dos resultados no **Monitor Serial**.

----

- A leitura do sensor é feita no pino **A0**, definido em `tds_sensor.h`.  
- O valor analógico é convertido em tensão e ajustado conforme a **temperatura ambiente** (padrão: 23 °C).  
    A variável temperatura **(definida em `tds_sensor.cpp`)** pode ser alterada para compensar a temperatura real da água.
- A conversão da tensão para o valor de TDS é feita com base em uma **equação empírica** amplamente utilizada.

---

## 🧩 Requisitos

- VS Code com extensão **PlatformIO** instalada  
- Placa compatível com Arduino (ex.: UNO, Nano, Mega)  
- Sensor TDS analógico (ex.: TDS Meter V1.0)  

---