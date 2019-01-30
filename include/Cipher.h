/*
 * priptologies by nieltg, Daniel
 */

#pragma once

#include <string>

template<typename CharT>
class Cipher {
public:
  virtual std::basic_string<CharT> encrypt(const std::basic_string<CharT>& plain_text) const = 0;
  virtual std::basic_string<CharT> decrypt(const std::basic_string<CharT>& cipher_text) const = 0;
};
