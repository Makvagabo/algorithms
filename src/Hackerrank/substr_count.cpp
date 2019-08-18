//
// Created by Alexander on 18.08.2019.
//

#include "substr_count.h"

long Hackerrank::substrCount(int n, const std::string &s) {
  long count = n;

  size_t i = 0;
  while (i < n - 1) {
    int k = 1;
    for (size_t l = i + 1; l < n; ++l) {
      if (s[i] == s[l]) {
        count++;
        k++;
      } else {
        for (auto r = l + 1; k > 0 && r <= n; ++r, --k) {
          if (s[i] != s[r]) break;
        }
        if (!k) {
          count++;
        }
        break;
      }
    }
    i++;
  }

  return count;
}
