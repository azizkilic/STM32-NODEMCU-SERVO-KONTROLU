//VERİCİ
//http://arduino.esp8266.com/stable/package_esp8266com_index.json     /ESP8266
//http://dan.drown.org/stm32duino/package_STM32duino_index.json       /STM32
//KODU YAPIŞTIRDIKTAN SONRA SERİ HABERLEŞME YAPARAK YÜKLEMEN GEREKİYOR VE ÖNCESİNDE STM32 KARTINI TANIMLADIĞINA
//KART YÖNETİCİSİNDEN EMİN OL

#include <Servo.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int value=0;
RF24 radio(D4,D2); // CE, CSN
Servo servo;
const uint64_t pipeIn = 0xE8E8F0F0E1LL; //Remember that this code is the same as in the transmitter


void setup()
{
  Serial.begin(9600); //Set the speed to 9600 bauds if you want.

  
  servo.attach(D0);
  
  radio.begin();
  radio.setAutoAck(false);                    // Ensure autoACK is enabled
  radio.setChannel(0x2F);
  radio.setDataRate(RF24_2MBPS);
  radio.openReadingPipe(1,pipeIn);
  radio.startListening();
}


void loop() {
  while(!radio.available());
  radio.read(&value,sizeof(value));
  Serial.println(value);
  //servo.write(value);
  if(value>200){
    servo.write(150);    
    Serial.println("1111111111111 da");
  }
  else if(value<200){
    servo.write(0);
    Serial.println("0 da");
  }
  

  

}
/**************************************************/
