//
// Created by Alexander on 02.05.2019.
//

#include "pseudo-random_number_generator.h"

namespace Numerical {

PseudoRandomNumberGenerator::PseudoRandomNumberGenerator() : a_(7), b_(5), m_(11), x_(0) {}
PseudoRandomNumberGenerator::PseudoRandomNumberGenerator(int a, int b, int m) : a_(a), b_(b), m_(m), x_(0) {}

int PseudoRandomNumberGenerator::random(unsigned int iterations, unsigned int min, unsigned int max) {
  for (int i = 0; i < iterations; ++i) {
    x_ = (a_ * x_ + b_) % m_;
  }
  double result = min + (static_cast<double>(x_) / m_) * (max - min);
  return static_cast<int>(result);
}

}  // namespace Numerical
