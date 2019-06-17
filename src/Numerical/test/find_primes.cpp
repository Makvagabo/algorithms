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

  auto finds_1 = FindPrimes(200);
  auto it_1 = finds_1.begin();
  for (int i = 0; i < 46 && it_1 != finds_1.end(); i++, it_1++) {
    EXPECT_EQ(*it_1, primes[i]);
  }

  auto finds_2 = FindPrimes(71);
  auto it_2 = finds_2.begin();
  for (int i = 0; i < 46 && it_2 != finds_2.end(); i++, it_2++) {
    EXPECT_EQ(*it_2, primes[i]);
  }

  auto finds_3 = FindPrimes(5);
  auto it_3 = finds_3.begin();
  for (int i = 0; i < 46 && it_3 != finds_3.end(); i++, it_3++) {
    EXPECT_EQ(*it_3, primes[i]);
  }
}
