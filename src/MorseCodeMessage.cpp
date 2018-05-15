#include "application.h"
#include "MorseCodeMessage.h"

MorseCodeMessage::MorseCodeMessage() {
  Particle.function("message", &MorseCodeMessage::setMessage, this);
  setMessage("");
}

MorseCodeMessage::MorseCodeMessage(int notificationLedPin) {
  Particle.function("message", &MorseCodeMessage::setMessage, this);
  setMessage("");
  setNotificationPin(notificationLedPin);
}

MorseCodeMessage::~MorseCodeMessage() {
}

void MorseCodeMessage::setNotificationPin(int pin) {
  notificationPin = pin;
}

int MorseCodeMessage::getNotificationPin() {
  return notificationPin;
}

String MorseCodeMessage::getEncoding(char character) {
    int asciiVal = (int)character;
    int key = -1;
    if(asciiVal >= 'A' && asciiVal <= 'Z') {
        key = asciiVal-'A'+10;
    } else if (asciiVal >= 'a' && asciiVal <= 'z') {
        key = asciiVal-'a'+10;
    } else if (asciiVal >= '0' && asciiVal <= '9') {
        key = asciiVal-'0';
    } else if (asciiVal == ' ') {
        return SPACE;
    } else {
        return "";
    }
    return morseEncoding[key];
}

bool MorseCodeMessage::isValid(String testMessage) {
    for(int i = 0; i < testMessage.length(); i++) {
        if (getEncoding(testMessage.charAt(i)).equals("")) {
            Particle.publish("Invalid Message", testMessage);
            return false;
        }
    }
    return true;
}

String MorseCodeMessage::getMessage() {
    return message;
}

int MorseCodeMessage::setMessage(String newMessage) {
    if(isValid(newMessage)) {
        message = newMessage;
        Particle.publish("Setting Message", message);
        if (getNotificationPin() != -1) {
            Particle.publish("DEBUG", "Turning on notification pin");
            digitalWrite(getNotificationPin(), HIGH);
        }
        return 1;
    }
    return -1;
}

int MorseCodeMessage::length() {
  return getMessage().length();
}

MorseCodeCharacter MorseCodeMessage::charAt(int i) {
  char character = getMessage().charAt(i);
  MorseCodeCharacter morseCodeChar(character, getEncoding(character));
  return morseCodeChar;
}
