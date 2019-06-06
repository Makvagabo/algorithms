//
// Created by Alexander on 15.05.2019.
//

#ifndef ALGORITHMS_NUMERICAL_RAISE_TO_POWER_H_
#define ALGORITHMS_NUMERICAL_RAISE_TO_POWER_H_

namespace Numerical {

/**
 * Fast rise to power
 * Foundation is a two mathematical rules: a^(2*m) = (a^m)^2, a^(m+n) = a^m * a*n
 * @tparam T Better experience with Numerical::BigInteger
 * @param a Input number
 * @param p Power
 * @return T
 */
template <class T>
T RaiseToPower(T a, int p);

} // namespace Numerical

#include "raise_to_power.hpp"

#endif //ALGORITHMS_NUMERICAL_RAISE_TO_POWER_H_
