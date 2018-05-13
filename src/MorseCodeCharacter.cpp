#include "MorseCodeCharacter.h"

MorseCodeCharacter::MorseCodeCharacter(char aCharacter, String encoding)
  : character(aCharacter), encodedCharacter(encoding) {
}

MorseCodeCharacter::~MorseCodeCharacter() {
}

String MorseCodeCharacter::getEncodedCharacter() {
  return encodedCharacter;
}

bool MorseCodeCharacter::isSpace() {
  return character == ' ';
}
