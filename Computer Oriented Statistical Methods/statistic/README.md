# Statistic-library for C

This repository contains a statistic library for the C programming language which prepare useful functions for dealing with average, standard deviation etc.   The library is platform-independent. So you can use this library with any C-compiler.  

### Usage

You needed to put in the files ```statistic.h``` and ```statistic.c``` in your project directory. After that you include the header file ```statistic.h```
in your project. Then you can use the functions of this library. You will find the files ```statistic.h``` and ```statistic.c``` in the directory **src**.  

### Overview about the functions

The first int-argument represents the size of the sample (double-array).  

```c
/*
    Computes the average of a given sample.
    The sample is a set of double values.
    The average-function gets a variable number of arguments. 
    The first argument must be the number of arguments!
    The averageArray-function instead gets a double-array of values and a int-number that
    represents the size of the double-array.
*/
double average_Array(int,const double[]);
double average(int,...);
```  

```c
/* 
    Computes the standard deviation (n-1)
*/
double standard_deviation(int,...);
double standard_deviation_array(int, const double[]);

/*
    Computes the standard deviation (n)
*/
double standard_deviation_N(int,...);
double standard_deviation_N_array(int, const double[]);
```  

```c
/*
    variance: computes the variance (n-1)
    variance_N: computes the variance (n)
*/
double variance(int, const double[]);
double variance_N(int, const double[]);
```  

```c
/*
    gets the max (min) element of the sample 
*/
double max(int, const double[]);
double min(int , const double[]);
```  

```c
/*
    computes the median of the sample
*/
double median(int, const double[]);
```  

```c
/*
    adds up all values of the sample.
*/
double sum(int,const double[]);
```  

```c
/* 
    computes the range of the sample.
*/
double range(int, const double[]);
```  

```c
/*
    gets the frequency of the last argument (double) of that sample.
*/
double frequency_of(int, const double[], double);
```  

```c
/* 
    quartile_I: computes the first quartile.
    quartile_III: computes the third quartile.
    The second quartile is the median!
*/
double quartile_I(int, const double[]);
double quartile_III(int, const double[]);
```  

```c
/*
    computes the quartile distance
*/
double quartile_distance(int, const double[]);
```  


### Running the tests

You navigate in the directory of this repository and type in the console:  

```bash
gcc -o myTests test/test.c src/statistic.c  -lcunit -lm  && ./myTests
```

#### Dependencies for tests  

* CUnit 
* gcc

