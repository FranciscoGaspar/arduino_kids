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

  float humidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  Serial.print("Humidade:");
  Serial.println(humidade);

  Serial.print("Temperatura:");
  Serial.println(temperatura);

  if (temperatura > 23 && humidade > 60) {
    digitalWrite(LED_VERMELHO, HIGH);
  }

  int valorLuz = analogRead(SENSOR_LUZ);

  Serial.print("Luz:");
  Serial.println(valorLuz);

  if (valorLuz > 250) {
    digitalWrite(LED_LARANJA, HIGH);
  }

  int ruido = analogRead(SENSOR_RUIDO);

  Serial.print("Ruido:");
  Serial.println(ruido);

  if (ruido > 200) {
    digitalWrite(LED_VERDE, HIGH);
  }

  delay(2000);
  digitalWrite(LED_LARANJA, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_VERDE, LOW);
}
