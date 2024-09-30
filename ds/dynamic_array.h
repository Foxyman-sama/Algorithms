#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

struct DynamicArray {
  int* ptr;
  int size;
  int capacity;
};

struct DynamicArray create_array(int capacity) {
  struct DynamicArray result = { (int*)calloc(capacity, sizeof(int)), 0, capacity };
  return result;
}

#endif