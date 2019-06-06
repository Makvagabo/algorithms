//
// Created by Aleskander on 03.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/gcd.h"

using Numerical::GCD;

TEST(Numerical, GratestCommonDevisor_Test) {
  EXPECT_EQ(GCD(4851, 3003), 231);
  EXPECT_EQ(GCD(10, 5), 5);
  EXPECT_EQ(GCD(13, 17), 1);
}
