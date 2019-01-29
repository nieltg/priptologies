/*
 * priptologies by nieltg, Daniel
 */

#include "Cipher.h"

template<typename CharT>
class Vigenere : public Cipher<CharT> {
protected:
  std::basic_string<CharT> key;

public:
  Vigenere(const std::basic_string<CharT>& _key)
    : key(_key) {}

  std::basic_string<CharT> encrypt(const std::basic_string<CharT>& _plain_text) const {
    return "";
  }

  std::basic_string<CharT> decrypt(const std::basic_string<CharT>& _cipher_text) const {
    return "";
  }
};
