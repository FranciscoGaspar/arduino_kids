#include <TM1637Display.h>
#define CLK 5
#define DIO 6

TM1637Display display = TM1637Display(CLK, DIO);

int ledPin = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int ledPin4 = 10;
int ledPin5 = 9;
const int buttonPin = 3;
int buttonState = 0;
int previousState = 0;
int speed = 500;
bool isGreen = false;
int x = 9;
unsigned long start;
unsigned long current;
bool win = false;
int points = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(buttonPin, INPUT);
  start = millis();
}

void loop() {

  display.setBrightness(5);
  display.showNumberDec(points);

  while (true) {

    previousState = buttonState;
    buttonState = digitalRead(buttonPin);

    if (x == 11 && buttonState == HIGH && previousState == LOW) {
      isGreen = true;
      if (speed != 100) {
        speed -= 50;
        points += 100;
        display.showNumberDec(points);
      } else {
        Serial.println("You Win!");
        win = true;
        break;
      }
    } else if (x != 11 && buttonState == HIGH && previousState == LOW) {
      Serial.println("LOOSER!");
      win = false;
      break;
    } else {
      isGreen = false;
    }

    digitalWrite(x, HIGH);

    if ((millis() - start) > speed) {
      digitalWrite(x, LOW);
      x++;
      if (x > 13) {
        x = 9;
      }
      start = millis();
    }
  }

  if( win == false) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  } else {
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
    delay(500);
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
  }

  speed = 500;
  points = 0;
}