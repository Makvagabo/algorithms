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

void raise_to_power_example() {
  cout << endl << "Example raise to power:" << endl;

  double a = 3; int p = 33;
  // 3 is a smallest number after 2, 33 is max power for double
  cout << a << " to power " << p << " = " << std::fixed << RaiseToPower(a, p);
  cout << endl;
}
void find_factors_example() {
  cout << endl << "Example find factors:" << endl;

  int number = 126;

  cout << "Factors of " << number << ": ";
  for (auto factor : FindFactors(number)) {
    cout << factor << " ";
  }

  cout << endl;
}
void find_primes_example() {
  cout << endl << "Example find primes:" << endl;

  int max = 100;
  cout << "Primes number from 2 to " << max << ": " << endl;
  auto primes = FindPrimes(max);
  for (auto item : primes) {
    cout << item << " ";
  }
  cout << endl;
}
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
void big_integer_example() {
  cout << endl << "Example big integer:" << endl;

  std::string n_0 = "5";
  std::string n_1 = "4294967296";
  std::string n_2 = "9007199254740992";
  std::string n_3 = "9007199254740992";

  b_int b_int0(n_0), b_int1(n_1), b_int2(n_2), b_int3(n_3);
  cout << n_3 << " + " << n_2 << " - " << n_1 << " = " << (((b_int2 + b_int3) * b_int0) - b_int1);
}

} // namespace Numerical
