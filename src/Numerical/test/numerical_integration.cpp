//
// Created by Alexander on 11.06.2019.
//

#include <gtest/gtest.h>
#include <math.h>

#include "Numerical/numerical_integration.h"

static float numerical_integration_f1(float x) {
  return 1 + x + std::sin(2 * x);
}

static float numerical_integration_F0(float x) {
  return x + std::pow(x, 2) / 2 - std::cos(2 * x) / 2 + 0;
}

static float min = 0;
static float max = 5;

TEST(Numerical, Integration_RectangleRule_Test) {
  EXPECT_NEAR(numerical_integration_F0(max) - numerical_integration_F0(min),
              Numerical::RectangleRule(numerical_integration_f1, min, max, 10),
              1.2);
}

TEST(Numerical, Integration_TrapezoidRule_Test) {
  EXPECT_NEAR(numerical_integration_F0(max) - numerical_integration_F0(min),
              Numerical::TrapezoidRule(numerical_integration_f1, min, max, 10),
              0.1);
}

TEST(Numerical, Integration_AdaptiveMidpoint_Test) {
  EXPECT_NEAR(numerical_integration_F0(max) - numerical_integration_F0(min),
              Numerical::IntegrateAdaptiveMidpoint(numerical_integration_f1, min, max, 2, 0.1),
              0.04);
}
