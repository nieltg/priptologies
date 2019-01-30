/*
 * priptologies by nieltg, Daniel
 */

#pragma once

#include <set>
#include <iostream>

#include "Playfair.h"
#include "Alphabet.h"

class PlayfairAlphabet : public Playfair<Alphabet, 5, 5> {
protected:
  Alphabet remove_ch;
  Alphabet remove_ch_to;

  static Tableau<Alphabet, 5, 5> gen_tableau(std::basic_string<Alphabet> _key, Alphabet _remove_ch) {
    Tableau<Alphabet, 5, 5> tableau;

    std::set<Alphabet> available_alphabets;

    for (char ch = 'A'; ch <= 'Z'; ch++)
      available_alphabets.insert(ch);
    available_alphabets.erase(_remove_ch);

    auto it1 = _key.begin();
    std::set<Alphabet>::iterator it2;

    bool stage1 = true;

    for (ptrdiff_t r = 0; r < 5; r++) {
      for (ptrdiff_t c = 0; c < 5; c++) {
        Alphabet ch;

        if (stage1) {
          bool ch_set = false;

          for (; it1 != _key.end(); ++it1) {
            auto find_it = available_alphabets.find(*it1);

            if (find_it != available_alphabets.end()) {
              ch = *find_it;
              ch_set = true;

              available_alphabets.erase(find_it);
              break;
            }
          }

          if (!ch_set) {
            stage1 = false;
            it2 = available_alphabets.begin();
          }
        }

        if (!stage1) {
          ch = *it2++;
        }

        tableau[r][c] = ch;
      }
    }

    return tableau;
  }

public:
  PlayfairAlphabet(std::basic_string<Alphabet> _key, Alphabet _remove_ch, Alphabet _remove_ch_to, Alphabet _substitute_ch)
    : Playfair(gen_tableau(_key, _remove_ch), _substitute_ch),
      remove_ch(_remove_ch),
      remove_ch_to(_remove_ch_to) {}

  std::basic_string<Alphabet> encrypt(const std::basic_string<Alphabet>& plain_text) const {
    std::basic_string<Alphabet> plain_text_copy = plain_text;

    for (Alphabet& a : plain_text_copy) {
      if (a == remove_ch) {
        a = remove_ch_to;
      }
    }

    return Playfair::encrypt(plain_text_copy);
  }
};
