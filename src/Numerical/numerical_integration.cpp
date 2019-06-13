//
// Created by Alexander on 14.06.2019.
//

#include "numerical_integration.h"

namespace Numerical {

float RectangleRule(float (*f)(float), float x_min, float x_max, unsigned int count_intervals) {
  auto dx = (x_max - x_min) / count_intervals;

  float total_area = 0.0;
  auto x = x_min;
  for (int i = 0; i < count_intervals; ++i) {
    total_area += dx * f(x);
    x += dx;
  }

  return total_area;
}

float TrapezoidRule(float (*f)(float), float x_min, float x_max, unsigned int count_intervals) {
  auto dx = (x_max - x_min) / count_intervals;

  float total_area = 0.0;
  auto x = x_min;
  for (int i = 0; i < count_intervals; ++i) {
    total_area += dx * (f(x) + f(x + dx)) / 2;
    x += dx;
  }

  return total_area;
}

float IntegrateAdaptiveMidpoint(float (*f)(float), float x_min, float x_max, unsigned int count_intervals) {

}

} // namespace Numerical
