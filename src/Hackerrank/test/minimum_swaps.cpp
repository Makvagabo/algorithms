//
// Created by Alexander on 13.08.2019.
//

#include <gtest/gtest.h>
#include <vector>

#include "Hackerrank/minimum_swaps.h"

TEST(Hackerrank, minimum_swaps_Test) {
  std::vector<int> ar0({ 7, 1, 3, 2, 4, 5, 6 });

  EXPECT_EQ(Hackerrank::minimumSwaps(ar0), 5);
}