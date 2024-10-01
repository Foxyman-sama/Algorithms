#include "ds/dynamic_array.h"

#include <gtest/gtest.h>

#include "gtest/gtest.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

class dynamic_array_tests : public testing::Test {};

TEST_F(dynamic_array_tests, create_and_clear_dynamic_array) {
  struct DynamicArray array = create_array(10);
  clear_array(&array);

  ASSERT_EQ(array.ptr, nullptr);
  ASSERT_EQ(array.size, 0);
  ASSERT_EQ(array.capacity, 0);
}

TEST_F(dynamic_array_tests, create_dynamic_array_using_bad_index) {
  ASSERT_DEATH({ struct DynamicArray array = create_array(0); }, "");
}

TEST_F(dynamic_array_tests, insert_into_dynamic_array) {
  struct DynamicArray array = create_array(1);

  insert_into_array(&array, 0, 321);
  insert_into_array(&array, 1, 5);
  insert_into_array(&array, 2, 7);
  insert_into_array(&array, 2, 23);

  ASSERT_EQ(array.ptr[0], 321);
  ASSERT_EQ(array.ptr[1], 5);
  ASSERT_EQ(array.ptr[2], 23);
}

TEST_F(dynamic_array_tests, insert_into_dynamic_array_using_bad_index) {
  struct DynamicArray array = create_array(1);

  insert_into_array(&array, 0, 321);
  ASSERT_EQ(false, insert_into_array(&array, 2, 5));
}

TEST_F(dynamic_array_tests, insert_into_empty_dynamic_array_with_bad_index) {
  struct DynamicArray array = create_array(1);

  ASSERT_EQ(false, insert_into_array(&array, 1, 321));
}

TEST_F(dynamic_array_tests, remove_from_dynamic_array) {
  struct DynamicArray array = create_array(1);

  insert_into_array(&array, 0, 321);
  insert_into_array(&array, 1, 5);
  insert_into_array(&array, 2, 7);

  remove_from_array(&array, 1);

  ASSERT_EQ(array.ptr[0], 321);
  ASSERT_EQ(array.ptr[1], 7);
  ASSERT_EQ(array.size, 2);
}

TEST_F(dynamic_array_tests, remove_from_dynamic_array_using_bad_index) {
  struct DynamicArray array = create_array(1);

  insert_into_array(&array, 0, 321);

  ASSERT_DEATH(remove_from_array(&array, 1), "");
}

TEST_F(dynamic_array_tests, get_element_from_dynamic_array) {
  struct DynamicArray array = create_array(1);
  insert_into_array(&array, 0, 321);

  ASSERT_EQ(321, get(&array, 0));
}

TEST_F(dynamic_array_tests, get_element_from_dynamic_array_using_bad_index) {
  struct DynamicArray array = create_array(1);
  insert_into_array(&array, 0, 321);

  ASSERT_DEATH(get(&array, 1), "");
}