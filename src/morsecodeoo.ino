// This #include statement was automatically added by the Particle IDE.
#include "MorseCodeFlasher.h"

// This #include statement was automatically added by the Particle IDE.
#include "MorseCodeMessage.h"

int LED = D0;
int SWITCH_PIN = D3;

MorseCodeMessage myMessage;
MorseCodeFlasher myFlasher(LED);

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(SWITCH_PIN) == LOW) {
        myFlasher.sendMessage(myMessage);
    }
}
