/*
 * priptologies by nieltg, Daniel
 */

#include <Cipher.h>

template<typename CharT>
class Vigenere : public Cipher<CharT> {
protected:
  std::basic_string<CharT> key;

public:
  Vigenere(const std::basic_string<CharT>& _key)
    : key(_key) {}

  std::basic_string<CharT> encrypt(const std::basic_string<CharT>& _plain_text) const {
    std::basic_string<CharT> cipher_text;

    auto key_it = key.begin();

    for (CharT ch : _plain_text) {
      cipher_text.push_back(ch + *key_it);

      if (++key_it == key.end()) {
        key_it = key.begin();
      }
    }

    return cipher_text;
  }

  std::basic_string<CharT> decrypt(const std::basic_string<CharT>& _cipher_text) const {
    return "";
  }
};
