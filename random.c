#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void populate(int * p)
{
  int ctr = 0;
  srand(time(NULL));
  while (ctr++ < 10)
    *(p + ctr) = rand();
}
void printarr(int * p)
{
  int ctr = 0;
  while (ctr++ < 10)
    printf("%d\n", *(p + ctr));
}
int main()
{
  int * p = malloc(10 * sizeof(int));
  populate(p);
  printarr(p);
  free(p);
  return 0;
}
