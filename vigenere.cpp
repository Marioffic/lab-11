#include "vigenere.h"
#include <cctype>

Vigenere::Vigenere(std::string key) {
    setKey(key);
}

Vigenere::~Vigenere() {}

char Vigenere::shift(char letter, int shiftAmount, bool isDecrypt) {
    letter = toupper(letter);
   
    int letterPos = letter - 'A';
    int newPos;

    if (isDecrypt) {
        newPos = (letterPos - shiftAmount + 26) % 26;
    } else {
        newPos = (newPos + shiftAmount) % 26;
    }

    return 'A' + newPos;
}

std::string Vigenere::reapply(std::string message) {
    std::string extraKey = key;
    int plaintextLength = message.length();
    for (size_t i = extraKey.length(); i < plaintextLength; i += key.length()) {
    extraKey += key;
}
    return extraKey.substr(0, plaintextLength);
}

std::string Vigenere::encrypt(std::string message) {
    std::string encryptedMsg = "";
    std::string extendedKey = reapply(message);

    for (size_t i = 0; i < message.length(); ++i) {
        char messageChar = message[i];
        char keyChar = extendedKey[i];

        int shiftAmount = keyChar - 'A';

        encryptedMsg += shift(messageChar, shiftAmount, false);
    }

    return encryptedMsg;
}

std::string Vigenere::decrypt(std::string encryptedMessage) {
    std::string decryptedMessage = "";
    std::string extendedKey = reapply(encryptedMessage);

    size_t i = 0;
    while (i < encryptedMessage.length()) {
        char messageChar = encryptedMessage[i];
        char keyChar = extendedKey[i];

        int shiftAmount = keyChar - 'A';

        decryptedMessage += shift(messageChar, shiftAmount, true);

        ++i;  // Increment the counter
    }

    return decryptedMessage;
}


bool Vigenere::isEncrypted(std::string encryptedMessage, std::string decryptedMessage) {
    return encryptedMessage == decrypt(decryptedMessage);
}

void Vigenere::setKey(std::string newKey) {
    key = newKey;

    for (char &ch : key) {
        ch = toupper(ch);
    }
}
