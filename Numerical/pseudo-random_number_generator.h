//
// Created by Alexander on 02.05.2019.
//

#ifndef ALGORITHMS_NUMERICAL_PSEUDO_RANDOM_NUMBER_GENERATOR_H_
#define ALGORITHMS_NUMERICAL_PSEUDO_RANDOM_NUMBER_GENERATOR_H_
namespace Numerical {

class PseudoRandomNumberGenerator {
  int a_, b_, m_;
  int x_;
 public:
  PseudoRandomNumberGenerator();
  explicit PseudoRandomNumberGenerator(int, int, int);
  int random(unsigned int, unsigned int min = 0, unsigned int max = 100);
};

} // namespace Numerical
#endif // ALGORITHMS_NUMERICAL_PSEUDO_RANDOM_NUMBER_GENERATOR_H_
