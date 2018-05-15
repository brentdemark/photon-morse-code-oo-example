#ifndef MORSECODEEMITTER_H
#define MORSECODEEMITTER_H

#include "MorseCodeMessage.h"

class MorseCodeEmitter {
  private:
    int outputPin;

    int DOT = 200;
    int DASH = DOT * 3;
    int CHARACTER_GAP = DASH - DOT;
    int SIGNAL_GAP = DOT;
    int SPACE_LENGTH = DOT * 7;


    void emitCharacter(MorseCodeCharacter morseCode);

  public:
    MorseCodeEmitter();
    MorseCodeEmitter(int pin);
    ~MorseCodeEmitter();
    void setOutputPin(int pin);
    int  getOutputPin();

    void sendMessage(MorseCodeMessage message);
    void emitSignal(int signalDuration);
    virtual void startEmittingSignal() = 0;
    virtual void stopEmittingSignal() = 0;
};

#endif
