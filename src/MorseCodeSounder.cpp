#include "application.h"
#include "MorseCodeSounder.h"

MorseCodeSounder::MorseCodeSounder() {
}

MorseCodeSounder::MorseCodeSounder(int pin)
  : MorseCodeEmitter(pin) {
}

MorseCodeSounder::~MorseCodeSounder() {
}

void MorseCodeSounder::startEmittingSignal() {
        tone(getOutputPin(), 1000);
}

void MorseCodeSounder::stopEmittingSignal() {
        noTone(getOutputPin());
}
