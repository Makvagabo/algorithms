#include <gtest/gtest.h>
#include <vector>

#include "Hackerrank/new_year_chaos.h"

TEST(Hackerrank, new_year_chaos_Test) {
  std::vector<int> q0({ 1, 2, 5, 3, 4, 7, 8, 6 });
  std::vector<int> q1({ 1, 2, 5, 3, 7, 8, 6, 4 });
  std::vector<int> q2({ 2, 1, 5, 3, 4 });
  std::vector<int> q3({ 2, 5, 1, 3, 4 });

  EXPECT_EQ(Hackerrank::minimumBribes(q0), 4);
  EXPECT_EQ(Hackerrank::minimumBribes(q1), 7);
  EXPECT_EQ(Hackerrank::minimumBribes(q2), 3);
  EXPECT_EQ(Hackerrank::minimumBribes(q3), -1);
}
