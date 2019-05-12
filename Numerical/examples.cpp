//
// Created by Alexander on 09.05.2019.
//

#include <iostream>

#include "pseudo-random_number_generator.h"
#include "randomize_array.h"

#include "examples.h"

namespace Numerical {

using std::cout, std::endl;

void pseudo_random_number_generator_example() {
  cout << "Example pseudo-random number generator:" << endl;

  PseudoRandomNumberGenerator gen(14, 3, 1879);
  for (int i = 1; i < 20; ++i) {
    cout << gen.random(i) << " ";
  }
  cout << endl;
}
void randomize_array_example() {
  cout << endl << "Example randomize array:" << endl;

  cout << "Input:  ";
  const int SIZE = 10;
  int arr[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    arr[i] = 10 * (i + 1);
    cout << arr[i] << " ";
  }
  cout << endl;

  auto *gen  = new PseudoRandomNumberGenerator(14, 3, 1879);
  RandomizeArray(gen, arr, SIZE);

  cout << "Output: ";
  for (auto item : arr) {
    cout << item << " ";
  }
  cout << endl;
}

} // namespace Numerical
