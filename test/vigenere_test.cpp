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
