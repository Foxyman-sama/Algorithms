#include "dynamic_array.h"

DynamicArray create_array(int capacity) {
  if (capacity < 1) {
    abort();
  }

  return { (int*)calloc(capacity, sizeof(int)), 0, capacity };
}

void clear_array(DynamicArray* array) {
  free(array->ptr);
  array->ptr = NULL;
  array->size = 0;
  array->capacity = 0;
}

void increase_capacity_twice(DynamicArray* array);
void make_empty_field_for_inserting(DynamicArray* array, int index);
int* copy_range(DynamicArray* array, int begin, int end);
void insert_element(DynamicArray* array, int index, int elem);

bool insert_into_array(DynamicArray* array, int index, int elem) {
  if (index < 0 || index > array->size) {
    return false;
  }

  if (array->capacity <= array->size) {
    increase_capacity_twice(array);
  }

  if (index != array->size) {
    make_empty_field_for_inserting(array, index);
  }

  insert_element(array, index, elem);

  return true;
}

void increase_capacity_twice(DynamicArray* array) {
  array->capacity *= 2;
  array->ptr = (int*)realloc(array->ptr, array->capacity);
}

void make_empty_field_for_inserting(DynamicArray* array, int index) {
  int* temp = copy_range(array, index, array->size);

  for (int i = index + 1; i < array->size + 1; ++i) {
    array->ptr[i] = temp[i - index - 1];
  }
}

int* copy_range(DynamicArray* array, int begin, int end) {
  int* result = (int*)calloc(end - begin, sizeof(array->ptr[0]));

  for (int i = begin; i < end; ++i) {
    result[i - begin] = array->ptr[i];
  }

  return result;
}

void insert_element(DynamicArray* array, int index, int elem) {
  array->ptr[index] = elem;
  ++array->size;
}

bool remove_from_array(DynamicArray* array, int index) {
  if (index < 0 || index >= array->size) {
    return false;
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

  return true;
}

int get(DynamicArray* array, int index) {
  if (index < 0 || index >= array->size) {
    abort();
  }

  return array->ptr[index];
}

bool push_back(DynamicArray* array, int elem) { return insert_into_array(array, array->size, elem); }
