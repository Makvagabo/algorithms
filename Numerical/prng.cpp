//
// Created by Alexander on 02.05.2019.
//

#include "prng.h"

namespace Numerical {

PRNG::PRNG() : a_(7), b_(5), m_(11), x_(0) {}
PRNG::PRNG(int a, int b, int m) : a_(a), b_(b), m_(m), x_(0) {}

int PRNG::random(unsigned int iterations, unsigned int min, unsigned int max) {
  for (int i = 0; i < iterations; ++i) {
    x_ = (a_ * x_ + b_) % m_;
  }
  double result = min + (static_cast<double>(x_) / m_) * (max - min);
  return static_cast<int>(result);
}

}  // namespace Numerical
