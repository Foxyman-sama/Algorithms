#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int* ptr;
  int size;
  int capacity;
} DynamicArray;

DynamicArray create_array(int capacity);

void clear_array(DynamicArray* array);

bool insert_into_array(DynamicArray* array, int index, int elem);

bool remove_from_array(DynamicArray* array, int index);

int get(DynamicArray* array, int index);

bool push_back(DynamicArray* array, int elem);

#endif