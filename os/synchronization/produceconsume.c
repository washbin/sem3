#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define true 1

int count = 0;
int n = 4;

int Buffer[4];

int produce_item(int seed) {
  int produced = rand() % seed;
  printf("Produced ==> %d\t\t\n", produced);
  return produced;
}

int consume_item(int item) {
  printf("\t\tConsumed <== %d\n", item);
  return item;
}

void *producer(void *pstring) {
  int item, in = 0;
  while (true) {
    item = produce_item(15);
    while (count == n) {
      printf("Queue Full, Can't produce more.\n");
      sleep(1);
    }
    sleep(1);
    Buffer[in] = item;
    in = (in + 1) % n;
    count++;
  }
}

void *consumer(void *pstring) {
  int item, out = 0;
  while (true) {
    while (count == 0) {
      printf("Queue empty, Nothing to consume.\n");
      sleep(1);
    }
    sleep(1);
    item = Buffer[out];
    out = (out + 1) % n;
    count--;
    consume_item(item);
  }
}

int main() {
  pthread_t thread1, thread2;

  // make threads
  pthread_create(&thread1, NULL, producer, "Producer thread");
  pthread_create(&thread2, NULL, consumer, "Consumer thread");

  // wait for threads to complete
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}
