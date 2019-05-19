//
// Created by Alexander on 12.05.2019.
//

#include "gcd.h"
namespace Numerical {

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
