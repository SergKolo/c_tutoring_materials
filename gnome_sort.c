#include <stdio.h>
#include <string.h>

void gnome_sort(char states[][15], int n)
{
    int i = 1, j = 2;
    char temp[15];
    while ( i < n ){
        if (strcmp(states[i-1],states[i]) >0) {
            strcpy(temp,states[i];
            strcpy(states[i],states[i-1]);
            strcpy(states[i-1],temp);
            if (--i)
               continue;
         }
         i = j;
         j++;
    }

}
