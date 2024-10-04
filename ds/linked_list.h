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

Link get_node(LinkedList* list, int index) {
  Link current = list->head;
  int iter = 0;
  while (iter != index) {
    current = current->next;
    ++iter;
  }

  return current;
}

void clear_linked_list(LinkedList* list) {
  Link current = list->head;
  while (current != list->tail) {
    Link temp = current;
    current = current->next;
    free(temp);
  }

  if (list->head != list->tail) {
    free(list->tail);
  }

  free(list->head);
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void insert_into_linked_list(LinkedList* list, int index, Item elem) {
  Link new_node = (Link)malloc(sizeof(Node));
  new_node->value = elem;

  Link current = get_node(list, index);

  new_node->next = current->next;
  current->next = new_node;

  if (index == list->size) {
    list->tail = new_node;
  }

  ++list->size;
}

void remove_from_linked_list(LinkedList* list, int index) {
  Link current = get_node(list, index);
  Link temp = current->next;
  current->next = temp->next;
  free(temp);

  if (index == list->size - 1) {
    list->tail = current;
  }

  --list->size;
}

Item get(LinkedList* list, int index) {
  Link current = get_node(list, index);
  return current->next->value;
}

#endif