/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <vigenere/Vigenere.h>
#include <Alphabet.h>

class VigenereAlphabetTest : public testing::Test {
protected:
  Vigenere<Alphabet> cipher_ = Vigenere<Alphabet>(Alphabet::from_string("key"));
};

TEST_F(VigenereAlphabetTest, encrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(VigenereAlphabetTest, encrypt_key_lengthed_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("abc")), Alphabet::from_string("lgb"));
}

TEST_F(VigenereAlphabetTest, encrypt_plain_text_with_length_more_than_key_length_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("abcabc")), Alphabet::from_string("lgblgb"));
}

TEST_F(VigenereAlphabetTest, decrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(VigenereAlphabetTest, decrypt_key_lengthed_plain_text_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("lgb")), Alphabet::from_string("abc"));
}

TEST_F(VigenereAlphabetTest, decrypt_plain_text_with_length_more_than_key_length_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("lgblgb")), Alphabet::from_string("abcabc"));
}
