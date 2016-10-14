#include <stdio.h>
#include <string.h>

/*
 * The lines below are function prototypes. They're basically
 * a way to tell compiler to expect that there will be a function
 * that expects to have certain variables, in specific order, and
 * of specific type given to it. Notice of it's organized:
 *         return_type name(variable_type,variable_type);
 * At this point we don't care about actual values, we're just
 * telling the compiler "expect this".
 */
void for_loop_example(int,int,char *);
int while_loop(char *);

void for_loop_example(int start,int end,char *array)
{
    /* 
     * Here's a for loop. Typically it has this structure:
     *
     * for ( starting variable ; test condition ; calculation for next step ) {
     *     statement 1;
     *     statement 2;
     *     . . . 
     *     statement 3;
     *  }
     *
     * For loop is used when we know where to start
     * where to end, and required steps. With single
     * statement inside the for loop you don't need
     * curly braces, but they're required with multiple 
     */
     int i;
     for(i=start;i<=end;i++)
         printf("The %d character of string is %c\n",i,array[i]); 

     // just to make the point, here's same thing , but mutliple statements
     i=0;
     for(i=start;i<=end;i++){
        printf("Index:%d\t",i);
        printf("Char: %c",array[i]);
        printf("\n");
     }


}

int while_loop(char *array)
{
    /*
     * While loop is used when we only know the condition
     * for doing something. For example,
     *
     * while ( tank_has_gas() ){
     *
     *     printf("Engine is running\n");
     *    
     * }
     *
     * Another  example would be a guessing game.
     *  
     * while (user_guess != answer){
     *      printf("Nope,try again!");
     *      scanf("%d",&answer);
     * } 
     *
     * Here we don't know how much gas there is in tank. The
     * function tank_has_has() returns 1 or True if there is.
     * Once there is no gas, the function would return 0 or False
     * so the loop exits.
     *
     * While loop is interchangeable with for loop. For instance,
     * in the code below, we set initial condition before the loop,
     * we have testing condition inside the brackets, and update
     * that initial condition within the loop body 
     *
     */
    
    int i = 0; 
    while (array[i] != '\0'){
        printf("%c\n",array[i]);
        i++;
    }

    return i;
}

int main()
{

    /*
     * strlen is part of string.h library
     * It returns size in bytes (!)  and takes string as argument
     * There's a bit of information that needs to be clear.
     * strlen gave us length of the string, which is 4, but
     * items in any array ( which in this case is array of strings)
     * start at index 0. That means last character has index
     * length - 1
     */
    char *string = "Hello";
    int length = strlen(string) - 1;
    for_loop_example(0,length,string);
    printf("Number of characters in string: %d",while_loop(string));
    return 0;
}
