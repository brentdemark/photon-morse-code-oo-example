#ifndef MORSECODECHARACTER_H
#define MORSECODECHARACTER_H

#include "application.h"

class MorseCodeCharacter {
  private:
    char character;
    String encodedCharacter;

  public:
    MorseCodeCharacter(char aCharacter, String encoding);
    ~MorseCodeCharacter();
    bool isSpace();
    String getEncodedCharacter();
};

#endif
