#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "dynamic_array.h"

int binary_search(DynamicArray* array, int l, int r, int found) {
  if (l > r) {
    return -1;
  }

  int m = (l + r) / 2;
  int actual = get(array, m);
  if (found == actual) {
    return m;
  }
  if (l == r) {
    return -1;
  }

  if (found < actual) {
    return binary_search(array, l, m - 1, found);
  } else {
    return binary_search(array, m + 1, r, found);
  }
}

#endif