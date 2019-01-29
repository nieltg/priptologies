/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <vigenere/VigenereAuto.h>

class VigenereAutoTest : public testing::Test {
protected:
  VigenereAuto<char> cipher_ = VigenereAuto<char>("key");
};

TEST_F(VigenereAutoTest, encrypt_empty_plain_text_works) {
  ASSERT_TRUE(cipher_.encrypt("") == "");
}

TEST_F(VigenereAutoTest, encrypt_key_lengthed_plain_text_works) {
  ASSERT_TRUE(cipher_.encrypt("abc") == "\xcc\xc7\xdc");
}

TEST_F(VigenereAutoTest, decrypt_empty_plain_text_works) {
  ASSERT_TRUE(cipher_.decrypt("") == "");
}

TEST_F(VigenereAutoTest, decrypt_key_lengthed_plain_text_works) {
  ASSERT_TRUE(cipher_.decrypt("\xcc\xc7\xdc") == "abc");
}
