#include "../include/linked_list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Node *linked_list_init_node(void *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "error allocating memory for a node\n");
    return NULL;
  }

  node->data = data;
  node->next = NULL;

  return node;
}

void linked_list_insert(Node *head, void *data) {
  if (head == NULL) {
    return;
  }
  
  if (head->next == NULL) {
    Node *new_node = linked_list_init_node(data);
    head->next = new_node;
    return;
  }

  Node *prev_head = head->next;
  linked_list_insert(prev_head, data);
}

void free_linked_list(Node *list) {
  if (list == NULL) {
    return;
  }

  Node *new_head = list->next;
  free(list);
  free_linked_list(new_head);
}

int linked_list_remove_at(Node **head, size_t index) {
  if (head == NULL || *head == NULL) {
    fprintf(stderr, "linked list is NULL\n");
    return 1;
  }

  Node *current_node = *head;
  Node *prev_node = NULL;
  int idx = 0;

  if (index == 0) {
    Node *next_node = current_node->next;
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

int linked_list_pop_back(Node **head) {
  if (head == NULL || *head == NULL) {
    fprintf(stderr, "linked list is NULL\n");
    return 1;
  }

  Node *fixed_head = *head;
  Node *current_node = *head;
  Node *prev_node = NULL;

  if (fixed_head->next == NULL) {
    Node *next_node = current_node->next;
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

int linked_list_pop_front(Node **head) { return linked_list_remove_at(head, 0); }

void linked_list_push_back(Node *head, void *data) {
  return linked_list_insert(head, data);
}

int linked_list_insert_at(Node **head, size_t index, void *data) {
  if (head == NULL || *head == NULL) {
    fprintf(stderr, "linked list is NULL\n");
    return 1;
  }

  Node *current_node = *head;
  Node *prev_node = NULL;
  int idx = 0;

  if (index == 0) {
    Node *new_node = linked_list_init_node(data);
    new_node->next = current_node;
    *head = new_node;
    return 0;
  }

  while (current_node != NULL) {

    if (idx == index) {
      Node *new_node = linked_list_init_node(data);
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

void linked_list_push_front(Node **head, void *data) {
  linked_list_insert_at(head, 0, data);
}