#include "../include/linked_list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node *linked_list_init_node(void *data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL) {
    fprintf(stderr, "error allocating memory for a node\n");
    return NULL;
  }

  node->data = data;
  node->next = NULL;

  return node;
}

void linked_list_insert(struct Node *head, void *data) {
  if (head == NULL) {
    return;
  }
  
  if (head->next == NULL) {
    struct Node *new_node = linked_list_init_node(data);
    head->next = new_node;
    return;
  }

  struct Node *prev_head = head->next;
  linked_list_insert(prev_head, data);
}

void free_linked_list(struct Node *list) {
  if (list == NULL) {
    return;
  }

  struct Node *new_head = list->next;
  free(list);
  free_linked_list(new_head);
}

int linked_list_remove_at(struct Node **head, size_t index) {
  if (head == NULL || *head == NULL) {
    fprintf(stderr, "linked list is NULL\n");
    return 1;
  }

  struct Node *current_node = *head;
  struct Node *prev_node = NULL;
  int idx = 0;

  if (index == 0) {
    struct Node *next_node = current_node->next;
    *head = next_node;

    free(current_node);
    return 0;
  }

  while (current_node != NULL) {

    if (idx == index) {
      prev_node->next = current_node->next;
      free(current_node);
      return 0;
    }

    prev_node = current_node;
    current_node = current_node->next;
    idx += 1;
  }

  fprintf(stderr, "index %zu out of range\n", index);
  return 1;
}

int linked_list_pop_back(struct Node **head) {
  if (head == NULL || *head == NULL) {
    fprintf(stderr, "linked list is NULL\n");
    return 1;
  }

  struct Node *fixed_head = *head;
  struct Node *current_node = *head;
  struct Node *prev_node = NULL;

  if (fixed_head->next == NULL) {
    struct Node *next_node = current_node->next;
    *head = next_node;

    free(current_node);
    return 0;
  }

  while (current_node != NULL) {

    if (current_node->next == NULL) {
      prev_node->next = current_node->next;
      free(current_node);
      return 0;
    }

    prev_node = current_node;
    current_node = current_node->next;
  }

  fprintf(stderr, "error occurred deleting node\n");
  return 1;
}

int linked_list_pop_front(struct Node **head) { return linked_list_remove_at(head, 0); }

void linked_list_push_back(struct Node *head, void *data) {
  return linked_list_insert(head, data);
}

int linked_list_insert_at(struct Node **head, size_t index, void *data) {
  if (head == NULL || *head == NULL) {
    fprintf(stderr, "linked list is NULL\n");
    return 1;
  }

  struct Node *current_node = *head;
  struct Node *prev_node = NULL;
  int idx = 0;

  if (index == 0) {
    struct Node *new_node = linked_list_init_node(data);
    new_node->next = current_node;
    *head = new_node;
    return 0;
  }

  while (current_node != NULL) {

    if (idx == index) {
      struct Node *new_node = linked_list_init_node(data);
      new_node->next = current_node;
      prev_node->next = new_node;
      return 0;
    }

    prev_node = current_node;
    current_node = current_node->next;
    idx += 1;
  }

  fprintf(stderr, "index %zu out of range\n", index);
  return 1;
}

void linked_list_push_front(struct Node **head, void *data) {
  linked_list_insert_at(head, 0, data);
}