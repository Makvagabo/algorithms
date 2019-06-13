//
// Created by Alexander on 14.06.2019.
//

#ifndef ALGORITHMS_NUMERICAL_INTEGRATE_ADAPTIVE_MIDPOINT_H_
#define ALGORITHMS_NUMERICAL_INTEGRATE_ADAPTIVE_MIDPOINT_H_
namespace Numerical {

float RectangleRule(float (*f)(float), float x_min, float x_max, unsigned int count_intervals);

float  TrapezoidRule(float (*f)(float), float x_min, float x_max, unsigned int count_intervals);

float IntegrateAdaptiveMidpoint(float (*f)(float), float x_min, float x_max, unsigned int count_intervals);

} // namespace Numerical
#endif //ALGORITHMS_NUMERICAL_INTEGRATE_ADAPTIVE_MIDPOINT_H_
