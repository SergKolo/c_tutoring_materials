#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void remove_newline(char *,int);

// This is just a blueprint, total size depends on elements
struct person_data{
    char name[1024];
    int age;
};


int main()
{
     int how_many = 3;
    /* This is the actual point where
     * we take chunk of memory and reserve
     * 3 chunks of size that are needed for
     * 1 person_data
     */
    struct person_data students[how_many];

    struct person_data *address = students; // address of first
    struct person_data *last;               // address of last

    for(int i=0;i<3;i++){
        printf("Enter name:");
        char buffer[sizeof(students[i].name)];
        fgets(buffer,sizeof(students[i].name),stdin);
        // fgets records newline, so we need to strip it 
        remove_newline(buffer,strlen(buffer));
        strcpy(students[i].name,buffer);
        
        printf("Enter age:");
        fscanf(stdin,"%d",&students[i].age);
        /* fscanf will read only integer so we need
         * to get rid of newline that appears after hittig
         * enter key
         */
        char devnull[2];
        fgets(devnull,sizeof(devnull),stdin);
        
        last = &students[i]; // remember address of last item
    }
    
        while(address != last+1) {
            printf("%s,%d\n",address->name,address->age);
            address++; // adding +1 to pointer is equivalent to moving address
                       // by size of the data you're referencing 
        }

    return 0;
}


/* This function removes newline that is read
 * from user input using fgets()
 */
void remove_newline(char *input,int length)
{ 
     int i = 0;
     for (i;i<length;i++){
         if (input[i] == '\n')
            input[i] = '\0' ;
     }
}
