#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "lab1_part5.h"

#define  MAX_NUMS 1000
/* array of random int accomplished with help of the following link: */
/* http://stackoverflow.com/questions/22186423/array-of-random-numbers-using-c-program */
/* rand() limiter inspired by: */
/* https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm */
void main (void)
{
  int array1[MAX_NUMS];
  int array2[MAX_NUMS];
  int i;
  int randLimit;
  time_t t;
  
  /* limit the random numbers to 0 - 999999 */
  randLimit = 1000000; 
  /* seed the random number gen */
  srand((unsigned) time(&t));
  
  /* fill the array with random numbers */
  for (i = 0; i < MAX_NUMS; i++){
    /* gen a limited random number and put it in the array*/
    array1[i] = rand() % randLimit; 
  }
  
  /* copy array1 to array2 */
  for (i = 0; i < MAX_NUMS; i++){
    array2[i] = array1[i];
  }
  
  /* fork it up */
  pid_t pid;
  pid = fork();
  if (pid == 0) {
    ChildProcess(array2);
  }
  else {
    ParentProcess(array1);
  }
}

void ChildProcess (int array[])
{
  int i;
  int min;
  int sum;
  
  min = getMin(array);
  for (i = 0; i < MAX_NUMS; i++){
    array[i] = min;
  }
  sum = sumArray(array);
  
  printf("Smallest Value: %d\n", min);
  printf("Sum of Smallest Value: %d\n", sum); 
}

void ParentProcess (int array[])
{
  int i;
  int max;
  int sum;
  
  max = getMax(array);
  for (i = 0; i < MAX_NUMS; i++){
    array[i] = max;
  }
  sum = sumArray(array);
  
  printf("Largest Value: %d\n", max);
  printf("Sum of Largest Value: %d\n", sum);
}

int getMax (int array[])
{
  int i;
  int max;
  
  max = array[0];
  for (i = 1; i < MAX_NUMS; i++){
    if (array[i] > max){
      max = array[i];    
    }
  }
  
  return max;
}

int getMin (int array[])
{
  int i;
  int min;
  
  min = array[0];
  for (i = 1; i < MAX_NUMS; i++){
    if (array[i] < min){
      min = array[i];    
    }
  }
  
  return min;
}

int sumArray (int array[])
{
  int i;
  int sum;
  
  sum = 0;
  for (i = 0; i < MAX_NUMS; i++){
    sum = sum + array[i];
  }
  
  return sum;
}
