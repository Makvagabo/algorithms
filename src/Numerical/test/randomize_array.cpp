//
// Created by Alexander on 02.06.2019.
//

#include <gtest/gtest.h>

#include "Numerical/prng.h"
#include "Numerical/randomize_array.h"

TEST(Numerical, RandomizeArray) {
  const int SIZE = 10;
  int arr[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto *generator  = new Numerical::PRNG(14, 3, 1879);
  RandomizeArray(generator, arr, SIZE);

  for (int i = 0; i < SIZE; ++i) {
    EXPECT_NE(arr[i], i);
  }
}
