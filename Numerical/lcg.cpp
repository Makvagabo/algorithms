// Copyright (c) 02.05.2019 Alexander Petropavlovskikh

#include "lcg.h"

namespace Numerical {

LCG::LCG() : A(7), B(5), M(11), X(0) {}
LCG::LCG(int a, int b, int m) : A(a), B(b), M(m), X(0) {}

int LCG::random(unsigned int iterations, unsigned int min, unsigned int max) {
  for (int i = 0; i < iterations; ++i) {
    X = (A * X + B) % M;
  }
  double result = min + (static_cast<double>(X) / M) * (max - min);
  return static_cast<int>(result);
}

}  // namespace Numerical
