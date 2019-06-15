//
// Created by Alexander on 15.06.2019.
//

#include <gtest/gtest.h>
#include <math.h>

#include "Numerical/find_zero.h"

float find_zero_F0(float x) {
  return std::pow(x, 3) / 5 - x * x + x;
}

float find_zero_f1(float x) {
  return 3 * x * x / 5 - 2 * x + 1;
}

TEST(Numerical, FindZero_Test) {
  EXPECT_NEAR(Numerical::FindZero(find_zero_F0, find_zero_f1, 0.3, 0.000001), -2.98139639e-7, 0.000001);
  EXPECT_NEAR(Numerical::FindZero(find_zero_F0, find_zero_f1, 1, 0.000001), 1.38196588, 0.000001);
  EXPECT_NEAR(Numerical::FindZero(find_zero_F0, find_zero_f1, 3, 0.000001), 3.61803389, 0.000001);
}
