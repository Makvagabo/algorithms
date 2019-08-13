//
// Created by Alexander on 13.08.2019.
//

#include <gtest/gtest.h>
#include <vector>

#include "Hackerrank/array_manipulation.h"

TEST(Hackerrank, array_manipulation) {
  std::vector<std::vector<int>> q0({ {1, 5, 3}, {4, 8, 7}, {6, 9, 1} });

  EXPECT_EQ(Hackerrank::arrayManipulation(10, q0), 10);
}