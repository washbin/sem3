#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY INT_MIN

struct node {
  int data;
  struct node *next;
};
typedef struct node node_t;

typedef node_t *stack;

bool push(stack *mystack, int value) {
  node_t *newnode = malloc(sizeof(node_t));
  if (newnode == NULL) {
    return false;
  }

  newnode->data = value;
  newnode->next = *mystack;
  *mystack = newnode;
  return true;
}

int pop(stack *mystack) {
  if (*mystack == NULL) {
    return STACK_EMPTY;
  }

  int value = (*mystack)->data;
  node_t *temp = *mystack;
  *mystack = (*mystack)->next;
  free(temp);
  return value;
}

int main() {
  stack st = NULL;
  push(&st, 56);
  push(&st, 97);
  push(&st, 84);
  push(&st, 78);
  push(&st, 45);

  pop(&st);
  pop(&st);

  int t;
  while ((t = pop(&st)) != STACK_EMPTY) {
    printf("t = %d\n", t);
  }
  return 0;
}
