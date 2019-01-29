/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <vigenere/VigenereAuto.h>
#include <Alphabet.h>

class VigenereAutoAlphabetTest : public testing::Test {
protected:
  VigenereAuto<Alphabet> cipher_ = VigenereAuto<Alphabet>(Alphabet::from_string("key"));
};

TEST_F(VigenereAutoAlphabetTest, encrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(VigenereAutoAlphabetTest, encrypt_key_lengthed_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("abc")), Alphabet::from_string("lgb"));
}

TEST_F(VigenereAutoAlphabetTest, encrypt_plain_text_with_length_more_than_key_length_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("abcabc")), Alphabet::from_string("lgbbdf"));
}

TEST_F(VigenereAutoAlphabetTest, decrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(VigenereAutoAlphabetTest, decrypt_key_lengthed_plain_text_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("lgb")), Alphabet::from_string("abc"));
}

TEST_F(VigenereAutoAlphabetTest, decrypt_plain_text_with_length_more_than_key_length_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("lgbbdf")), Alphabet::from_string("abcabc"));
}
