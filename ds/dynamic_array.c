#include "dynamic_array.h"

struct DynamicArray create_array(int capacity) {
  if (capacity < 1) {
    abort();
  }

  struct DynamicArray result = { (int*)calloc(capacity, sizeof(int)), 0, capacity };
  return result;
}
