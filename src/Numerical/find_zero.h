//
// Created by Alexander on 15.06.2019.
//

#ifndef ALGORITHMS_NUMERICAL_FIND_ZERO_H_
#define ALGORITHMS_NUMERICAL_FIND_ZERO_H_
namespace Numerical {

float FindZero(float (*f)(float), float (*dfdx)(float), float init_guess, float max_error);

} // namespace Numerical

#endif //ALGORITHMS_NUMERICAL_FIND_ZERO_H_
