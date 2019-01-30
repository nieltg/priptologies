/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <PlayfairAlphabet.h>
#include <Alphabet.h>

class PlayfairAlphabetTest : public testing::Test {
protected:
  // Tableau<Alphabet, 5, 5> tableau = {{
  //   {'H', 'E', 'L', 'O', 'A'},
  //   {'B', 'C', 'D', 'F', 'G'},
  //   {'I', 'K', 'M', 'N', 'P'},
  //   {'Q', 'R', 'S', 'T', 'U'},
  //   {'V', 'W', 'X', 'Y', 'Z'}
  // }};

  PlayfairAlphabet cipher_ = PlayfairAlphabet(Alphabet::from_string("hello"), 'J', 'I', 'X');
};

TEST_F(PlayfairAlphabetTest, encrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(PlayfairAlphabetTest, encrypt_single_character_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("v")), Alphabet::from_string("wy"));
}
