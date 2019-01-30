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

  Playfair<Alphabet, 5, 5> cipher_ = Playfair<Alphabet, 5, 5>(tableau, Alphabet('X'));
};

TEST_F(PlayfairAlphabetTest, encrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(PlayfairAlphabetTest, encrypt_single_character_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("v")), Alphabet::from_string("wy"));
}

TEST_F(PlayfairAlphabetTest, encrypt_single_same_bigram_works) {
  ASSERT_EQ(cipher_.encrypt(Alphabet::from_string("ww")), Alphabet::from_string("xyxy"));
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

TEST_F(PlayfairAlphabetTest, decrypt_empty_plain_text_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("")), Alphabet::from_string(""));
}

TEST_F(PlayfairAlphabetTest, decrypt_single_character_fails) {
  ASSERT_THROW(cipher_.decrypt(Alphabet::from_string("v")), std::invalid_argument);
}

TEST_F(PlayfairAlphabetTest, decrypt_single_horizontal_bigram_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("bc")), Alphabet::from_string("ab"));
}

TEST_F(PlayfairAlphabetTest, decrypt_single_horizontal_wrapped_bigram_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("ba")), Alphabet::from_string("ae"));
}

TEST_F(PlayfairAlphabetTest, decrypt_single_vertical_bigram_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("fl")), Alphabet::from_string("af"));
}

TEST_F(PlayfairAlphabetTest, decrypt_single_vertical_wrapped_bigram_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("fa")), Alphabet::from_string("av"));
}

TEST_F(PlayfairAlphabetTest, decrypt_diagonal_down_bigram_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("na")), Alphabet::from_string("lc"));
}

TEST_F(PlayfairAlphabetTest, decrypt_diagonal_up_bigram_works) {
  ASSERT_EQ(cipher_.decrypt(Alphabet::from_string("an")), Alphabet::from_string("cl"));
}
