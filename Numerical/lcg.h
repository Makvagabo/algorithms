//
// Created by Alexander on 02.05.2019.
//

#ifndef ALGORITHMS_LCG_H
#define ALGORITHMS_LCG_H
namespace Numerical {

class LCG {
  int A, B, M;
  int X;
 public:
  explicit LCG();
  explicit LCG(int a, int b, int m);
  int random(unsigned int iterations, unsigned int min = 0, unsigned int max = 100);
};

}
#endif //ALGORITHMS_LCG_H
