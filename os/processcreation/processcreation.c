#include <stdio.h>
#include <unistd.h>

int fibonacci(int n) {
  if (n <= 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int n) {
  if (n < 0) {
    return 0;
  }
  if (n == 0 || n == 1) {
    return 1;
  }

  return n * factorial(n - 1);
}

int main() {
  int pid, mypid, myppid, num;

  printf("Enter a number: ");
  scanf("%d", &num);

  pid = fork();
  if (pid < 0) {
    perror("fork() failure\n");
    return 1;
  }

  if (pid == 0) {
    printf("\nThis is child process\
           \nand we will find %dth term of fibonaci 0,1,1,2,3,5...\n ",
           num);

    mypid = getpid();
    myppid = getppid();
    printf("Process id is %d and parent process id is %d\n", mypid, myppid);
    printf("%dth term of Fibonacci is %d\n", num, fibonacci(num));
  } else {
    sleep(2);
    printf("\nThis is parent process\
	   \nand we will calculate factorial of the number %d\n ",
           num);
    mypid = getpid();
    myppid = getppid();
    printf("Process id is %d and parent process id is %d\n", mypid, myppid);
    printf("Factorial of %d is %d\n", num, factorial(num));
  }

  return 0;
}
