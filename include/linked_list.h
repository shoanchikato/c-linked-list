#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

struct Node {
  void *data;
  struct Node *next;
};

struct Node *linked_list_init_node(void *data);
void linked_list_insert(struct Node *head, void *data);

void free_linked_list(struct Node *list);

int linked_list_remove_at(struct Node **head, size_t index);
int linked_list_insert_at(struct Node **head, size_t index, void *data);

int linked_list_pop_back(struct Node **head);
int linked_list_pop_front(struct Node **head);
void linked_list_push_back(struct Node *head, void *data);
void linked_list_push_front(struct Node **head, void *data);

#endif // LINKED_LIST_H