/*
 * priptologies by nieltg, Daniel
 */

#pragma once

#include <unordered_map>
#include <iostream>

#include <Cipher.h>

template<typename CharT, size_t R, size_t C>
using Tableau = std::array<std::array<CharT, C>, R>;

template<typename CharT, size_t R, size_t C>
class Playfair : Cipher<CharT> {
protected:
  Tableau<CharT, R, C> tableau;
  CharT substitute_ch;

  std::unordered_map<CharT, std::pair<ptrdiff_t, ptrdiff_t>> tableau_index;

public:
  Playfair(Tableau<CharT, R, C> _tableau, CharT _substitute_ch)
    : tableau(_tableau), substitute_ch(_substitute_ch) {

    for (ptrdiff_t r = 0; r < R; ++r) {
      for (ptrdiff_t c = 0; c < C; ++c) {
        tableau_index[_tableau[r][c]] = std::make_pair(r, c);
      }
    }
  }

  std::basic_string<CharT> encrypt(const std::basic_string<CharT>& plain_text) const {
    std::basic_string<CharT> cipher_text;

    for (auto it = plain_text.begin(); it != plain_text.end(); ) {
      CharT a, b;
      a = *it++;
      b = substitute_ch;
      if (it != plain_text.end()) {
        if (a != *it) b = *it++;
      }

      ptrdiff_t a_r, a_c, b_r, b_c;
      auto const& a_pair = tableau_index.at(a);
      a_r = a_pair.first;
      a_c = a_pair.second;
      auto const& b_pair = tableau_index.at(b);
      b_r = b_pair.first;
      b_c = b_pair.second;

      if (a_r == b_r) {
        a_c = (a_c + 1) % C;
        b_c = (b_c + 1) % C;
      } else if (a_c == b_c) {
        a_r = (a_r + 1) % C;
        b_r = (b_r + 1) % C;
      } else {
        std::swap(a_c, b_c);
      }

      cipher_text.push_back(tableau[a_r][a_c]);
      cipher_text.push_back(tableau[b_r][b_c]);
    }

    return cipher_text;
  }

  std::basic_string<CharT> decrypt(const std::basic_string<CharT>& cipher_text) const {
    std::basic_string<CharT> plain_text;

    for (auto it = cipher_text.begin(); it != cipher_text.end(); ) {
      CharT a, b;
      a = *it++;
      if (it == cipher_text.end())
        throw std::invalid_argument("not a playfair cipher-text");
      b = *it++;

      ptrdiff_t a_r, a_c, b_r, b_c;
      auto const& a_pair = tableau_index.at(a);
      a_r = a_pair.first;
      a_c = a_pair.second;
      auto const& b_pair = tableau_index.at(b);
      b_r = b_pair.first;
      b_c = b_pair.second;

      if (a_r == b_r) {
        if (--a_c < 0) a_c += C;
        if (--b_c < 0) b_c += C;
      } else if (a_c == b_c) {
        if (--a_r < 0) a_r += C;
        if (--b_r < 0) b_r += C;
      } else {
        std::swap(a_c, b_c);
      }

      plain_text.push_back(tableau[a_r][a_c]);
      plain_text.push_back(tableau[b_r][b_c]);
    }

    return plain_text;
  }
};
