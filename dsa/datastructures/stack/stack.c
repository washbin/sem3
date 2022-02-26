/*
 * Write algorithm and code to perform all operation on stack
 *
 * push, pop
 *
 * --------
 * |      | -> 2
 * --------
 * |      | -> 1
 * --------
 * |      | -> 0
 * --------
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define STACK_OVERFLOW "!!!Stack overflow\n"
#define STACK_EMPTY "!!!Stack is empty.\n"

/* stack is a LIFO datastrucutre like a stack of clothes */
typedef struct stack {
  int top;
  int size;
  int *arr;
} stack;

/* push function pushes a new item on top of stack */
void push(stack *s, int value) {
  if (s->top == s->size - 1) {
    printf(STACK_OVERFLOW);
    return;
  }

  s->top++;
  s->arr[s->top] = value;
}

/* pop function pops the top item from stack and returns it */
int pop(stack *s) {
  if (s->top == -1) {
    printf(STACK_EMPTY);
    return -1;
  }

  int value = s->arr[s->top];
  s->top--;
  return value;
}

/* display function prints the stack */
void display(stack *s) {
  if (s->top == -1) {
    printf(STACK_EMPTY);
    return;
  }
  for (int i = s->top; i >= 0; i--) {
    printf("The item at %d is %d\n", i, s->arr[i]);
  }
}

int main(void) {
  stack s;
  s.top = -1;
  s.size = 5;
  s.arr = malloc(sizeof(int) * s.size);
  printf("--Stack Program--\n");

  int choice, value;
  while (1) {
    printf("\nEnter your choice\n"
           "1. Push item\n"
           "2. Pop item\n"
           "3. Display items\n"
           "4. Exit\n\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the int value to push\n");
      scanf("%d", &value);
      push(&s, value);
      break;
    case 2:
      printf("Popping: %d\n", pop(&s));
      break;
    case 3:
      display(&s);
      break;
    case 4:
      free(s.arr);
      return 0;
      break;
    default:
      printf("Invalid Choice %d\n", choice);
    }
  }
}
