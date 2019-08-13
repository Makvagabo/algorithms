//
// Created by Alexander on 14.08.2019.
//

#include <vector>

#include "array_manipulation.h"

long Hackerrank::arrayManipulation(int n, const std::vector<std::vector<int>>& queries) {
  std::vector<long> z(n, 0);

  for (auto q : queries) {
    for (int i = q[0] - 1; i < q[1]; ++i) {
      z[i] += q[2];
    }
  }

  long max = 0;
  for (auto v : z) {
    max = v > max ? v : max;
  }

  return max;
}
