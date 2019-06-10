//
// Created by Aleskander on 10.06.2019.
//

#include "rectangle_rule.h"

namespace Numerical {

float RectangleRule(float (*f)(float), float x_min, float x_max, unsigned int count_intervals) {
  auto width = (x_max - x_min) / count_intervals;

  float total_area = 0.0;
  auto x = x_min;
  for (int i = 0; i < count_intervals; ++i) {
    total_area += width * f(x);
  }

  return total_area;
}

} // namespace Numerical
