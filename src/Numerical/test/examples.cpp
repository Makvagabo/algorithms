//
// Created by Alexander on 09.05.2019.
//

#include <cstdint>
#include <iostream>
#include <string>

#include "big_integer.h"

#include "prng.h"
#include "randomize_array.h"
#include "gcd.h"
#include "raise_to_power.h"
#include "find_factors.h"
#include "find_primes.h"
#include "is_prime.h"

#include "examples.h"

namespace Numerical {

using std::cout, std::endl;

void is_prime_example() {
  cout << endl << "Example prime test:" << endl;

  uint64_t p = 19;
  auto is_prime = IsPrime(p, 10);

  cout << p << " is ";
  if (is_prime) {
    cout << "probably prime";
  } else {
    cout << "composite";
  }

  cout << endl;
}


} // namespace Numerical
