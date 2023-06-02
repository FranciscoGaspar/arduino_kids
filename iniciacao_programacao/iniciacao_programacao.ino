#include <dht11.h>
#define DHT11PIN 4

int LED_VERMELHO = 3;
int LED_AMARELO = 4;
int LED_VERDE = 5;
int SENSOR_LUMINOSIDADE = 10;

dht11 DHT11;

void setup() {
  Serial.begin(9600);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(SENSOR_LUMINOSIDADE, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT11.read(DHT11PIN);
  const humidade = DHT11.humidity;
  const temperatura = DHT11.temperature;

  int valorLuminosidade = analogRead(SENSOR_LUMINOSIDADE);
}
