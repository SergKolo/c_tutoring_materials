#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char rand_char(int,int);
char * reverse(char *);
int alen(char *);

int main()
{
    int length = 7;
    int min = 97;
    int max = 122;
    char word[length];

    srand(time(NULL));

    for(int i=0; i<length;i++)
        word[i] = rand_char(min,max);
    //for(int i=0;i<=length;i++)
        //printf("%d : %c\n",i,word[i]);      
    //if (word[length]== '\0')
        //printf("YES");
    //printf("\nWORD has %d elements",alen(word)); 
    //printf("\n%d",(int)sizeof(unsigned short int));
    printf("\nreverse: %s",reverse(word));
    return 0;
}

int alen(char *array)
{
    return (int)(sizeof(array)/sizeof(array[0])) - 1;
}

char *reverse(char * orig)
{
    char temp;
    int rightmost = alen(orig) - 1;
    printf("\nOrig is %s,%d",orig,rightmost);
    for(int i=0;i<rightmost;i++,rightmost--){
        temp = orig[i];
        orig[i] = orig[rightmost];
        orig[rightmost] = temp;
    }
    return orig; 
}

char rand_char(int a,int b)
{
     unsigned short int rand_value;
     while (1)
     {
        rand_value = rand();
        if( rand_value >= a && rand_value <= b ) 
            return (char)rand_value;
     }
}
