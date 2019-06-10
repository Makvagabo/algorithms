//
// Created by Aleskander on 10.06.2019.
//

#ifndef ALGORITHMS_NUMERICAL_RECTANGLE_RULE_H_
#define ALGORITHMS_NUMERICAL_RECTANGLE_RULE_H_
namespace Numerical {

float RectangleRule(float (*f)(float), float x_min, float x_max, unsigned int count_intervals);

} // namespace Numerical
#endif //ALGORITHMS_SRC_NUMERICAL_RECTANGLE_RULE_H_
