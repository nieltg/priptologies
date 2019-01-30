/*
 * priptologies by nieltg, Daniel
 */

#pragma once

#include <Cipher.h>

template<typename CharT>
class VigenereAuto : public Cipher<CharT> {
protected:
  std::basic_string<CharT> initial_key;

public:
  VigenereAuto(const std::basic_string<CharT>& _initial_key)
    : initial_key(_initial_key) {}

  std::basic_string<CharT> encrypt(const std::basic_string<CharT>& _plain_text) const {
    std::basic_string<CharT> cipher_text;

    auto key_it = initial_key.begin();

    for (CharT ch : _plain_text) {
      cipher_text.push_back(ch + *key_it);

      if (++key_it == initial_key.end()) {
        key_it = _plain_text.begin();
      }
    }

    return cipher_text;
  }

  std::basic_string<CharT> decrypt(const std::basic_string<CharT>& _cipher_text) const {
    std::basic_string<CharT> plain_text;

    auto key_it = initial_key.begin();

    for (CharT ch : _cipher_text) {
      plain_text.push_back(ch - *key_it);

      if (++key_it == initial_key.end()) {
        key_it = plain_text.begin();
      }
    }

    return plain_text;
  }
};
