//
// Created by Alexander on 07.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/find_primes.h"

using Numerical::FindPrimes;

TEST(Numerical, FindPrimes_Test) {
  int primes[] = {
      2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
      67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
      139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
  };

  auto finds = FindPrimes(200);
  auto it = finds.begin();
  for (int v : primes) {
    EXPECT_EQ(*(it++), v);
  }
}
