/************************************************************************************************************

                                      configurações Slave_ESP32
************************************************************************************************************/

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "wire.h"

/**********************************************************************************************************/
                                        /* Arquivos de inclusão */


#include "Config_mcu.h"

#define myAdress 0x07

const int LED_ESP32 = 13;




#define ReleledPin 32 // numero do pino onde o LED esta conectado
// funcao executada sempre que algum dado e recebido no barramento I2C
// vide "void setup()"
void receiveEvent(int howMany) {
  // verifica se existem dados para serem lidos no barramento I2C
  if (Wire.available()) {
    // le o byte recebido
    char received = Wire.read();

    // se o byte recebido for igual a 0, apaga o LED
    if (received == 0) {
      digitalWrite(ReleledPin, LOW);
    }

    // se o byte recebido for igual a 1 acende o LED
    if (received == 1) {
      digitalWrite(ReleledPin, HIGH);
    }
  }
}


void Config_mcu()
{
   Serial.begin(115200);
  // ingressa ao barramento I2C com o endereço definido no myAdress (0x07)
  Wire.begin(myAdress);
 

  //Registra um evento para ser chamado quando chegar algum dado via I2C
  Wire.onReceive(receiveEvent);

  pinMode(ReleledPin, OUTPUT);  // configura o pino do LED como saida
  digitalWrite(ReleledPin,HIGH);                     

}