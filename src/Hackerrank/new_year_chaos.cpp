//
// Created by Alexander on 11.08.2019.
//

#include "new_year_chaos.h"

namespace Hackerrank {

int minimumBribes(std::vector<int> q) {
  int size = q.size();
  int count_bribes = 0;

  int start = 0;

  bool first = true;
  for (int i = 0; i < size; i++) {
    if (first && q[i] == i + 1) {
      start++;
    }

    int range = q[i] - (i + 1);

    if (range > 2) {
      return -1;
    }

    first = false;

    /**
     * Fast algorithm
     */
    for (int j = std::max(0, q[i] - 2); j < i; j++) {
      if (q[j] > q[i]) {
        count_bribes++;
      }
    }
  }

  /**
   * Slow algorithm with sorting
   */
  // while (start < size - 1) {
  //   bool first = true;
  //   for (int i = start; i < size - 1; i++) {
  //     if (first && q[i] == i + 1) {
  //       start = i + 1;
  //       first = false;
  //       continue;
  //     }
  //
  //     int current = q[i];
  //     int next = q[i + 1];
  //
  //     if (current > next) {
  //       q[i] = next;
  //       q[i + 1] = current;
  //
  //       if (current == i + 2) {
  //         first = false;
  //       }
  //
  //       count_bribes++;
  //     }
  //   }
  // }

  return count_bribes;
}

}
