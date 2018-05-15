#ifndef MORSECODEFLASHER_H
#define MORSECODEFLASHER_H

#include "MorseCodeEmitter.h"

class MorseCodeFlasher : public MorseCodeEmitter {
  public:
    MorseCodeFlasher();
    MorseCodeFlasher(int pin);
    ~MorseCodeFlasher();

    void startEmittingSignal();
    void stopEmittingSignal();

};

#endif
