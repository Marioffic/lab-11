#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

/**
 * @class Vigenere
 * @brief A class for encrypting and decrypting messages using the Vigenère cipher.
 * 
 * The Vigenère cipher is a method of encrypting alphabetic text by using a simple form
 * of polyalphabetic substitution. It uses a keyword to encrypt and decrypt messages.
 * This class provides methods for both encryption and decryption of messages using a
 * given key, as well as methods for verifying if a message has been encrypted correctly.
 */

class Vigenere {
public:

  /**
     * @brief Constructs a Vigenere cipher object with a given key.
     * 
     * This constructor initializes the Vigenere cipher using a specified key. The key is
     * used to encrypt and decrypt messages. The key is automatically converted to uppercase.
     * 
     * @param key The key to be used for encryption and decryption. It should be a string of alphabetic characters.
     */

    Vigenere(std::string key);

    /**
     * @brief Destructor for the Vigenere class.
     * 
     * The destructor cleans up any resources used by the Vigenere object. No special cleanup
     * is needed for this class since it does not manage dynamic memory.
     */
    ~Vigenere();

    /**
     * @brief Encrypts a message using the Vigenere cipher.
     * 
     * This method takes a plaintext message and encrypts it using the Vigenère cipher, based
     * on the key provided when the object was created. The function returns the encrypted message.
     * 
     * @param msg The plaintext message to be encrypted.
     * @return The encrypted message.
     */

    std::string encrypt(std::string msg);
 /**
     * @brief Decrypts an encrypted message using the Vigenere cipher.
     * 
     * This method takes an encrypted message and decrypts it using the same key that was used
     * for encryption. It returns the original plaintext message.
     * 
     * @param msg The encrypted message to be decrypted.
     * @return The decrypted message (plaintext).
     */
    std::string decrypt(std::string msg);
/**
     * @brief Checks if the decrypted message matches the original encrypted message.
     * 
     * This method compares an encrypted message with the result of decrypting a given decrypted message
     * and returns whether they match. It is useful for verifying the correctness of encryption and decryption.
     * 
     * @param encryptedMsg The encrypted message.
     * @param decryptedMessage The decrypted message to compare against.
     * @return `true` if the decrypted message matches the encrypted message, `false` otherwise.
     */
 
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);
    /**
     * @brief Sets a new key for the Vigenere cipher.
     * 
     * This method allows the user to set a new key to be used for future encryption and decryption.
     * The new key is automatically converted to uppercase.
     * 
     * @param key The new key to set for encryption/decryption.
     */

    void setKey(std::string key);

   /**
     * @brief Shifts a letter by a certain amount based on the cipher logic.
     * 
     * This function shifts a given letter by the specified `shiftAmount`. The shift can be applied
     * for both encryption and decryption, depending on the `decrypt` flag. 
     * 
     * @param letter The character to be shifted.
     * @param shiftAmount The amount by which to shift the character (typically derived from the key).
     * @param decrypt If `true`, the letter is shifted in reverse (for decryption). Default is `false` (for encryption).
     * @return The shifted letter after applying the shift.
     */
    std::string key;
    char shift(char letter, int shiftAmount, bool decrypt = false);

    /**
     * @brief Re-applies the key to match the length of the message.
     * 
     * This method extends the key to match the length of the given message. If the key is shorter
     * than the message, it repeats the key as many times as needed, and cuts off the excess to match
     * the length of the message.
     * 
     * @param msg The message whose length determines how much of the key is needed.
     * @return A string representing the extended key, now the same length as the message.
     */
    std::string reapply(std::string msg);
};

#endif
