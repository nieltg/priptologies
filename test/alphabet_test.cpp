/*
 * priptologies by nieltg, Daniel
 */

#include <gtest/gtest.h>

#include <Alphabet.h>

TEST(basic_test, alphabet_from_lower_case_works) {
  ASSERT_EQ(Alphabet('a'), Alphabet('a'));
}

TEST(basic_test, alphabet_from_upper_case_works) {
  ASSERT_EQ(Alphabet('A'), Alphabet('a'));
}

TEST(basic_test, alphabet_from_unknown_character_fails) {
  ASSERT_THROW(Alphabet('!'), std::invalid_argument);
}

TEST(basic_test, alphabet_to_plain_works) {
  ASSERT_EQ(Alphabet('a').to_plain(), 'a');
}

TEST(basic_test, alphabet_to_cipher_works) {
  ASSERT_EQ(Alphabet('a').to_cipher(), 'A');
}

TEST(basic_test, alphabet_addition_works) {
  ASSERT_EQ((Alphabet('a') + Alphabet('b')), Alphabet('c'));
}

TEST(basic_test, alphabet_addition_overflow_works) {
  ASSERT_EQ((Alphabet('a') + Alphabet('z')), Alphabet('a'));
}

TEST(basic_test, alphabet_substraction_works) {
  ASSERT_EQ((Alphabet('b') - Alphabet('a')), Alphabet('a'));
}

TEST(basic_test, alphabet_substraction_overflow_works) {
  ASSERT_EQ((Alphabet('a') - Alphabet('a')), Alphabet('z'));
}

TEST(basic_test, alphabet_from_string_works) {
  auto alphabet_str = Alphabet::from_string("abc");

  ASSERT_EQ(alphabet_str[0], Alphabet('a'));
  ASSERT_EQ(alphabet_str[1], Alphabet('b'));
  ASSERT_EQ(alphabet_str[2], Alphabet('c'));
}

TEST(basic_test, alphabet_from_string_equality_works) {
  auto alphabet1_str = Alphabet::from_string("abc");
  auto alphabet2_str = Alphabet::from_string("abc");

  ASSERT_EQ(alphabet1_str, alphabet2_str);
}
