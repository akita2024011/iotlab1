#include "Arduino.h"

#define BUTTON_PIN 25
#define GREEN_LED_PIN 27

int greenState = 0;
int lastButtonState = HIGH;

/****************************************************/
void setup(void)
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(GREEN_LED_PIN, OUTPUT);

    Serial.begin(115200);

    digitalWrite(GREEN_LED_PIN, LOW);
}


/****************************************************/
void loop(void)
{
    int buttonState = digitalRead(BUTTON_PIN);

    if (lastButtonState == HIGH && buttonState == LOW)
    {
        greenState = !greenState;

        digitalWrite(GREEN_LED_PIN, greenState);

        Serial.print("GREEN=");
        Serial.println(greenState);

        delay(50); // debounce
    }

    lastButtonState = buttonState;
}
