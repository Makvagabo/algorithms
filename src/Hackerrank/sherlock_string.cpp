//
// Created by Alexander on 16.08.2019.
//

#include <string>
#include <map>
#include <cmath>

#include "sherlock_string.h"

bool Hackerrank::isValid(const std::string &s) {
  std::map<char, int> fq;
  std::map<int, int> f_fq;

  for (auto w : s) {
    if (fq[w]) {
      fq[w]++;
    } else {
      fq[w] = 1;
    }
  }

  int i = 0;
  for (auto f : fq) {
    if (f_fq[f.second]) {
      f_fq[f.second]++;
    } else if (i < 2) {
      f_fq[f.second] = 1;
      i++;
    } else {
      return false;
    }
  }

  if (
      f_fq.size() == 1 ||
      (f_fq.begin()->first == 1 && f_fq.begin()->second == 1) ||
      (f_fq.rbegin()->first == 1 && f_fq.rbegin()->second == 1)
  ) return true;

  int diff = f_fq.begin()->first - f_fq.rbegin()->first;
  if (std::abs(diff) > 1) {
    return false;
  }

  return f_fq.begin()->second == 1 || f_fq.rbegin()->second == 1;
}
