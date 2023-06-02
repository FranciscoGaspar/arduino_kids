#include <TM1637Display.h>
#define CLK 3
#define DIO 4

TM1637Display display = TM1637Display(CLK, DIO);

//KY016 3-color LED module
int redpin = 9; // select the pin for the red LED
int bluepin = 11; // select the pin for the blue LED
int greenpin = 10 ;// select the pin for the green LED
int trigPin = 6;    // Trigger
int echoPin = 12;    // Echo
int buzzer = 8;

long duration, cm, inches;
int val;

void setup () {
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);  
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);

  pinMode (buzzer, OUTPUT);
  Serial.begin (9600);
}
void loop ()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration/2) / 29.1;


  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  display.setBrightness(5);
  display.showNumberDec(cm);

  delay(500);
	display.clear();

  if (cm >= 50) {
    analogWrite(redpin, 0);
    analogWrite(greenpin, 100);
    analogWrite(bluepin, 0);
  } else if (cm > 20) {
    analogWrite(redpin, 255);
    analogWrite(greenpin, 50);
    analogWrite(bluepin, 0);
  } else {
    analogWrite(redpin, 100);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 0);

    digitalWrite(buzzer, HIGH);
    delay(10);

    digitalWrite(buzzer, LOW);
    delay(10);

    tone(buzzer, 50, 500);
  }
}