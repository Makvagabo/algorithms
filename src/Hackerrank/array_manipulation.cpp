//
// Created by Alexander on 14.08.2019.
//

#include <vector>

#include "array_manipulation.h"

long Hackerrank::arrayManipulation(int n, const std::vector<std::vector<int>> &queries) {
  std::vector<long> z(n + 1, 0);

  for (auto q : queries) {
    z[q[0]] += q[2];
    if (q[1] + 1 <= n) z[q[1] + 1] -= q[2];
  }

  long max = 0;
  long x = 0;
  for (auto v : z) {
    x += v;
    if (x > max) max = x;
  }

  return max;
}
