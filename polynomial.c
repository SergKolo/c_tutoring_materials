#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for atoi() function
#include <math.h> // for pow() function

double calc_polynomial(int *,int,int);

int main(){
    // declare variables
    const char items[512];
    char plm[512];
    int coefficients[512];

    // ask user for input
    printf(">>> enter polynomial:\n");
    scanf("%s",plm);

    // basically for loop implemented using while loop
    // NOTE: In each subsequent call  that  should  parse  the  same
    // string, str must be NULL.

    int i = 0;
    int array_size = 0;
    char *p = strtok(plm,","); 
    while (p != NULL){
        array_size += 1;
        printf("%s\n",p);
        // convert text number to int type , save to array
        coefficients[i] = atoi(p); 
        i+=1;
        p = strtok(NULL,",");
    }
    printf("%f\n",calc_polynomial(coefficients,3,array_size));
    return 0;
}

double calc_polynomial(int *arr,int x,int length){
    double result;
    double j=0;
    printf("Calculating F(x)\n");
    for(int i=length-1; i >= 0;i--,j++){
       printf("%d,%f\n",arr[i],j);
       result += arr[i]*pow((double)x,(double)j);
    }
    printf("Final result:%f\n",result);
    return result;
}
