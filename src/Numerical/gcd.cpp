//
// Created by Alexander on 12.05.2019.
//

#include "Numerical/gcd.h"

namespace Numerical {

/**
 * Greatest common devisor or Euclidean algorithm
 */
int GCD(int a, int b) {
  int remainder;
  while (b) {
    remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}

} // namespace Numerical
