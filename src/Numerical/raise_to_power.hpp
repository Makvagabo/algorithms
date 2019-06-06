//
// Created by Alexander on 15.05.2019.
//

#include <map>

namespace Numerical {

template <class T>
T RaiseToPower(T a, int p) {
  if (p == 0) {
    return 1;
  }

  if (p == 1) {
    return a;
  }

  std::map<int, T> computed_pow_of2;

  int n = 1;
  computed_pow_of2[n] = a;
  n += n;

  while (n + 1 <= p) {
    auto prev_pow = computed_pow_of2[n/2];
    computed_pow_of2[n] = prev_pow * prev_pow;
    n += n;
  }
  n /= 2;

  int diff = p - n;
  if (computed_pow_of2[diff] != 0) {
    return computed_pow_of2[n] * computed_pow_of2[diff];
  }

  T multipliers = 1;

  if (diff % 2) {
    diff--;
    multipliers *= computed_pow_of2.begin()->second;
  }

  int start = 0;
  while (computed_pow_of2[diff] == 0) {
    start = (start ? start : n) / 2;
    while (diff < start) {
      start /= 2;
    }
    multipliers *= computed_pow_of2[start];
    diff -= start;
  }
  if (diff) {
    multipliers *= computed_pow_of2[diff];
  }

  return computed_pow_of2[n] * multipliers;
}

} // namespace Numerical
