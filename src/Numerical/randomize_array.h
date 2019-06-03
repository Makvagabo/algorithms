//
// Created by Alexander on 09.05.2019.
//

#ifndef ALGORITHMS_NUMERICAL_RANDOMIZE_ARRAY_H_
#define ALGORITHMS_NUMERICAL_RANDOMIZE_ARRAY_H_
namespace Numerical {

template<class T>
void RandomizeArray(PRNG *generator, T *arr, const int &size);

} // namespace Numerical

#include "randomize_array.hpp"

#endif // ALGORITHMS_NUMERICAL_RANDOMIZE_ARRAY_H_
