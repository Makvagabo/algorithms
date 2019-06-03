//
// Created by Aleskander on 03.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/gcd.h"

TEST(Numerical, GratestCommonDevisor_Test) {
  EXPECT_EQ(Numerical::GCD(4851, 3003), 231);
  EXPECT_EQ(Numerical::GCD(10, 5), 5);
  EXPECT_EQ(Numerical::GCD(13, 17), 1);
}
