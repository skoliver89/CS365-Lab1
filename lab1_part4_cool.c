#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define  BUF_SIZE  100
#define  MAX_COUNT 200

/* Generates numbered cows for a farm and its child farm. */
/* NOTE: must run on linux and must have cowsay installed */
void main (void)
{
  pid_t pid;
  
  fork();
  pid = getpid();
  char buf[BUF_SIZE];
  int i;
  
  for (i = 1; i <= MAX_COUNT; i++) {
    sprintf(buf, "cowsay farmID: %d cowNumber: %d", pid, i);
    system(buf);
  }
}
