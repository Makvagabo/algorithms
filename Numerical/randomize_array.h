//
// Created by Alexander on 09.05.2019.
//

#ifndef ALGORITHMS_NUMERICAL_RANDOMIZE_ARRAY_H_
#define ALGORITHMS_NUMERICAL_RANDOMIZE_ARRAY_H_
namespace Numerical {

template<class T>
void RandomizeArray(PseudoRandomNumberGenerator *generator, T *arr, const int &size) {
  for (int i = 0; i < size; ++i) {
    auto temp = arr[i];
    auto j = generator->random(i, 0, size);
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

} // namespace Numerical
#endif // ALGORITHMS_NUMERICAL_RANDOMIZE_ARRAY_H_
