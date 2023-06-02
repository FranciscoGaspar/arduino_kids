#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

int LED_VERMELHO = 10;
int LED_LARANJA = 12;
int LED_VERDE = 11;
int SENSOR_LUZ = A0;
#define SENSOR_RUIDO A3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_LARANJA, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(SENSOR_LUZ, INPUT);
  pinMode(SENSOR_RUIDO, INPUT);

  dht.begin();
  Serial.begin(9600);
}

void loop() {

}
