//
// Created by Alexander on 02.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/prng.h"

TEST(Numerical, PRNG_Test) {
  Numerical::PRNG generator(14, 3, 1879);

  int expect_number_row[] = {
      2, 71, 35, 91, 3, 82, 8, 93, 87, 71,
      75, 31, 61, 96, 26, 78, 28, 32, 8
  };
  for (int i = 1; i < 20; ++i) {
    EXPECT_EQ(generator.random(i), expect_number_row[i-1]);
  }
}
