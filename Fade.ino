/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int ledR = 9; // the PWM pin the LED is attached to
int ledG = 10;
int ledB = 11;
int brightness = 0; // how bright the LED is
int fadeAmount = 5; // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  for (int i = 9; i < 12; i++) {
    brightness = 0;
    fadeAmount = 5;

    for (int j = 0; j < 200; j++) {
      brightness = brightness + fadeAmount;
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      analogWrite(i, brightness);
      delay(10);
    }

    delay(90);
    analogWrite(i, 0);
    delay(90);
  }
}