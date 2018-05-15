#ifndef MORSECODESOUNDER_H
#define MORSECODESOUNDER_H

#include "MorseCodeEmitter.h"

class MorseCodeSounder : public MorseCodeEmitter {
  public:
    MorseCodeSounder();
    MorseCodeSounder(int pin);
    ~MorseCodeSounder();

    void startEmittingSignal();
    void stopEmittingSignal();
};

#endif
