/*
 * priptologies by nieltg, Daniel
 */

#pragma once

#include <stdexcept>

class Alphabet {
  friend struct std::hash<Alphabet>;

protected:
  int8_t val;

  static inline Alphabet from_value(int8_t _val) {
    Alphabet a;
    a.val = _val;

    return a;
  }

public:
  Alphabet() {}

  Alphabet(char _ch) {
    if (_ch >= 'A' && _ch <= 'Z') {
      val = _ch - 'A';
    } else if (_ch >= 'a' && _ch <= 'z') {
      val = _ch - 'a';
    } else {
      throw std::invalid_argument("not an alphabet");
    }
  }

  char to_plain(void) const {
    return val + 'a';
  }

  char to_cipher(void) const {
    return val + 'A';
  }

  friend Alphabet operator+(const Alphabet& _lhs, const Alphabet& _rhs) {
    int8_t val = _lhs.val + _rhs.val + 1;
    return Alphabet::from_value(val >= 26 ? val - 26 : val);
  }

  friend Alphabet operator-(const Alphabet& _lhs, const Alphabet& _rhs) {
    int8_t val = _lhs.val - _rhs.val - 1;
    return Alphabet::from_value(val < 0 ? val + 26 : val);
  }

  friend bool operator==(const Alphabet& _lhs, const Alphabet& _rhs) {
    return _lhs.val == _rhs.val;
  }

  friend bool operator!=(const Alphabet& _lhs, const Alphabet& _rhs) {
    return _lhs.val != _rhs.val;
  }

  friend bool operator<(const Alphabet& _lhs, const Alphabet& _rhs) {
    return _lhs.val < _rhs.val;
  }

  static std::basic_string<Alphabet> from_string(std::string _str) {
    std::basic_string<Alphabet> alphabet_str;

    for (char ch : _str) {
      alphabet_str.push_back(ch);
    }

    return alphabet_str;
  }
};

namespace std {
  template<>
  struct hash<Alphabet> {
    size_t operator()(const Alphabet& _a) const {
      return std::hash<int8_t>()(_a.val);
    }
  };
}
