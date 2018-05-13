#ifndef MORSECODEMESSAGE_H
#define MORSECODEMESSAGE_H

#include "application.h"
#include "MorseCodeCharacter.h"

class MorseCodeMessage {
  private:
  String SPACE = " ";
  String message = "";

  String morseEncoding[37] = {
    "-----",  // 0
    ",----",  // 1
    ",,---",  // 2
    ",,,--",  // 3
    ",,,,-",  // 4
    ",,,,,",  // 5
    "-,,,,",  // 6
    "--,,,",  // 7
    "---,,",  // 8
    "----,",  // 9
    ",-",     // A
    "-,,,",   // B
    "-,-,",   // C
    "-,,",    // D
    ",",      // E
    ",,-,",   // F
    "--,",    // G
    ",,,,",   // H
    ",,",     // I
    ",----",  // J
    "-,-",    // K
    ",-,,",   // L
    "--",     // M
    "-,",     // N
    "---",    // O
    ",--,",   // P
    "--,-",   // Q
    ",-,",    // R
    ",,,",    // S
    "-",      // T
    ",,-",    // U
    ",,,-",   // V
    ",--",    // W
    "-,,-",   // X
    "-,--",   // Y
    "--,,",   // Z
  };

  public:
    MorseCodeMessage();
    ~MorseCodeMessage();
    void setup();
    void loop();
    void sendMorseMessage(String message);
    String getEncoding(char character);
    void flashEncodedChar(String morseCode);
    void flashSignal(int flashLength);
    bool isValid(String testMessage);
    int setMessage(String newMessage);
    String getMessage();
    int length();
    MorseCodeCharacter charAt(int i);

};

#endif
