//
// Created by Alexander on 15.06.2019.
//

#include <math.h>

#include "find_zero.h"

float Numerical::FindZero(float (*f)(float), float (*dfdx)(float), float init_guess, float max_error) {
  auto x = init_guess;
  for (int i = 0; i < 100; ++i) {
    auto y = f(x);
    if (std::abs(y) < max_error) break;

    x -= y / dfdx(x);
  }
  return x;
}
