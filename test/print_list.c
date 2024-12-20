#include <stdio.h>
#include "../include/linked_list.h"
#include "print_list.h"

void print_int_list(Node *list) {
  if(list == NULL) {
    printf("END\n\n");
    return;
  }

  printf("%d->\n", *(int *)list->data);
  Node *new_head = list->next;
  print_int_list(new_head);
}

void print_str_list(Node *list) {
  if(list == NULL) {
    printf("END\n\n");
    return;
  }

  printf("%s->\n", (char *)list->data);
  Node *new_head = list->next;
  print_str_list(new_head);
}