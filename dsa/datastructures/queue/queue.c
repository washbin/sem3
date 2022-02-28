#include <stdio.h>
#include <stdlib.h>

#define QUEUE_FULL "!!!Queue is full\n"
#define QUEUE_EMPTY "!!!Queue is empty\n"

/* queue is a FIFO datastructure, analogous to a real world queue */
struct queue {
  int *data;
  int size;
  int front;
  int rear;
};
typedef struct queue queue_t;

/* Enqueue adds a value at the end of queue */
void enqueue(queue_t *q, int value) {
  if (q->rear == q->size - 1) {
    printf(QUEUE_FULL);
    return;
  }
  if (q->front == -1) {
    q->front = 0;
  }

  q->rear++;
  q->data[q->rear] = value;
}

/* Deque removes a value at the front of the queue and returns the removed value
 */
int dequeue(queue_t *q) {
  if (q->front == -1) {
    printf(QUEUE_EMPTY);
    return -1;
  }

  int value = q->data[q->front];
  q->front++;

  if (q->front > q->rear) {
    q->front = -1;
    q->rear = -1;
  }
  return value;
}

/* printQueue traverses the queue and prints all the current items */
void printQueue(queue_t *q) {
  if (q->front == -1) {
    printf(QUEUE_EMPTY);
    return;
  }

  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->data[i]);
  }
  printf("\n");
}

int main(void) {
  queue_t q;
  q.size = 5;
  q.data = malloc(sizeof(int) * q.size);
  q.front = -1;
  q.rear = -1;

  printf("--Queue Program--\n");

  int choice, value;
  for (;;) {
    printf("\nEnter your choice\n"
           "1. Enqueue item\n"
           "2. Dequeue item\n"
           "3. Display items\n"
           "4. Exit\n\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the int value to push\n");
      scanf("%d", &value);
      enqueue(&q, 1);
      break;
    case 2:
      printf("Dequeing %d\n", dequeue(&q));
      break;
    case 3:
      printQueue(&q);
      break;
    case 4:
      free(q.data);
      return 0;
      break;
    default:
      printf("Invalid Choice %d\n", choice);
    }
  }
}
