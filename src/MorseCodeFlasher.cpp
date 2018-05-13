#include "application.h"
#include "MorseCodeFlasher.h"

MorseCodeFlasher::MorseCodeFlasher() {
}

MorseCodeFlasher::MorseCodeFlasher(int ledFlashPin)
  : ledPin(ledFlashPin) {
}

MorseCodeFlasher::~MorseCodeFlasher() {
}

void MorseCodeFlasher::sendMessage(MorseCodeMessage message) {
    for (int i = 0; i < message.length(); i++) {
        flashCharacter(message.charAt(i));
        delay(CHARACTER_GAP);
    }
}

void MorseCodeFlasher::flashCharacter(MorseCodeCharacter morseCodeChar) {
    if (morseCodeChar.isSpace()) {
        delay(SPACE_LENGTH);
    } else {
        for (int i = 0; i < morseCodeChar.getEncodedCharacter().length(); i++) {
            flashSignal((morseCodeChar.getEncodedCharacter().charAt(i) == '-') ? DASH : DOT);
        }
    }
}

void MorseCodeFlasher::flashSignal(int flashLength) {
        digitalWrite(getLedPin(), HIGH);
        delay(flashLength);
        digitalWrite(getLedPin(), LOW);
        delay(SIGNAL_GAP);
}

int MorseCodeFlasher::getLedPin() {
    return ledPin;
}

void MorseCodeFlasher::setLedPin(int pin) {
    ledPin = pin;
}
