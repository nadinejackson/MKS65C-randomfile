#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void populate(int * p)
{
  printf("populating...\n");
  int test = open("/dev/random", O_CREAT | O_RDONLY, 0777);
  printf("read = %ld\n", read(test, p, 10 * sizeof(int)));
  printf("error %d\n", errno);
  perror("error");
  close(test);
}
void printarr(int * p)
{
  int ctr = 0;
  while (ctr < 10){
    printf("random %d: %d\n", ctr, *(p + ctr));
    ctr++;
  }
}
int main()
{
  int * p = malloc(10 * sizeof(int));
  populate(p);
  printarr(p);

  printf("Writing numbers to file...\n");
  int test = open("./file.txt", O_CREAT | O_WRONLY, 0777);
  printf("write = %ld\n", write(test, p, 10 * sizeof(int)));
  printf("error %d\n", errno);
  perror("error");
  close(test);

  printf("Reading numbers from file\n");
  int * q = malloc(10 * sizeof(int));
  int exam = open("./file.txt", O_CREAT | O_RDONLY, 0777);
  printf("read = %ld\n", read(test, q, 10 * sizeof(int)));
  printf("error %d\n", errno);
  perror("error");
  close(exam);

  printf("Verification that written values are the same...\n");
  printarr(q);
  
  free(p);
  free(q);
  
  return 0;
}
