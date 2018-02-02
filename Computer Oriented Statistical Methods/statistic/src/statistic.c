/*
    author: Christian Bender
    This file contains the implementation part of the statistic-library.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "statistic.h"

double average(int n, ...)
{
    va_list valist;
    double sum = 0;
    int i;

    /* initializes valist for num number of arguments */
    va_start(valist, n);

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {

        sum += va_arg(valist, double);
    }

    /* cleans memory reserved for valist */
    va_end(valist);

    return sum / n;
}

double average_Array(int n, const double values[])
{
    int i;
    double sum = 0;

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {
        sum += values[i];
    }

    return sum / n;
}

double standard_deviation(int n, ...)
{
    va_list valist;
    double var = 0;
    double avg = 0;
    double value = 0;
    double values[n];
    int i;

    /* initializes valist for num number of arguments */
    va_start(valist, n);

    for (i = 0; i < n; i++)
    {
        values[i] = va_arg(valist, double);
    }

    va_end(valist);
    va_start(valist, n);

    /* fetches the average */
    avg = average_Array(n, values);

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {
        value = va_arg(valist, double);
        var += (value - avg) * (value - avg);
    }

    var /= (double)(n - 1);

    /* cleans memory reserved for valist */
    va_end(valist);

    return sqrt(var);
}

double standard_deviation_array(int n, const double values[])
{

    double var = 0;
    double avg = 0;
    int i;

    /* fetches the average */
    avg = average_Array(n, values);

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {
        var += (values[i] - avg) * (values[i] - avg);
    }

    var /= (double)(n - 1);

    return sqrt(var);
}

double standard_deviation_N(int n, ...)
{
    va_list valist;
    double var = 0;
    double avg = 0;
    double value = 0;
    double values[n];
    int i;

    /* initializes valist for num number of arguments */
    va_start(valist, n);

    for (i = 0; i < n; i++)
    {
        values[i] = va_arg(valist, double);
    }

    va_end(valist);
    va_start(valist, n);

    /* fetches the average */
    avg = average_Array(n, values);

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {
        value = va_arg(valist, double);
        var += (value - avg) * (value - avg);
    }

    var /= (double)n;

    /* cleans memory reserved for valist */
    va_end(valist);

    return sqrt(var);
}

double standard_deviation_N_array(int n, const double values[])
{
    double var = 0;
    double avg = 0;
    int i;

    /* fetches the average */
    avg = average_Array(n, values);

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {
        var += (values[i] - avg) * (values[i] - avg);
    }

    var /= (double)n;

    return sqrt(var);
}

double variance(int n, const double values[])
{
    double var = 0;
    double avg = 0;
    int i;

    /* fetches the average */
    avg = average_Array(n, values);

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {
        var += (values[i] - avg) * (values[i] - avg);
    }

    var /= (double)(n - 1);

    return var;
}

double variance_N(int n, const double values[])
{
    double var = 0;
    double avg = 0;
    int i;

    /* fetches the average */
    avg = average_Array(n, values);

    /* adds up all double values of the sample. */
    for (i = 0; i < n; i++)
    {
        var += (values[i] - avg) * (values[i] - avg);
    }

    var /= (double)n;

    return var;
}

double max(int n, const double values[])
{
    double max = values[0];
    int i;

    /* iterates over all elements in 'values' */
    for (i = 1; i < n; i++)
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }

    return max;
}

double min(int n, const double values[])
{
    double min = values[0];
    int i;

    /* iterates over all elements in 'values' */
    for (i = 1; i < n; i++)
    {
        if (values[i] < min)
        {
            min = values[i];
        }
    }

    return min;
}

/* 
    private helper-function for comparing two double values 
*/
int cmp(const void *a, const void *b)
{
    return (*(double *)a - *(double *)b);
}

double median(int n, const double values[])
{
    double tmp[n];
    int i;

    /* clones the array 'values' to array 'tmp' */
    for (i = 0; i < n; i++)
    {
        tmp[i] = values[i];
    }

    /* sorts the array 'tmp' with quicksort from stdlib.h */
    qsort(tmp, n, sizeof(double), cmp);

    if (n % 2 != 0) /* n is odd */
    {
        /* integer division */
        return tmp[n / 2];
    }
    else
    { /* n is even */

        /* uses the average(...) function, above. */
        return average(2, tmp[n / 2], tmp[(n / 2) - 1]);
    }
}

double sum(int n, const double values[])
{
    double sum = 0;
    int i;

    /* actual adding procedure */
    for (i = 0; i < n; i++)
    {
        sum += values[i];
    }

    return sum;
}

double range(int n, const double values[])
{
    return max(n, values) - min(n, values);
}

double frequency_of(int n, const double values[], double val)
{
    int i;
    double counter = 0;

    /* counts the number of occurs */
    for (i = 0; i < n; i++)
    {
        if (values[i] == val)
        {
            counter++;
        }
    }

    return counter / n;
}

double quartile_I(int n, const double values[])
{
    double sum = 0;
    double freq = 0;
    int i;
    int d = 1;
    double tmp[n];

    for (i = 0; i < n; i++)
    {
        tmp[i] = values[i];
    }

    /* sorts the array 'tmp' with quicksort from stdlib.h */
    qsort(tmp, n, sizeof(double), cmp);

    double lastVal = tmp[0];

    freq = frequency_of(n, values, lastVal);
    sum += freq;

    for (i = 1; i < n; i++)
    {
        if (tmp[i] != lastVal)
        {
            freq = frequency_of(n, values, tmp[i]);
            sum += freq;
            lastVal = tmp[i];
            if (sum >= 0.25)
            {
                if (n % 2 != 0)
                {
                    return values[i];
                }
                else
                {

                    return average(2, values[i], values[i + 1]);
                }
            }
        }
    }
}

double quartile_III(int n, const double values[])
{
    double sum = 0;
    double freq = 0;
    int i;
    double tmp[n];

    for (i = 0; i < n; i++)
    {
        tmp[i] = values[i];
    }

    /* sorts the array 'tmp' with quicksort from stdlib.h */
    qsort(tmp, n, sizeof(double), cmp);

    double lastVal = tmp[0];

    freq = frequency_of(n, values, lastVal);
    sum += freq;

    for (i = 1; i < n; i++)
    {
        if (tmp[i] != lastVal)
        {
            freq = frequency_of(n, values, tmp[i]);
            sum += freq;
            lastVal = tmp[i];
            if (sum >= 0.75)
            {
                if (n % 2 != 0)
                {
                    return values[i];
                }
                else
                {
                    return average(2, values[i], values[i + 1]);
                }
            }
        }
    }
}

double quartile_distance(int n, const double values[])
{
    return quartile_III(n, values) - quartile_I(n, values);
}