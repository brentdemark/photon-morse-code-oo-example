#include "application.h"
#include "MorseCodeEmitter.h"
#include "MorseCodeCharacter.h"

MorseCodeEmitter::MorseCodeEmitter() {
}

MorseCodeEmitter::MorseCodeEmitter(int pin)
  : outputPin(pin) {
}

MorseCodeEmitter::~MorseCodeEmitter() {
}

void MorseCodeEmitter::sendMessage(MorseCodeMessage message) {
    for (int i = 0; i < message.length(); i++) {
        emitCharacter(message.charAt(i));
        delay(CHARACTER_GAP);
    }
}

void MorseCodeEmitter::emitCharacter(MorseCodeCharacter morseCodeChar) {
    if (morseCodeChar.isSpace()) {
        delay(SPACE_LENGTH);
    } else {
        for (int i = 0; i < morseCodeChar.getEncodedCharacter().length(); i++) {
            emitSignal((morseCodeChar.getEncodedCharacter().charAt(i) == '-') ? DASH : DOT);
            delay(SIGNAL_GAP);
        }
    }
}

int MorseCodeEmitter::getOutputPin() {
    return outputPin;
}

void MorseCodeEmitter::setOutputPin(int pin) {
    outputPin = pin;
}

void MorseCodeEmitter::emitSignal(int signalDuration) {
        startEmittingSignal();
        delay(signalDuration);
        stopEmittingSignal();
}
