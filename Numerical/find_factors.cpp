//
// Created by Alexander on 20.05.2019.
//

#include <math.h>

#include "find_factors.h"

namespace Numerical {

std::vector<int> FindFactors(int number) {
  std::vector<int> list_of_integer;

  while (number % 2 == 0) {
    list_of_integer.push_back(2);
    number /= 2;
  }

  int i = 3;
  auto max_factor = std::sqrt(number);
  while (i <= max_factor) {
    while (number % i == 0) {
      list_of_integer.push_back(i);
      number /= i;
      max_factor = std::sqrt(number);
    }

    i += 2;
  }

  if (number > 1) list_of_integer.push_back(number);

  return list_of_integer;
}

} // namespace Numerical
