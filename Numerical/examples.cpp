//
// Created by Alexander on 09.05.2019.
//

#include <cstdint>
#include <iostream>

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

void pseudo_random_number_generator_example() {
  cout << "Example pseudo-random number generator:" << endl;

  PRNG generator(14, 3, 1879);
  for (int i = 1; i < 20; ++i) {
    cout << generator.random(i) << " ";
  }
  cout << endl;
}
void randomize_array_example() {
  cout << endl << "Example randomize array:" << endl;

  cout << "Input:  ";
  const int SIZE = 10;
  int arr[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    arr[i] = 10 * (i + 1);
    cout << arr[i] << " ";
  }
  cout << endl;

  auto *generator  = new PRNG(14, 3, 1879);
  RandomizeArray(generator, arr, SIZE);

  cout << "Output: ";
  for (auto item : arr) {
    cout << item << " ";
  }
  cout << endl;
}
void greatest_common_devisor_example() {
  cout << endl << "Example greatest common devisor:" << endl;

  int a = 4851, b = 3003;
  cout << "GCD(" << a << ", " << b << ") = " << GCD(a, b);
  cout << endl;
}
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

} // namespace Numerical
