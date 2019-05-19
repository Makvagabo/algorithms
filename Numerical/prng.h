//
// Created by Alexander on 02.05.2019.
//

#ifndef ALGORITHMS_NUMERICAL_PRNG_H_
#define ALGORITHMS_NUMERICAL_PRNG_H_
namespace Numerical {
/**
 * Pseudo-random number generator
 */
class PRNG {
  int a_, b_, m_;
  int x_;
 public:
  PRNG();
  explicit PRNG(int, int, int);
  int random(unsigned int, unsigned int min = 0, unsigned int max = 100);
};

} // namespace Numerical
#endif // ALGORITHMS_NUMERICAL_PRNG_H_
