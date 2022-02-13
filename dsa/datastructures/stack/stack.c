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

/* define the size of stack to be used */
#define SIZE 5

/* initialize an array to be used as a stack */
int ARR[SIZE];

/* a variable representing the current head of the stack  */
int TOP = -1;

void push() {
  if (TOP == SIZE - 1) {
    printf("Stack overflow\n");
    return;
  }
  TOP += 1;
  int value;
  printf("Enter the value to push\n");
  scanf("%d", &value);
  ARR[TOP] = value;
}

void pop() {
  if (TOP == -1) {
    printf("Stack is empty.\n");
    return;
  }
  printf("Popping: %d\n", ARR[TOP]);
  TOP -= 1;
}

void display() {
  if (TOP == -1) {
    printf("Stack is empty\n");
  }
  for (int i = TOP; i >= 0; i--) {
    printf("The item at %d is %d\n", i, ARR[i]);
  }
}

int main(void) {
  printf("--Stack Program--\n");

  int choice;
  while (1) {
    printf("\nEnter your choice\n"
           "1. Push item\n"
           "2. Pop item\n"
           "3. Display items\n"
           "4. Exit\n\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      return 0;
      break;
    default:
      printf("Invalid Choice %d\n", choice);
    }
  }
}
