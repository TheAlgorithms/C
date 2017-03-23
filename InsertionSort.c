#include <stdio.h>
#incude  <stdlib.h>
#define MAX 20



int main()
{
    int i, elmtToInsert , j , arraySort[MAX] = {0};

        for(i = 1 ; i < MAX ;  i++)
        {
            elmtToInsert = arraySort[i];
            j = i - 1 ;

            while( j >= 0 && elmtToInsert < arraySort[j])
            {
                arraySort[j+1] = arraySort[j];
                j--;
            }

            arraySort[j+1] = elmtToInsert ;
        }




    return EXIT_SUCCESS;
}
