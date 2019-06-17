//
// Created by Alexander on 21.05.2019.
//

#include <cmath>
#include <list>

#include "find_primes.h"

namespace Numerical {

std::list<int> FindPrimes(int max_number) {
  const int SIZE = max_number + 1;
  bool is_composite[SIZE];

  for (int i = 0; i < SIZE; ++i) {
    is_composite[i] = i < 2 ? true : i > 2 && !(i % 2);
  }

  int next_prime = 3;
  auto stop_at = std::sqrt(max_number);
  while (next_prime <= stop_at) {

    int step = next_prime * 2;
    for (int i = next_prime * 3; i < max_number; i += step) {
      is_composite[i] = true;
    }

    next_prime += 2;
    while (next_prime <= max_number && is_composite[next_prime]) {
      next_prime += 2;
    }
  }

  std::list<int> primes;
  for (int j = 2; j <= max_number; ++j) {
    if (!is_composite[j]) primes.push_back(j);
  }

  return primes;
}

} // namespace Numerical
