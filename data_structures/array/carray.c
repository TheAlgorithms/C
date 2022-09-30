/*
 * CArray.c
 *
 * Author: Leonardo Vencovsky
 * Created on 19/03/2018
 *
 * Modified by: Leonardo Vencovsky
 * Last modified: 19/03/2018
 *
 * Array Implementations in C
 *
 * Compiled in Visual Studio 2017
 *
 */

/*
Return Codes

-1 - Array Erased
0 - Success
1 - Invalid Position
2 - Position already initialized (use update function)
3 - Position not initialized (use insert function)
4 - Position already empty
5 - Array is full

*/

#include "carray.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(CArray *array, int position1, int position2);

CArray *getCArray(int size)
{
    CArray *array = (CArray *)malloc(sizeof(CArray));
    array->array = (int *)malloc(sizeof(int) * size);
    array->size = size;
    int i;
    for (i = 0; i < size; i++)
    {
        array->array[i] = 0;
    }
    return array;
}

int insertValueCArray(CArray *array, int position, int value)
{
    if (position >= 0 && position < array->size)
    {
        if (array->array[position] == 0)
        {
            array->array[position] = value;
            return SUCCESS;
        }
        else
            return POSITION_INIT;
    }
    return INVALID_POSITION;
}

int removeValueCArray(CArray *array, int position)
{
    if (position >= 0 && position < array->size)
    {
        if (array->array[position] != 0)
        {
            array->array[position] = 0;
        }
        else
            return POSITION_EMPTY;
    }
    return INVALID_POSITION;
}

int pushValueCArray(CArray *array, int value)
{
    int i;
    int ok = 0;
    for (i = 0; i < array->size; i++)
    {
        if (array->array[i] == 0)
        {
            array->array[i] = value;
            ok = 1;
            break;
        }
    }
    if (ok == 1)
        return SUCCESS;
    else
        return ARRAY_FULL;
}

int updateValueCArray(CArray *array, int position, int value)
{
    if (position >= 0 && position < array->size)
    {
        if (array->array[position] != 0)
        {
            array->array[position] = value;
            return SUCCESS;
        }

        else
            return POSITION_NOT_INIT;
    }
    return INVALID_POSITION;
}

int eraseCArray(CArray *array)
{
    int i;
    for (i = 0; i < array->size; i++)
    {
        array->array[i] = 0;
    }
    return 0;
}

int switchValuesCArray(CArray *array, int position1, int position2)
{
    if (position1 >= 0 && position1 < array->size && position2 >= 0 &&
        position2 < array->size)
    {
        int temp = array->array[position1];
        array->array[position1] = array->array[position2];
        array->array[position2] = temp;
        return SUCCESS;
    }
    return INVALID_POSITION;
}

int reverseCArray(CArray *array)
{
    int i;
    for (i = 0; i < array->size / 2; i++)
    {
        swap(array, i, array->size - i - 1);
    }
    return SUCCESS;
}

int displayCArray(CArray *array)
{
    int i;
    printf("\nC ARRAY\n");
    for (i = 0; i < array->size; i++)
    {
        printf("%d ", array->array[i]);
    }
    printf("\n");
    return 0;
}

int blenderCArray(CArray *array)
{
    srand(time(NULL) * array->size);
    int i;
    int total = array->size * 100;
    for (i = 0; i < total; i++)
    {
        swap(array, rand() % array->size, rand() % array->size);
    }
    return 0;
}

CArray *getCopyCArray(CArray *arr)
{
    CArray *array = (CArray *)malloc(sizeof(CArray));
    array->array = (int *)malloc(sizeof(int) * arr->size);
    array->size = arr->size;
    int i;
    for (i = 0; i < arr->size; i++)
    {
        array->array[i] = arr->array[i];
    }
    return array;
}

void swap(CArray *array, int position1, int position2)
{
    int temp = array->array[position1];
    array->array[position1] = array->array[position2];
    array->array[position2] = temp;
}

int bubbleSortCArray(CArray *array)
{
    int i, j;
    for (i = 0; i < array->size - 1; i++)
    {
        for (j = 0; j < array->size - i - 1; j++)
        {
            if (array->array[j] > array->array[j + 1])
            {
                swap(array, j, j + 1);
            }
        }
    }
    return 0;
}

int selectionSortCArray(CArray *array)
{
    int i, j, min;
    for (i = 0; i < array->size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < array->size; j++)
            if (array->array[j] < array->array[min])
                min = j;
        swap(array, min, i);
    }
    return 0;
}

int insertionSortCArray(CArray *array)
{
    int i, j, num;
    for (i = 1; i < array->size; i++)
    {
        num = array->array[i];
        j = i - 1;
        while (j >= 0 && array->array[j] > num)
        {
            array->array[j + 1] = array->array[j];
            j--;
        }
        array->array[j + 1] = num;
    }
    return 0;
}

int valueOcurranceCArray(CArray *array, int value)
{
    int i, total = 0;
    for (i = 0; i < array->size; i++)
    {
        if (array->array[i] == value)
            total++;
    }
    return total;
}

CArray *valuePositionsCArray(CArray *array, int value)
{
    int i, j = 0;
    int total = valueOcurranceCArray(array, value);
    CArray *resultArray = getCArray(total);
    for (i = 0; i < array->size; i++)
    {
        if (array->array[i] == value)
        {
            // Hopefully this won't overflow
            resultArray->array[j] = i;
            j++;
        }
    }
    return resultArray;
}

int findMinCArray(CArray *array)
{
    int i;
    int min = array->array[0];
    for (i = 1; i < array->size; i++)
    {
        if (array->array[i] < min)
        {
            min = array->array[i];
        }
    }
    return min;
}

int findMaxCArray(CArray *array)
{
    int i;
    int max = array->array[0];
    for (i = 1; i < array->size; i++)
    {
        if (array->array[i] > max)
        {
            max = array->array[i];
        }
    }
    return max;
}
