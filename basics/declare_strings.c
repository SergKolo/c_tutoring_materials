/*
 * Author: Serg Kolo
 * Date: Feb 21, 2017
 * Description: simple code to show how
 *       to declare and use strings
 * IDE: vim
 * Tested on: Ubuntu Linux 16.04 LTS
 */
#include <stdio.h>

int main(char args[],int argv){
    // array of items, type char ( character )
    
    // px is a pointer ( address  ) , points to
    // string literal "hello" 
    // You can't do this with pointer:
    //px[1]="z";

    // Pointers can be re-assigned
    //px = &str1;   

    // Print me address of the pointer, and the block
    // of memory  where it points

    char str1[] = "world";
    const char *px = "%s\t%s\n";
    printf(px,"Hello","World");
    printf("%p\t%s\n",&px,px);

    // Print me first item to what px points
    printf("%c\n",*px);
    // Print me second item to what px points
    printf("%c\n",*(px+1));

    printf("Address: %p\n",(void *)px);
    printf("%p\n",(void *) "Hello World!");

    printf("%p\t%s\n",&str1,str1);
    return 0;
}
