#include "algorithms/binary_search.h"

#include <gtest/gtest.h>

#include "ds/dynamic_array.h"
#include "gtest/gtest.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

class binary_search_tests : public testing::Test {};

TEST_F(binary_search_tests, find_in_array_with_size_one) {
  DynamicArray array = create_array(1);
  insert_into_array(&array, 0, 321);

  const int actual = binary_search(&array, 0, array.size - 1, 321);

  ASSERT_EQ(0, actual);
}

TEST_F(binary_search_tests, find_in_array_with_size_four) {
  DynamicArray array = create_array(1);

  push_back(&array, 1);
  push_back(&array, 23);
  push_back(&array, 33);
  push_back(&array, 100);

  const int actual = binary_search(&array, 0, array.size - 1, 33);

  ASSERT_EQ(2, actual);
}