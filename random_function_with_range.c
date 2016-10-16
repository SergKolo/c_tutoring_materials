#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randInt (int, int);

void
main (int argc, char *argv[])
{

  int min = atoi (argv[1]), max = atoi (argv[2]), i = 0;
  srand (time (NULL));


  for (i; i < 11; i++)
    {
      printf ("%d \n", randInt (min, max));
    }

}


int
randInt (int a, int b)
{


  int randValue;
  randValue = a + (int) rand () % (b - a + 1);
  return randValue;

}

