/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <Playfair.h>
#include <Alphabet.h>

class PlayfairAlphabetTest : public testing::Test {
protected:
  Playfair<Alphabet, 25, 25> cipher_ = Playfair<Alphabet, 25, 25>(Alphabet::from_string("key"));
};

TEST_F(PlayfairAlphabetTest, encrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}
