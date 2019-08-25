//
// Created by Alexander on 19.08.2019.
//

#include <string>
#include <vector>

#include "common_child.h"

int Hackerrank::commonChild(const std::string &s1, const std::string &s2) {
  const auto size = s1.size();

  std::vector<std::vector<int>> c(size + 1, std::vector<int>(size + 1));

  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      if (s1[i - 1] == s2[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
      else c[i][j] = std::max(c[i][j - 1], c[i - 1][j]);
    }
  }

  return c[size][size];
}
