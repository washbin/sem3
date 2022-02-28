#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
  struct node *prev;
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
  new_node->prev = NULL;
  return new_node;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
  node_to_insert->next = *head;
  if (*head != NULL) {
    (*head)->prev = node_to_insert;
  }
  *head = node_to_insert;
  node_to_insert->prev = NULL;
  return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode) {
  newnode->next = node_to_insert_after->next;
  if (newnode->next != NULL) {
    newnode->next->prev = newnode;
  }
  newnode->prev = node_to_insert_after;
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
    if (*head != NULL) {
      (*head)->prev = NULL;
    }
    return;
  }
  node_to_remove->prev->next = node_to_remove->next;
  if (node_to_remove->next != NULL) {
    node_to_remove->next->prev = node_to_remove->prev;
  }
  node_to_remove->next = NULL;
  node_to_remove->prev = NULL;
}

int main() { return 0; }
