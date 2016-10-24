#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void gnome_sort(int n, int size,char words[n][size])
{
    int i = 1, j = 2;
    char temp[size];
    while ( i < n ){
        if (strcmp(words[i-1],words[i]) >0) {
            strcpy(temp,words[i]);
            strcpy(words[i],words[i-1]);
            strcpy(words[i-1],temp);
            if (--i)
               continue;
         }
         i = j;
         j++;
    }
}

void fill_array(int count,int word_size,char buffer[count][word_size])
{
    char temp[count][word_size];
    //char *temp[word_size];
    for(int i = 0; i< count; i++){
        printf("\nstate %d: ",i+1);
        fgets(buffer[i],word_size,stdin);
        //buffer[i] = malloc(word_size*sizeof(char));
        //buffer[i] = temp[i];
    }
    //copy_array(count,word_size,temp,buffer);
}

void copy_array(int count, int size,
                char source[count][size],char dest[count][size]){

     for(int i = 0; i<count;i++)
         //printf("\n%d:%s",i,source[i]);
         strcpy(dest[i],source[i]);
}

void print_array(int height, int len, char array[height][len])
{

    for (int i = 0; i<height;i++)
        printf("\nstate %d:%s",i,array[i]);
}

int main()
{
    int num_states = 5;
    int len = 512;
    char states[num_states][len];
    char sorted_states[num_states][len];
    
    printf(">>> Enter a list of %d states",num_states);
    fill_array(num_states,len,states);
    
    printf("\n we got this\n");
    print_array(num_states,len,states);
    //for (int i = 0; i<num_states;i++)
    //    printf("\nstate %d:%s",i,states[i]);

    gnome_sort(num_states,len,states);

    print_array(num_states,len,states);

    return 0;
}
