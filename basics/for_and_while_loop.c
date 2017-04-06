/* This program gets 5 numbers from users
 * and calculates the sum of those numbers
 * using 2 different loops. You should see 
 * something like this,when you run program:
 *
 *        $ ./a.out
 *        Enter number 0
 *        3
 *        Enter number 1
 *        4
 *        Enter number 2
 *        5
 *        Enter number 3
 *        1
 *        Enter number 4
 *        4
 *        OK now we need to sum all numbers
 *        Right now adding 3 , sum is 3
 *        Right now adding 4 , sum is 7
 *        Right now adding 5 , sum is 12
 *        Right now adding 1 , sum is 13
 *        Right now adding 4 , sum is 17
 *        Final result: 17
 *
 *
 */
#include <stdio.h>

int main(){
    // we need to save numebers somewhere. Use array
    int how_many = 5;
    int numbers[how_many];
    // we save results into variable sum
    int sum = 0;
    
    for(int i = 0;i<how_many;i++){
        printf("Enter number %d\n",i);
        scanf("%d",&numbers[i]);
    }

    printf("OK now we need to sum all numbers\n");

    // This is while loop. It keeps repeating things until test condition
    // is false. In this case , test condition is j not equals to how_many
    // This written almost the same as for loop.
    int j = 0;
    while(j != how_many){
       sum = sum + numbers[j];
       printf("Right now adding %d , sum is %d\n",numbers[j],sum);
       j++;
    }
   
    printf("Final result: %d",sum); 
    return 0;
}
