/*
    author: Christian Bender
    This file contains the public interface for the statistic-library.
*/

#ifndef __STATISTIC__H
#define __STATISTIC__H

/*
    Computes the average of a given sample.
    The sample is a set of double values.
    The average-function gets a variable number of arguments. The first argument
    must be the number of arguments!
    The averageArray-function instead gets a double-array of values and a int-number that
    represents the size of the double-array.
*/
double average_Array(int, const double[]);
double average(int, ...);

/* 
    computes the standard deviation (n-1)
*/
double standard_deviation(int, ...);
double standard_deviation_array(int, const double[]);

/*
    computes the standard deviation (n)
*/
double standard_deviation_N(int, ...);
double standard_deviation_N_array(int, const double[]);

/*
    variance: computes the variance (n-1)
    variance_N: computes the variance (n)
*/

double variance(int, const double[]);
double variance_N(int, const double[]);

/*
    gets the max (min) element of the sample 
*/
double max(int, const double[]);
double min(int, const double[]);

/*
    computes the median of the sample
*/
double median(int, const double[]);

/*
    adds up all values of the sample.
*/
double sum(int, const double[]);

/* 
    computes the range of the sample.
*/
double range(int, const double[]);

/*
    gets the frequency of the last argument (double) of that sample.
*/
double frequency_of(int, const double[], double);

/* 
    quartile_I: computes the first quartile.
    quartile_III: computes the third quartile.
    The second quartile is the median!
*/
double quartile_I(int, const double[]);
double quartile_III(int, const double[]);

/*
    computes the quartile distance
*/
double quartile_distance(int, const double[]);

#endif