#include "application.h"
#include "MorseCodeCompositeEmitter.h"

MorseCodeCompositeEmitter::MorseCodeCompositeEmitter() {
}

MorseCodeCompositeEmitter::MorseCodeCompositeEmitter(int pin)
    : MorseCodeEmitter() {
}

MorseCodeCompositeEmitter::~MorseCodeCompositeEmitter() {
}

void MorseCodeCompositeEmitter::startEmittingSignal() {
    std::vector<MorseCodeEmitter*>::iterator iter;
    for(iter = emitters.begin(); iter != emitters.end(); iter++) {
        (*iter)->startEmittingSignal();
    }
}

void MorseCodeCompositeEmitter::stopEmittingSignal() {
    std::vector<MorseCodeEmitter*>::iterator iter;
    for(iter = emitters.begin(); iter != emitters.end(); iter++) {
        (*iter)->stopEmittingSignal();
    }
}

MorseCodeCompositeEmitter* MorseCodeCompositeEmitter::addEmitter(MorseCodeEmitter* emitter) {
    emitters.push_back(emitter);
    return this;
}
