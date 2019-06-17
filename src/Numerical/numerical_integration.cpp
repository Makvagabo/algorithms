//
// Created by Alexander on 14.06.2019.
//

#include "Numerical/numerical_integration.h"

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

float IntegrateAdaptiveMidpoint(float (*f)(float),
                                float x_min,
                                float x_max,
                                unsigned int count_intervals,
                                float max_slice_error) {
  float dx = (x_max - x_min) / count_intervals;

  float total_area = 0;
  float x = x_min;
  for (int i = 0; i < count_intervals; ++i) {
    total_area += SliceArea(f, x, x + dx, max_slice_error);
    x += dx;
  }

  return total_area;
}

float SliceArea(float (*f)(float), float x1, float x2, float max_slice_error) {
  auto y1 = f(x1);
  auto y2 = f(x2);
  auto xm = (x1 + x2) / 2;
  auto ym = f(xm);

  auto area_big = (x2 - x1) * (y1 + y2) / 2;
  auto area_first = (xm - x1) * (y1 + ym) / 2;
  auto area_second = (x2 - xm) * (ym + y2) / 2;
  auto area_composite = area_first + area_second;

  auto error = (area_composite - area_big) / area_big;

  if (error < max_slice_error) return area_composite;

  return SliceArea(f, x1, xm, max_slice_error) + SliceArea(f, xm, x2, max_slice_error);
}

} // namespace Numerical
