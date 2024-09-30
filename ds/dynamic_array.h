#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

#include <cstdlib>

struct DynamicArray {
  int* ptr;
  int size;
  int capacity;
};

inline struct DynamicArray create_array(int capacity) {
  if (capacity < 1) {
    abort();
  }

  struct DynamicArray result = { (int*)calloc(capacity, sizeof(int)), 0, capacity };
  return result;
}

inline void clear_array(struct DynamicArray* array) {
  free(array->ptr);
  array->ptr = NULL;
  array->size = 0;
  array->capacity = 0;
}

inline void insert_into_array(struct DynamicArray* array, int index, int elem) {
  if (index < 0 || index > array->size) {
    abort();
  }

  if (array->capacity <= array->size) {
    array->capacity *= 2;
    array->ptr = (int*)realloc(array->ptr, array->capacity);
  }

  if (index != array->size) {
    int* temp = (int*)calloc(array->size - index, sizeof(array->ptr[0]));
    for (int i = index; i < array->size; ++i) {
      temp[i - index] = array->ptr[i];
    }

    array->ptr[index] = elem;
    for (int i = index + 1; i < array->size + 1; ++i) {
      array->ptr[i] = temp[i - index - 1];
    }
  } else {
    array->ptr[index] = elem;
  }

  ++array->size;
}

inline void remove_from_array(struct DynamicArray* array, int index) {
  if (index < 0 || index >= array->size) {
    abort();
  }

  if (index != array->size) {
    int* temp = (int*)calloc(array->size - index - 1, sizeof(array->ptr[0]));
    for (int i = index + 1; i < array->size; ++i) {
      temp[i - index - 1] = array->ptr[i];
    }

    for (int i = index; i < array->size - 1; ++i) {
      array->ptr[i] = temp[i - index];
    }
  }

  --array->size;
}

inline int get(struct DynamicArray* array, int index) {
  if (index < 0 || index >= array->size) {
    abort();
  }

  return array->ptr[index];
}

#endif