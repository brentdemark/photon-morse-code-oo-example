#ifndef MORSECODECOMPOSITEEMITTER_H
#define MORSECODECOMPOSITEEMITTER_H

#include <vector>
#include "MorseCodeEmitter.h"

class MorseCodeCompositeEmitter : public MorseCodeEmitter {
  private:
    std::vector<MorseCodeEmitter*> emitters;


  public:
    MorseCodeCompositeEmitter();
    MorseCodeCompositeEmitter(int pin);
    ~MorseCodeCompositeEmitter();

    MorseCodeCompositeEmitter* addEmitter(MorseCodeEmitter* emitter);
    void startEmittingSignal();
    void stopEmittingSignal();
};

#endif
