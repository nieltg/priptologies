/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <vigenere/Vigenere.h>

class VigenereTest : public testing::Test {
protected:
  Vigenere<char> cipher_ = Vigenere<char>("key");
};

TEST_F(VigenereTest, encrypt_empty_plain_text_works) {
  ASSERT_TRUE(cipher_.encrypt("") == "");
}

TEST_F(VigenereTest, encrypt_key_lengthed_plain_text_works) {
  ASSERT_TRUE(cipher_.encrypt("abc") == "\xcc\xc7\xdc");
}

TEST_F(VigenereTest, encrypt_plain_text_with_length_more_than_key_length_works) {
  ASSERT_TRUE(cipher_.encrypt("abcabc") == "\xcc\xc7\xdc\xcc\xc7\xdc");
}

TEST_F(VigenereTest, decrypt_empty_plain_text_works) {
  ASSERT_TRUE(cipher_.decrypt("") == "");
}

TEST_F(VigenereTest, decrypt_key_lengthed_plain_text_works) {
  ASSERT_TRUE(cipher_.decrypt("\xcc\xc7\xdc") == "abc");
}

TEST_F(VigenereTest, decrypt_plain_text_with_length_more_than_key_length_works) {
  ASSERT_TRUE(cipher_.decrypt("\xcc\xc7\xdc\xcc\xc7\xdc") == "abcabc");
}
