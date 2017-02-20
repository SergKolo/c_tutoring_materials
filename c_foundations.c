#include <stdio.h>
// Function main is where program starts
// It is a type int, therefore must have return statement
int main(){
    int age; // integer, whole number ( no floating point)
    char gender; // single character/text
    float weight; // floating point number, like 3.14
    char name[20];

    // printf is function for printing/outputing stuff
    // it has constant string as first argument which explains the format of what will be printed
    // and can have arbitrary other arguments, but it's important to match format specified in the
    // constant string with extra arguments.
    printf("Tell me your age:\n"); // \n moves cursor to new line
    // scanf is same as printf but for getting input from user. Same idea: format on the left
    // variable where we send stuff on the right
    scanf("%d",&age);
    // scanf will skip newline character that is inserted by enter key. We need to get rid of it
    getchar();

    printf("Tell me your gender:\n");
    scanf("%c",&gender);
    getchar();

    
    printf("Tell me your weight:\n");
    scanf("%f",&weight);
    getchar();


    printf("Tell me your name:\n");
    fgets(name,20,stdin); // scanf for strings isn't good, so we use 

    printf("Your name is %s, you are %c, %f pounds and %d years old",name,gender,weight,age); 

    return 0;
}
