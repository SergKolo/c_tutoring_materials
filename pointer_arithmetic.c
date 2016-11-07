#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int,int);
int main()
{
    int array_size = 5;
    int array[array_size];
    int *address = array;
    srand(time(NULL));
    for(int x = 0;x<array_size;x++)
        array[x] = rand_int(100,200);

    printf("Hello, I'm array of integers. Here are my values:\n");

    for(int x=0;x<array_size;x++)
        printf("Element # %d,value: %d at address: %p\n",x,array[x],&array[x]);
    
    printf("As you may have guessed, int *address grabs address of my first element\n");
    printf("To be precise, the address is %p\n",address);
    printf("And its value is %d\n",*address);
    printf("\n\n");

    printf("What if we do address+1?\n");
    printf("That will point to next address in memory, which is away x number of bytes\n");
    printf("In this case it will be 4 bytes away, because size of int is %d\n",(int)sizeof(int));
    printf("And look ! First element is at  %p but second is at %p\n",address,address+1);

    printf("If we wanted to read contents of that address, we would do *(address + 1)\n");
    printf("In fact that's what it is: %d\n",*(address+1));
 
    printf("\n\n");  
 
    printf("We can also play with the values. For example, if we wanted to add 2 to ");
    printf("the second element we would do *(address + 1) + 2. Again, the *(address + 1) part means");
    printf(" the actual contents of that address, and simply add 2 to it, like so:");
    printf("%d\n",*(address+1) + 2);

    printf("\n\n");
    printf("We can do the same thing with any address, so long as it is within the bounds of array\n");
    printf("So last element is %d",*(address + array_size - 1));
 

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
