//
// Created by Aleskander on 03.06.2019.
//

#include <gtest/gtest.h>
#include <cmath>

#include "Numerical/raise_to_power.h"
#include "Numerical/big_integer.h"

using Numerical::RaiseToPower, Numerical::b_int;

TEST(Numerical, RiseToPower_Test) {
  EXPECT_EQ(RaiseToPower<int>(3, 5), std::pow(3, 5));
  EXPECT_EQ(RaiseToPower<uint64_t>(3, 33), std::pow(3, 33));
  EXPECT_EQ(RaiseToPower<b_int>(3, 15), std::pow(3, 15));
  EXPECT_EQ(RaiseToPower<b_int>(3, 80).toString(), "147808829414345923316083210206383297601");
  EXPECT_EQ(RaiseToPower<b_int>(3, 100).toString(), "515377520732011331036461129765621272702107522001");
}
