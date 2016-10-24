#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rand_int (int,int);
void copy_array(int *,int *,int);
void merge(int *,int *,int,int,int);

int main()
{
   int len = 3;
   int array[len];
   int temp[len];
   
   // fill up array with random ints
   int min = 100;
   int max = 200;
   srand(time(NULL));
   for (int i=0;i<len;i++)
       array[i] = rand_int(min,max);

   // see what we got
   printf("\nORIGINAL ARRAY: \n");
   for(int i=0;i<len;i++)
      printf("\t%d",array[i]);
   printf("\n");

   for (int size = 1; size < len; size = size*2) {
     /*
      * Each time through outter loop, we will be
      * dealing with sub arrays of size that keeps doubling
      * So instead of dividing up array first as the theory goes, 
      * we jump right to the part where we alredy "have" subarray of size 1
      * and go from there
      */
      printf("\n Dealing with subarrays size: %d\n",size);
      for(int i = 0;i<len;i = i + 2*size){
         // we can only look at two subarrays at a time.
         // first will be array[left,middle]
         // second - array[middle,right]
         // We also need to make sure we don't go past
         // array boundaries, that's why if statements
         // are used
         int left, middle, right;
         left = i;
         if (i+size < len)
             middle = i + size;
         else
             middle = len;

         if (i + 2*size < len )
            right = i +2*size;
         else
            right = len;
         printf("\n This pass: %d:%d:%d\n",left,middle,right);
         merge(array,temp,left,middle,right);

         }

      copy_array(temp,array,len);
      //printf("\n");
   }

//   printf("\nORIG ARRAY:");
//   for(int i=0;i<len;i++)
//      printf("\t%d",array[i]);

   printf("\nSORTED ARRAY:\n");
   for(int i=0;i<len;i++)
      printf("\t%d",temp[i]);
 
}
       


void merge(int *arr,int *tmp,int left,int middle,int right)
{
    /* since we're sending stuff to another array of same size
       we need to ensure that we're not going past that array's
       max index. 
    */
    int i = left; 
    int j = middle;

    int k = left;
    while(k < right){
       // this part is basically picking out numbers from both
       // subarrays
       if (i < middle) {
          // is the item in right subarray greater than the one in left?
          // If it is , we take the smaller one in left subarray
          // We also need to ensure that we didn't reach end of right subarray
          // 
          if ( j >= right || arr[j] >= arr[i]  ){
          tmp[k] = arr[i];
          i++; 
          }
       }
       else{
          // nothing else in left array, so use right subarray
          tmp[k] = arr[j];
          j++;
       }
    k++;
    }

}

void copy_array(int *tmp,int *arr,int length)
{
    for(int i = 0; i < length ; i++){
       arr[i] = tmp[i];
    }
}

int rand_int (int a, int b)
{
    int randValue;
    randValue = a + (int) rand () % (b - a + 1);
    return randValue;
}


