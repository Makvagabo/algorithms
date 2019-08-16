//
// Created by Alexander on 13.08.2019.
//

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "Hackerrank/make_anagram.h"

TEST(Hackerrank, make_anagram_Test) {
  std::string a0 = "fcrxzwscanmligyxyvym";
  std::string b0 = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";

  EXPECT_EQ(Hackerrank::makeAnagram(a0, b0), 30);
}