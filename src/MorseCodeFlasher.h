#ifndef MORSECODEFLASHER_H
#define MORSECODEFLASHER_H

#include "MorseCodeMessage.h"

class MorseCodeFlasher {
  private:
    int DOT = 200;
    int DASH = DOT * 3;
    int CHARACTER_GAP = DASH - DOT;
    int SIGNAL_GAP = DOT;
    int SPACE_LENGTH = DOT * 7;

    int ledPin;

    void flashCharacter(MorseCodeCharacter morseCode);
    void flashSignal(int flashLength);

  public:
    MorseCodeFlasher();
    MorseCodeFlasher(int ledFlashPin);
    ~MorseCodeFlasher();
    void setLedPin(int pin);
    int  getLedPin();

    void sendMessage(MorseCodeMessage message);
};

#endif
