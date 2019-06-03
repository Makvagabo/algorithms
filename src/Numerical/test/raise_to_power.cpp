//
// Created by Aleskander on 03.06.2019.
//

#include <gtest/gtest.h>
#include <math.h>

#include "Numerical/raise_to_power.h"
#include "Numerical/big_integer.h"

using namespace Numerical;

TEST(Numerical, RiseTo_Test) {
  EXPECT_EQ(RaiseToPower<int>(3, 5), std::pow(3, 5));
  EXPECT_EQ(RaiseToPower<uint64_t>(3, 33), std::pow(3, 33));

  // EXPECT_EQ(RaiseToPower<b_int>(3, 15), std::pow(3, 15));
}
