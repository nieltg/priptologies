/*
 * priptologies by nieltg, Daniel
 */

#include <Cipher.h>

template<typename CharT, size_t R, size_t C>
class Playfair : Cipher<CharT> {
protected:
  std::basic_string<CharT> key;

public:
  Playfair(std::basic_string<CharT> _key)
    : key(_key) {}

  std::basic_string<CharT> encrypt(const std::basic_string<CharT>& plain_text) const {
    return std::basic_string<CharT>();
  }

  std::basic_string<CharT> decrypt(const std::basic_string<CharT>& cipher_text) const {
    return std::basic_string<CharT>();
  }
};
