#include <stdio.h>
/* The Problem: You have three processes coming at random. Let's say the
processes are searching from a list(basically an array in C programming),
sorting a list and finding subsets of a list. Let's assume the list is common to
all of the process. SJF(Shortest Job First) Algorithm find the tentative time of
a process and execute the one which has shortest time. Time complexity of linear
search = O(n) Time Complexity of bubble sort = O(n*n) Time Complexity of findind
subset = O(2^n) (2 raised to the power n). You have already studied in Discrete
mathematics that 2^n > n*n for all n>4. So we can arrange the jobs in order of
Shortest time as follows: linear search < bubble sort < finding subsets let us
number the jobs as 1,2,3 linear search=1 bubble sort=2, finding subset= 3
*/
int list[10] = {23, 21, 10, 11, 7,
                8,  24, 6,  9,  10}; // this is a global variable so that every
                                     // process can have access to it
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

void linearsearch() {
  // here you have to write the code for linear search
  printf("This is linear search\n");
}

void sort() {
  // here you have to write the code for sorting
  printf("This is sorting\n");
}
void subsets() {
  // here you have to write the code for subsets
  printf("This is subsets finding algorithm\n");
}

void function(int x, int y) {
  printf("Process number %d is in execution\n", x);
  // switch(y)
  switch (y) {
  case 1:
    linearsearch();
    break;
  case 2:
    sort();
    break;
  case 3:
    subsets();
    break;
  default:
    printf("Invalid\n");
  }
}
int main() {
  int n, i, j;
  int processarriving[10][2];
  for (i = 0; i < 10; i++) {
    n = rand() % 3 + 1;        // n indicates the process type arriving at queue
    processarriving[i][0] = i; // job number
    processarriving[i][1] = n; // job size
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 10; j++) {
      if (processarriving[j][1] == i + 1) {
        function(processarriving[j][0], processarriving[j][1]);
      }
    }
  }
  return 0;
}
