#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rand_int(int,int);

int main()
{

    //This is where we create 2d array
    int ROWS = 3;
    int COLUMNS = 2;
    int arr[ROWS][COLUMNS];

    // We need to grab address of first and last item
    // so that we know when to stop
    int *address = &arr[0][0];
    int *last = &arr[ROWS-1][COLUMNS-1];
   
    // seed the random number generator
    srand(time(NULL));

    // fill up the array with random data
    for(int i = 0; i<ROWS;i++)
        for(int j=0;j<COLUMNS;j++)
            arr[i][j] = rand_int(100,200);

    // This is where pointer magic happens:
    // we keep printing until we go past the last
    // item. At that point we'll get out of the loop
    while ( address != last+1 ){
        printf("Address: %p, Value: %d\n",address,*address);
        address++;
    }
     
    // This is the same thing, except we're using two nested loops   
    for(int i = 0; i<ROWS;i++){
        printf("Printing ROW: %d\n",i);
        for(int j=0;j<COLUMNS;j++)
            printf("\tCOLUMN  %d value: %d\n",j,arr[i][j]);
    }

    return 0;
}

int rand_int(int min,int max)
{
     // Function that generates random integer. Give it
     // range ( min and max values) and it will give random int
     // in that range
     int a = min;
     int b = max;
     int randValue;
     randValue = a + (int) rand () % (b - a + 1);
     return randValue;

}
