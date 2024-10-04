#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <climits>
#include <cstdlib>

typedef int Item;

struct Node {
  struct Node* next;
  Item value;
};

typedef struct Node Node;
typedef Node* Link;

typedef struct {
  Link head;
  Link tail;
  int size;
} LinkedList;

LinkedList create_linked_list() {
  LinkedList result;
  result.head = (Link)malloc(sizeof(Node));
  result.head->value = INT_MIN;
  result.head->next = NULL;
  result.tail = result.head;
  result.size = 0;
  return result;
}

void clear_linked_list(LinkedList* list) {
  // Clear list

  free(list->head);
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

#endif