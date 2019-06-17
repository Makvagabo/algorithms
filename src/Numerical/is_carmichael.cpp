//
// Created by Alexander on 15.06.2019.
//

#include <iostream>

#include "Numerical/is_carmichael.h"
#include "Numerical/gcd.h"
#include "Numerical/raise_to_power.h"
#include "Numerical/big_integer.h"

bool Numerical::IsCarmichael(unsigned int number, unsigned int max_tests) {
  if (number % 2) {
    for (int n = 2; n < number && max_tests > n; ++n) {
      // for mutually simple
      if (Numerical::GCD(number, n) == 1) {
        auto pow = Numerical::RaiseToPower<b_int>(n, number - 1);
        if (pow % number != 1) {
          return false;
        }
      }
    }
    return true;
  }

  return false;
}
