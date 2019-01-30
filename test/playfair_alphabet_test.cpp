/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <Playfair.h>
#include <Alphabet.h>

class PlayfairAlphabetTest : public testing::Test {
protected:
  Tableau<Alphabet, 25, 25> tableau = {{
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'K'},
    {'L', 'M', 'N', 'O', 'P'},
    {'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'X', 'Y', 'Z'}
  }};

  Playfair<Alphabet, 25, 25> cipher_ = Playfair<Alphabet, 25, 25>(tableau);
};

TEST_F(PlayfairAlphabetTest, encrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}
