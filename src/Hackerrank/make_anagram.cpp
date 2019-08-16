//
// Created by Alexander on 16.08.2019.
//

#include <vector>

#include "make_anagram.h"

int Hackerrank::makeAnagram(const std::string &a, const std::string &b) {
  int count = 0;
  std::vector<bool> vis(b.size(), false);
  for (char i : a) {
    bool find = false;
    for (size_t j = 0; j < b.size(); ++j) {
      if (i == b[j] && !vis[j]) {
        find = true;
        vis[j] = true;
        break;
      }
    }
    if (!find) {
      count++;
    }
  }
  for (auto v : vis) {
    if (!v) count++;
  }
  return count;
}
