/*
 * priptologies by nieltg, Daniel
 */

#include <unordered_map>

#include <Cipher.h>

template<typename CharT, size_t R, size_t C>
using Tableau = std::array<std::array<CharT, C>, R>;

template<typename CharT, size_t R, size_t C>
class Playfair : Cipher<CharT> {
protected:
  Tableau<CharT, R, C> tableau;

  std::unordered_map<CharT, std::pair<ptrdiff_t, ptrdiff_t>> tableau_index;

public:
  Playfair(Tableau<CharT, R, C> _tableau)
    : tableau(_tableau) {

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
      b = *it++;

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
      }

      cipher_text.push_back(tableau[a_r][a_c]);
      cipher_text.push_back(tableau[b_r][b_c]);
    }

    return cipher_text;
  }

  std::basic_string<CharT> decrypt(const std::basic_string<CharT>& cipher_text) const {
    return std::basic_string<CharT>();
  }
};
