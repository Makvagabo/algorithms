//
// Created by Alexander on 22.05.2019.
//

#include <iostream>

#include "Numerical/is_prime.h"
#include "Numerical/prng.h"
#include "Numerical/randomize_array.h"
#include "Numerical/raise_to_power.h"
#include "Numerical/big_integer.h"

namespace Numerical {

bool IsPrime(int number, int max_tests) {
  if (max_tests >= number) {
    std::cerr << "Max count tests must be less number!";
  }

  int arr[max_tests];
  for (int i = 0; i < max_tests; ++i) {
    arr[i] = i + 1;
  }

  auto *generator  = new PRNG(14, 3, 1879);
  RandomizeArray(generator, arr, max_tests);

  for (int i = 0; i < max_tests; ++i) {
    auto pow = RaiseToPower<b_int>(arr[i], number - 1);
    auto witness = pow % number;
    if (witness != 1) {
      return false;
    }
  }

  return true;
}

} // namespace Numerical
