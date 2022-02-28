#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct {
  node *head;
  node *tail;
} queue;

queue *init_queue() {
  queue *q = malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

bool enqueue(queue *q, int value) {
  // create a new node
  node *new_node = malloc(sizeof(node));
  if (new_node == NULL) {
    return false;
  }
  new_node->value = value;
  new_node->next = NULL;

  // if there is tail, connect tail to new node
  if (q->tail != NULL) {
    q->tail->next = new_node;
  }
  q->tail = new_node;

  // if there is no head, set head to new node
  if (q->head == NULL) {
    q->head = new_node;
  }

  return true;
}

int dequeue(queue *q) {
  // check empty queue
  if (q->head == NULL) {
    return QUEUE_EMPTY;
  }
  // save head of the queue
  node *tmp = q->head;

  // save the value of the head node to return
  int result = tmp->value;

  // take if off.
  q->head = q->head->next;
  if (q->head == NULL) {
    q->tail = NULL;
  }
  free(tmp);

  return result;
}

int main() {
  queue q1 = *init_queue();

  enqueue(&q1, 1);
  enqueue(&q1, 2);
  enqueue(&q1, 3);
  enqueue(&q1, 4);
  enqueue(&q1, 5);

  dequeue(&q1);
  dequeue(&q1);

  int t;
  while ((t = dequeue(&q1)) != QUEUE_EMPTY) {
    printf("t = %d\n", t);
  }
  return 0;
}
