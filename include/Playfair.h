/*
 * priptologies by nieltg, Daniel
 */

#include <Cipher.h>

template<typename CharT, size_t R, size_t C>
using Tableau = std::array<std::array<CharT, C>, R>;

template<typename CharT, size_t R, size_t C>
class Playfair : Cipher<CharT> {
protected:
  Tableau<CharT, R, C> tableau;

public:
  Playfair(Tableau<CharT, R, C> _tableau)
    : tableau(_tableau) {}

  std::basic_string<CharT> encrypt(const std::basic_string<CharT>& plain_text) const {
    return std::basic_string<CharT>();
  }

  std::basic_string<CharT> decrypt(const std::basic_string<CharT>& cipher_text) const {
    return std::basic_string<CharT>();
  }
};
