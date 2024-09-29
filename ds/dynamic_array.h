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

inline void push_back(struct DynamicArray* array, int val) { array->ptr[array->size++] = val; }

inline void clear(struct DynamicArray* array) {
  if (array->ptr != NULL) {
    free(array->ptr);
  }
}

#endif