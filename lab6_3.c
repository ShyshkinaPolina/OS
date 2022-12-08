#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main(void) {

  int count = 0;
  printf("main pid: %d\n", getpid());
  pid_t pid1, pid11, pid12;
  pid_t pid2, pid21, pid22;
  pid1 = fork();

  if (pid1 == 0) {
    count += 1;
    printf("count=%d\taddr=%d\tppid=%d\tpid=%d\n", count, &count, getppid(), getpid());
    pid11 = fork();
    if (pid11 == 0) {
      count += 1;
      printf("count=%d\taddr=%d\tppid=%d\tpid=%d\n", count, &count, getppid(), getpid());
    }
    else 
      if (pid11 > 0) {
        pid12 = fork();
        if (pid12 == 0) {
          count += 1;
          printf("count=%d\taddr=%d\tppid=%d\tpid=%d\n", count, &count, getppid(), getpid());
        }
      }
  }
  else 
    if (pid1 > 0) {
      pid2 = fork();
    if (pid2 == 0) {
      count += 1;
      printf("count=%d\taddr=%d\tppid=%d\tpid=%d\n", count, &count, getppid(), getpid());
      pid21 = fork();
      if (pid21 == 0) {
         count += 1;
         printf("count=%d\taddr=%d\tppid=%d\tpid=%d\n", count, &count, getppid(), getpid());
      }
      else 
         if (pid21 > 0) {
            pid22 = fork();
         if (pid22 == 0) {
            count += 1;
            printf("count=%d\taddr=%d\tppid=%d\tpid=%d\n", count, &count, getppid(), getpid());
        }
      }
    }
  }

  return 0;
}
