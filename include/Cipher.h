/*
 * priptologies by nieltg, Daniel
 */

#include <string>

class Cipher {
public:
  virtual std::string encrypt(const std::string& plain_text) const = 0;
  virtual std::string decrypt(const std::string& cipher_text) const = 0;
};
