//
// Created by Alexander on 02.06.2019.
//
namespace Numerical {

template<class T>
void RandomizeArray(PRNG *generator, T *arr, const int &size) {
  for (int i = 0; i < size; ++i) {
    auto temp = arr[i];
    auto j = generator->random(i, 0, size);
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

} // namespace Numerical
