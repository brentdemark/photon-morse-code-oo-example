// This #include statement was automatically added by the Particle IDE.
#include "MorseCodeCompositeEmitter.h"
#include "MorseCodeSounder.h"
#include "MorseCodeFlasher.h"
#include "MorseCodeMessage.h"

int LED_PIN = D0;
int SOUND_PIN = D1;
int SWITCH_PIN = D3;
int NOTIFICATION_LED = D0;

MorseCodeMessage myMessage(NOTIFICATION_LED);
MorseCodeCompositeEmitter* myMorseCodeEmitter = new MorseCodeCompositeEmitter();

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SOUND_PIN, OUTPUT);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    myMorseCodeEmitter
        ->addEmitter(new MorseCodeFlasher(LED_PIN))
        ->addEmitter(new MorseCodeSounder(SOUND_PIN));
}

void loop() {
    if (digitalRead(SWITCH_PIN) == LOW) {
        digitalWrite(NOTIFICATION_LED, LOW);
        delay(1000);
        myMorseCodeEmitter->sendMessage(myMessage);
    }
}
