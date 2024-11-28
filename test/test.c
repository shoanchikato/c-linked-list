#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"
#include "print_list.h"

int main() {
  int one[] = {1, 2, 3, 4, 5, 6, 7};

  struct Node *head = linked_list_init_node(&one[0]);
  linked_list_insert(head, &one[1]);
  linked_list_insert(head, &one[2]);
  linked_list_insert(head, &one[3]);
  linked_list_insert(head, &one[4]);

  print_int_list(head);

  // if(linked_list_pop_back(&head)) {
  //   printf("error removing element from list\n");
  //   return 1;
  // }

  linked_list_insert_at(&head, 4, &one[6]);

  print_int_list(head);
  free_linked_list(head);

  return 0;
}