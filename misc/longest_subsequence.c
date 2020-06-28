#include <stdio.h>
#include <stdlib.h>

void longestSub(int *ARRAY, int ARRAY_LENGTH, int **RESULT, int *RESULT_LENGTH)
{  // RESULT and RESULT_LENGTH will be modified by their pointers

    if (ARRAY_LENGTH <= 1)
    {
        *RESULT = ARRAY;
        *RESULT_LENGTH = ARRAY_LENGTH;
    }
    else
    {
        int PIVOT = ARRAY[0];
        int *LONGEST_SUB = NULL;
        int i, j, LONGEST_SUB_LENGTH = 0;
        int TEMPORARY_ARRAY_LENGTH = 0, *TEMPORARY_ARRAY = NULL;

        for (i = 1; i < ARRAY_LENGTH; i++)
        {
            if (ARRAY[i] < PIVOT)
            {
                TEMPORARY_ARRAY_LENGTH = 0;
                TEMPORARY_ARRAY = NULL;

                for (j = i + 1; j < ARRAY_LENGTH; j++)
                {
                    if (ARRAY[j] >= ARRAY[i])
                    {
                        TEMPORARY_ARRAY_LENGTH++;
                        TEMPORARY_ARRAY = (int *)realloc(
                            TEMPORARY_ARRAY,
                            TEMPORARY_ARRAY_LENGTH * sizeof(int));
                        TEMPORARY_ARRAY[TEMPORARY_ARRAY_LENGTH - 1] = ARRAY[j];
                    }
                }

                longestSub(TEMPORARY_ARRAY, TEMPORARY_ARRAY_LENGTH,
                           &TEMPORARY_ARRAY, &TEMPORARY_ARRAY_LENGTH);
                if (LONGEST_SUB_LENGTH < TEMPORARY_ARRAY_LENGTH + 1)
                {
                    LONGEST_SUB_LENGTH = TEMPORARY_ARRAY_LENGTH + 1;
                    LONGEST_SUB = (int *)realloc(
                        LONGEST_SUB, LONGEST_SUB_LENGTH * sizeof(int));
                    LONGEST_SUB[0] = ARRAY[i];

                    for (i = 1; i < LONGEST_SUB_LENGTH; i++)
                        LONGEST_SUB[i] = TEMPORARY_ARRAY[i - 1];
                }
            }
        }

        TEMPORARY_ARRAY = NULL;
        TEMPORARY_ARRAY_LENGTH = 0;
        for (i = 1; i < ARRAY_LENGTH; i++)
        {
            if (ARRAY[i] >= PIVOT)
            {
                TEMPORARY_ARRAY_LENGTH++;
                TEMPORARY_ARRAY = (int *)realloc(
                    TEMPORARY_ARRAY, TEMPORARY_ARRAY_LENGTH * sizeof(int));
                TEMPORARY_ARRAY[TEMPORARY_ARRAY_LENGTH - 1] = ARRAY[i];
            }
        }

        longestSub(TEMPORARY_ARRAY, TEMPORARY_ARRAY_LENGTH, &TEMPORARY_ARRAY,
                   &TEMPORARY_ARRAY_LENGTH);
        if (TEMPORARY_ARRAY_LENGTH + 1 > LONGEST_SUB_LENGTH)
        {
            LONGEST_SUB_LENGTH = TEMPORARY_ARRAY_LENGTH + 1;
            LONGEST_SUB =
                (int *)realloc(LONGEST_SUB, LONGEST_SUB_LENGTH * sizeof(int));
            LONGEST_SUB[0] = PIVOT;
            for (i = 1; i < LONGEST_SUB_LENGTH; i++)
                LONGEST_SUB[i] = TEMPORARY_ARRAY[i - 1];
        }
        *RESULT = LONGEST_SUB;
        *RESULT_LENGTH = LONGEST_SUB_LENGTH;
    }
}

int main()
{
    int EXAMPLE_LENGTH = 8;
    int EXAMPLE[] = {18, 2, 15, 4, 30, 0, 11, 12};

    int *RESULT = NULL;
    int RESULT_LENGTH, i;

    longestSub(EXAMPLE, EXAMPLE_LENGTH, &RESULT, &RESULT_LENGTH);

    printf("Longest Sub Sequence length: %d and it's:\n", RESULT_LENGTH);
    for (i = 0; i < RESULT_LENGTH; i++) printf("%d ", RESULT[i]);
    printf("\n");

    return 0;
}