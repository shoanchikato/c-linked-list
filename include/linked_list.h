#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

Node *linked_list_init_node(void *data);
void linked_list_insert(Node *head, void *data);

void free_linked_list(Node *list);

int linked_list_remove_at(Node **head, size_t index);
int linked_list_insert_at(Node **head, size_t index, void *data);

int linked_list_pop_back(Node **head);
int linked_list_pop_front(Node **head);
void linked_list_push_back(Node *head, void *data);
void linked_list_push_front(Node **head, void *data);

#endif // LINKED_LIST_H