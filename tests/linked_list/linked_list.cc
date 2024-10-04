#include "ds/linked_list.h"

#include <gtest/gtest.h>

#include "gtest/gtest.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

class linked_list_tests : public testing::Test {};

TEST_F(linked_list_tests, create_and_clear_linked_list) {
  LinkedList list = create_linked_list();

  ASSERT_EQ(list.head->value, INT_MIN);
  ASSERT_EQ(list.tail, list.head);
  ASSERT_EQ(list.size, 0);

  clear_linked_list(&list);

  ASSERT_EQ(list.head, nullptr);
  ASSERT_EQ(list.tail, nullptr);
  ASSERT_EQ(list.size, 0);
}

TEST_F(linked_list_tests, create_and_insert_elements_at_the_beginning) {
  LinkedList list = create_linked_list();

  insert_into_linked_list(&list, 0, 15);
  insert_into_linked_list(&list, 0, 3);

  ASSERT_NE(list.head->next, nullptr);
  ASSERT_EQ(list.head->next->value, 3);
  ASSERT_EQ(list.head->next->next->value, 15);
  ASSERT_EQ(list.tail->value, list.head->next->next->value);
  ASSERT_EQ(list.size, 2);
}

TEST_F(linked_list_tests, create_and_insert_elements_at_the_end) {
  LinkedList list = create_linked_list();

  insert_into_linked_list(&list, 0, 15);
  insert_into_linked_list(&list, 1, 3);

  ASSERT_EQ(list.head->next->value, 15);
  ASSERT_EQ(list.head->next->next->value, 3);
  ASSERT_EQ(list.tail, list.head->next->next);
  ASSERT_EQ(list.size, 2);
}

TEST_F(linked_list_tests, create_and_insert_elements_at_the_middle) {
  LinkedList list = create_linked_list();

  insert_into_linked_list(&list, 0, 15);
  insert_into_linked_list(&list, 1, 3);
  insert_into_linked_list(&list, 1, 7);

  ASSERT_EQ(list.head->next->value, 15);
  ASSERT_EQ(list.head->next->next->value, 7);
  ASSERT_EQ(list.head->next->next->next->value, 3);
  ASSERT_EQ(list.tail, list.head->next->next->next);
  ASSERT_EQ(list.size, 3);
}

TEST_F(linked_list_tests, remove_elements_from_the_beginning) {
  LinkedList list = create_linked_list();

  insert_into_linked_list(&list, 0, 15);
  insert_into_linked_list(&list, 1, 3);

  remove_from_linked_list(&list, 0);

  ASSERT_EQ(list.head->next->value, 3);
  ASSERT_EQ(list.head->next->next, nullptr);
  ASSERT_EQ(list.tail, list.head->next);
  ASSERT_EQ(list.size, 1);
}

TEST_F(linked_list_tests, remove_elements_from_the_end) {
  LinkedList list = create_linked_list();

  insert_into_linked_list(&list, 0, 15);
  insert_into_linked_list(&list, 1, 3);

  remove_from_linked_list(&list, 1);

  ASSERT_EQ(list.head->next->value, 15);
  ASSERT_EQ(list.head->next->next, nullptr);
  ASSERT_EQ(list.tail, list.head->next);
  ASSERT_EQ(list.size, 1);
}

TEST_F(linked_list_tests, remove_elements_from_the_middle) {
  LinkedList list = create_linked_list();

  insert_into_linked_list(&list, 0, 15);
  insert_into_linked_list(&list, 1, 3);
  insert_into_linked_list(&list, 2, 7);

  remove_from_linked_list(&list, 1);

  ASSERT_EQ(list.head->next->value, 15);
  ASSERT_EQ(list.head->next->next->value, 7);
  ASSERT_EQ(list.tail, list.head->next->next);
  ASSERT_EQ(list.tail->value, 7);
  ASSERT_EQ(list.size, 2);
}