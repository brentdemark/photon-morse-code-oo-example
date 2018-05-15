#include "application.h"
#include "MorseCodeFlasher.h"

MorseCodeFlasher::MorseCodeFlasher() {
}

MorseCodeFlasher::MorseCodeFlasher(int pin)
  : MorseCodeEmitter(pin) {
}

MorseCodeFlasher::~MorseCodeFlasher() {
}

void MorseCodeFlasher::startEmittingSignal() {
        digitalWrite(getOutputPin(), HIGH);
}

void MorseCodeFlasher::stopEmittingSignal() {
        digitalWrite(getOutputPin(), LOW);
}
