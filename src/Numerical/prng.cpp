//
// Created by Alexander on 02.05.2019.
//

#include "Numerical/prng.h"

namespace Numerical {

PRNG::PRNG() : a_(7), b_(5), m_(11), x_(0), prev(0) {}
PRNG::PRNG(int a, int b, int m) : a_(a), b_(b), m_(m), x_(0), prev(0) {}

unsigned int PRNG::random(unsigned int iterations, unsigned int min, unsigned int max) {
  if (!iterations) iterations = 1;

  int result = 0;
  int safe_prev = prev;
  do {
    for (int i = 0; i < iterations; ++i) {
      x_ = (a_ * x_ + b_) % m_;
    }
    auto row_result = min + (static_cast<double>(x_) / m_) * (max - min);
    result = static_cast<int>(row_result);

    if (safe_prev == result) continue;

  } while (result == prev);

  prev = result;

  return result;
}

}  // namespace Numerical
