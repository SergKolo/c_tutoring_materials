#include <stdio.h>
int main(){
    // Declare all things we need
    int n; 
    int k;
    int n_fact = 1;
    int nk;
    int nk_fact = 1;

    // Get input from user
    printf("Enter n:");
    scanf("%d",&n);

    printf("Enter k:");
    scanf("%d",&k);

    nk=n-k;
    
    // Calculate n! first
    do{
       n_fact = n_fact*n;
       n = n - 1; 
    }while(n>0);
    printf("n factorial: %d\n",n_fact);

    do{
       printf("nk: %d\n",nk);
       nk_fact = nk_fact * nk;
       nk = nk - 1;
    }while(nk>0);
    printf("nk factorial: %d\n",nk_fact);

    printf("Result is %d\n\n",n_fact/nk_fact);
 
    return 0;
}
