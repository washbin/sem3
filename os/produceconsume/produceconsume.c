#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;

void producer() {
  mutex--;

  empty--;
  full++;
  x++;
  printf("\nProducer produces item %d", x);

  mutex++;
}

void consumer() {
  mutex--;

  full--;
  empty++;
  printf("\nConsumer consumes item %d", x);
  x--;

  mutex++;
}

int main() {
  int rand_num;
  while (1) {
    sleep(1);
    rand_num = rand() % 2;

    switch (rand_num) {
    case 0:
      if (mutex == 1 && full > 0) {
        consumer();
      } else {
        printf("\nConsumer arrived but buffer is empty !");
      }

    case 1:
      if (mutex == 1 && empty > 0) {
        producer();
      } else {
        printf("\nProducer arrived but buffer is full!");
      }
    }
  }
}
