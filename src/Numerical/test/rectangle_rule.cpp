//
// Created by Alexander on 11.06.2019.
//

#include <gtest/gtest.h>
#include <math.h>

#include "Numerical/rectangle_rule.h"

float f1(float x) {
  return 1 + x + std::sin(2*x);
}

float F0(float x) {
  return x + std::pow(x, 2)/2 - std::cos(2*x)/2 + 0;
}

TEST(Numerical, RectangleRule_Test) {
  float min = 0;
  float max = 5;
  EXPECT_NEAR(F0(max) - F0(min), Numerical::RectangleRule(f1, min, max, 10), 1.2);
}
