/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <Playfair.h>
#include <Alphabet.h>

class PlayfairAlphabetTest : public testing::Test {
protected:
  Tableau<Alphabet, 5, 5> tableau = {{
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'K'},
    {'L', 'M', 'N', 'O', 'P'},
    {'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'X', 'Y', 'Z'}
  }};

  Playfair<Alphabet, 5, 5> cipher_ = Playfair<Alphabet, 5, 5>(tableau);
};

TEST_F(PlayfairAlphabetTest, encrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(PlayfairAlphabetTest, encrypt_single_horizontal_bigram_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("ab")), Alphabet::from_string("bc"));
}

TEST_F(PlayfairAlphabetTest, encrypt_single_horizontal_wrapped_bigram_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("ae")), Alphabet::from_string("ba"));
}

TEST_F(PlayfairAlphabetTest, encrypt_single_vertical_bigram_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("af")), Alphabet::from_string("fl"));
}

TEST_F(PlayfairAlphabetTest, encrypt_single_vertical_wrapped_bigram_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("av")), Alphabet::from_string("fa"));
}

TEST_F(PlayfairAlphabetTest, encrypt_diagonal_down_bigram_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("lc")), Alphabet::from_string("na"));
}

TEST_F(PlayfairAlphabetTest, encrypt_diagonal_up_bigram_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("cl")), Alphabet::from_string("an"));
}
