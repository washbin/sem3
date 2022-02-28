#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};
typedef struct node node_t;

void printList(node_t *head) {
  node_t *temp = head;
  while (temp != NULL) {
    printf("%d - ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

node_t *create_new_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
  node_to_insert->next = *head;
  *head = node_to_insert;
  return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode) {
  newnode->next = node_to_insert_after->next;
  node_to_insert_after->next = newnode;
}

node_t *find_node(node_t *head, int value) {
  node_t *temp = head;
  while (temp != NULL) {
    if (temp->value == value) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void remove_node(node_t **head, node_t *node_to_remove) {
  if (*head == node_to_remove) {
    *head = node_to_remove->next;
    return;
  }
  node_t *temp = *head;
  while (temp->next != NULL && temp->next != node_to_remove) {
    temp = temp->next;
  }
  if (temp->next == NULL) {
    return;
  }
  temp->next = node_to_remove->next;
  node_to_remove->next = NULL;
}

int main() {
  node_t *head = NULL;
  node_t *tmp;

  for (int i = 0; i < 25; i++) {
    tmp = create_new_node(i);
    insert_at_head(&head, tmp);
  }

  tmp = find_node(head, 13);
  printf("found node with value %d\n", tmp->value);

  insert_after_node(tmp, create_new_node(23));

  printList(head);

  return 0;
}
