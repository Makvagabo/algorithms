//
// Created by Alexander on 07.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/is_prime.h"

using Numerical::IsPrime;

TEST(Numerical, IsPrime_Test) {
  EXPECT_TRUE(IsPrime(71, 70));
  EXPECT_TRUE(IsPrime(19, 18));
  EXPECT_TRUE(IsPrime(41, 40));
}
