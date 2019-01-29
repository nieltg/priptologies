/*
 * priptologies by nieltg, Daniel
 */

#include "Cipher.h"

class Vigenere : public Cipher {
protected:
  std::string key;

public:
  Vigenere(const std::string& _key)
    : key(_key) {}

  std::string encrypt(const std::string& _plain_text) const {
    return "";
  }

  std::string decrypt(const std::string& _cipher_text) const {
    return "";
  }
};
