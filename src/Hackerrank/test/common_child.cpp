//
// Created by Alexander on 13.08.2019.
//

#include <gtest/gtest.h>
#include <string>

#include "Hackerrank/common_child.h"

TEST(Hackerrank, common_child_Test) {
  std::string s0_1 = "SHINCHAN";
  std::string s0_2 = "NOHARAAA";
  std::string s1_1 = "ABCDEF";
  std::string s1_2 = "FBDAMN";
  std::string s2_1 = "WEWOUCUIDGCGTRMEZEPXZFEJWISRSBBSYXAYDFEJJDLEBVHHKS";
  std::string s2_2 = "FDAGCXGKCTKWNECHMRXZWMLRYUCOCZHJRRJBOAJOQJZZVUYXIC";
  std::string s3_1 = "OUDFRMYMAW";
  std::string s3_2 = "AWHYFCCMQX";
  std::string s4_1 = "ELGGYJWKTDHLXJRBJLRYEJWVSUFZKYHOIKBGTVUTTOCGMLEXWDSXEBKRZTQUVCJNGKKRMUUBACVOEQKBFFYBUQEMYNENKYYGUZSP";
  std::string s4_2 = "FRVIFOVJYQLVZMFBNRUTIYFBMFFFRZVBYINXLDDSVMPWSQGJZYTKMZIPEGMVOUQBKYEWEYVOLSHCMHPAZYTENRNONTJWDANAMFRX";

  // EXPECT_EQ(Hackerrank::commonChild(s0_1, s0_2), 3);
  // EXPECT_EQ(Hackerrank::commonChild(s1_1, s1_2), 2);
  EXPECT_EQ(Hackerrank::commonChild(s2_1, s2_2), 15);
  // EXPECT_EQ(Hackerrank::commonChild(s3_1, s3_2), 2);
  // EXPECT_EQ(Hackerrank::commonChild(s4_1, s4_2), 27);
}