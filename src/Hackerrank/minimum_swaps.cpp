//
// Created by Alexander on 11.08.2019.
//

#include <vector>
#include <algorithm>

#include "minimum_swaps.h"

namespace Hackerrank {

int minimumSwaps(std::vector<int> arr) {
  int swaps = 0;
  int size = arr.size();

  std::pair<int, int> arr_pos[size];
  for (int i = 0; i < size; ++i) {
    arr_pos[i].first = arr[i];
    arr_pos[i].second = i;
  }

  std:sort(arr_pos, arr_pos+size);

  std::vector<bool> vis(size, false);

  for (int i = 0; i < size; ++i) {
    if (vis[i] || arr_pos[i].second == i) continue;

    int cycle_size = 0;
    int j = i;
    while (!vis[j]) {
      vis[j] = true;

      j = arr_pos[j].second;
      cycle_size++;
    }

    if (cycle_size > 0) {
      swaps += (cycle_size - 1);
    }
  }

  return swaps;
}

}
