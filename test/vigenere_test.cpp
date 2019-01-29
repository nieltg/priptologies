/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <Vigenere.h>

class VigenereTest : public testing::Test {
protected:
  Vigenere<char> cipher_ = Vigenere<char>("key");
};

TEST_F(VigenereTest, empty_plain_text_works) {
  ASSERT_TRUE(cipher_.encrypt("") == "");
}

TEST_F(VigenereTest, key_lengthed_plain_text_works) {
  ASSERT_TRUE(cipher_.encrypt("abc") == "\xcc\xc7\xdc");
}

TEST_F(VigenereTest, plain_text_with_length_more_than_key_length_works) {
  ASSERT_TRUE(cipher_.encrypt("abcabc") == "\xcc\xc7\xdc\xcc\xc7\xdc");
}
