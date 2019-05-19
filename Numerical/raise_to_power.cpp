//
// Created by Alexander on 15.05.2019.
//

#include <map>
#include <iostream>

#include "raise_to_power.h"

namespace Numerical {

double RaiseToPower(double a, int p) {
  if (p == 0) {
    return 1;
  }

  if (p == 1) {
    return a;
  }

  std::map<int, double> computed_pow_of2;

  int n = 1;
  computed_pow_of2[n] = a;
  n += n;

  while (n + 1 <= p) {
    computed_pow_of2[n] = a *= a;
    n += n;
  }
  n /= 2;

  int diff = p - n;
  if (computed_pow_of2[diff] != 0) {
    return computed_pow_of2[n] * computed_pow_of2[diff];
  }

  double multipliers = 1;
  auto it = computed_pow_of2.begin();

  if (diff % 2) {
    diff--;
    multipliers *= it->second;
  }
  it++;

  if (computed_pow_of2[diff] == 0) {
    int start = n / 2;
    if (diff < start) {
      start /= 2;
    }
    multipliers *= computed_pow_of2[start];
    diff -= start;

    while (diff != 0) {
      multipliers *= it->second;
      if (diff - it->first < 0) {
        it = computed_pow_of2.begin();
      } else {
        diff -= it->first;
      }
      it++;
    }
  }

  return computed_pow_of2[n] * multipliers;
}

} // namespace Numerical
