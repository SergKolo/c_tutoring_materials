#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rand_int1 (int, int);
int rand_int2 (int, int);

int main (int argc, char *argv[])
{
    /*
     * Random number generation in C is done via
     * rand() function which belongs to stdlib.h
     * It has to have certain seed or "starting point"
     * from which to generate numbers. Otherwise,
     * if there is same seed each time, numbers won't
     * be random. Seeding must be done in the beginning
     * of the program, hence why it is used in main()
     *  
     */
  
    int t = (int)time(NULL);
    printf("Seed value is %d\n",t);
    srand (t);
    // argv[1] and [2] are used on command-line.
    //int min = atoi (argv[1]), max = atoi (argv[2]), i = 0;
    // Variable of same type can be declared on one line
    int min = 100, max = 200;
    for (int i = 0; i < 11; i++)
        printf ("Random value #%d : %d\n",i, rand_int2(min, max));
    return 0;
}


int rand_int1 (int a, int b)
{
     /*
      * To solve the problem of getting random values in 
      * range, there's couple of ways. The big issue is that
      * rand() gives anything between min and max values defined
      * in stdlib.h.
      * 
      * This function is a wrapper for rand() which uses mathematical
      * approach. It returns integer in range from min to max, which
      * are given as arguments to the function itself.
      * There are two important things going on here. One,
      * we simply add minimum number and some number between
      * minimum and maximum to stay in range. Two, the number
      * between min and max are used in integer division
      * of rand() output.
      *
      * The idea here is to use the modulus operator (which is
      * the % sign). Modulus gives us a remainder of integer
      * division of two numbers. The rule is that remainder
      * value will always be a number between divisor (not including it)
      * and zero (https://en.wikipedia.org/wiki/Remainder)
      * If we take for example, integer division
      * 43 / 5 , divisor here is 5, so there can only be
      * remainder values from 0 to 4. 
      * 
      * Then by getting the diference of two numbers, 'a' and 'b',
      * we know what values we can add to 'a' to remain within range.
      * Thus, what happens here is simply adding a certain number to 
      * minimum value (which is 'a') to stay within range.
      *
      * Since the remainder ranges from 0 to (divisor-1) we must add
      * 1 to the range to actually obtain a number between 0 and the (b-a),
      * giving us (b - a + 1) as a divisor to the module.
      *
      * Say rand() gave us 9347. We  need values from 200 to 100.
      * So we know we need to add to 100 some number between 0 and 100 
      * to stay in range, and that number will come from integer division
      * So knowing that remainder of integer division will always be from 
      * 0 to (divisor-1), 9347 / (200 - 100 + 1) will give us remainder of 55.
      * So 55 + 100 is 155. Here's your random number in range!
      */

      int randValue;
      randValue = a + (int) rand () % (b - a + 1);
      return randValue;
}

int rand_int2(int a, int b)
{
     /* 
      * This is alternative way of dealing with the problem.
      * Instead of mathematical approach, we simply "roll the dice"
      * until we get a number that is within range. Of course, this
      * approach is WAY slower than the rand_int1 approach, since it's
      * very likely our min and max values will only be in a really small
      * portion of the rand() min and max. It will have to be called several
      * times for the value returned fitting in the range.
      * We use && operator to ensure that two testing conditions are true.
      * If both conditions are true, the function will return value.
      * Otherwise it will keep on goning until rand gives us the number
      * we need.
      */

     int rand_value;
     while (1)
     {
        rand_value = rand();
        if( rand_value >= a && rand_value <= b ) 
            return rand_value;
     }
}
