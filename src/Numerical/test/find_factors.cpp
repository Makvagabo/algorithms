//
// Created by Aleskander on 06.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/find_factors.h"

using Numerical::FindFactors;

TEST(Numerical, FindFactors_Test) {
  auto finds_1 = FindFactors(189);
  int factors_1[] = { 3, 3, 3, 7 };
  for (int i = 0; i < 4; ++i) {
    EXPECT_EQ(finds_1[i], factors_1[i]);
  }

  auto finds_2 = FindFactors(252);
  int factors_2[] = { 2, 2, 3, 3, 7 };
  for (int i = 0; i < 4; ++i) {
    EXPECT_EQ(finds_2[i], factors_2[i]);
  }
}
