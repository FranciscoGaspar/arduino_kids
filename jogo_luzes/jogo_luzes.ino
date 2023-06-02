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

  while (true) {
    previousState = buttonState;
    buttonState = digitalRead(buttonPin);

    if (x == 11 && buttonState == HIGH && previousState == LOW) {
      isGreen = true;
      if (speed - 50 != 50) {
        speed -= 50;
      } else {
        Serial.println("You Win!");
        speed = 500;
      }
    } else if (x != 11 && buttonState == HIGH && previousState == LOW) {
      Serial.println("LOOSER!");
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

  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
}