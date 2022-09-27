/**
 * \file
 * \brief [Kohonen self organizing
 * map](https://en.wikipedia.org/wiki/Self-organizing_map) (data tracing)
 *
 * \details
 * This example implements a powerful self organizing map algorithm.
 * The algorithm creates a connected network of weights that closely
 * follows the given data points. This creates a chain of nodes that
 * resembles the given input shape.
 * \author [Krishna Vedala](https://github.com/kvedala)
 * \see kohonen_som_topology.c
 */
#define _USE_MATH_DEFINES /**< required for MS Visual C */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP  // check if OpenMP based parallelization is available
#include <omp.h>
#endif

/**
 * @addtogroup machine_learning Machine learning algorithms
 * @{
 * @addtogroup kohonen_1d Kohonen SOM trace/chain algorithm
 * @{
 */

#ifndef max
/** shorthand for maximum value */
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
/** shorthand for minimum value */
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

/**
 * \brief Helper function to generate a random number in a given interval.
 * \details
 * \n Steps:
 * 1. `r1 = rand() % 100` gets a random number between 0 and 99
 * 2. `r2 = r1 / 100` converts random number to be between 0 and 0.99
 * 3. scale and offset the random number to given range of \f$[a,b)\f$
 * \f[
 * y = (b - a) \times \frac{\text{(random number between 0 and RAND_MAX)} \;
 * \text{mod}\; 100}{100} + a \f]
 *
 * \param a lower limit
 * \param b upper limit
 * \returns random number in the range \f$[a,b)\f$
 */
double _random(double a, double b)
{
    int r = rand() % 100;
    return ((b - a) * r / 100.f) + a;
}

/**
 * Save a given n-dimensional data martix to file.
 *
 * \param [in] fname filename to save in (gets overwriten without confirmation)
 * \param [in] X matrix to save
 * \param [in] num_points rows in the matrix = number of points
 * \param [in] num_features columns in the matrix = dimensions of points
 * \returns 0 if all ok
 * \returns -1 if file creation failed
 */
int save_nd_data(const char *fname, double **X, int num_points,
                 int num_features)
{
    FILE *fp = fopen(fname, "wt");
    if (!fp)  // error with fopen
    {
        char msg[120];
        sprintf(msg, "File error (%s): ", fname);
        perror(msg);
        return -1;
    }

    for (int i = 0; i < num_points; i++)  // for each point in the array
    {
        for (int j = 0; j < num_features; j++)  // for each feature in the array
        {
            fprintf(fp, "%.4g", X[i][j]);  // print the feature value
            if (j < num_features - 1)      // if not the last feature
                fprintf(fp, ",");          // suffix comma
        }
        if (i < num_points - 1)  // if not the last row
            fprintf(fp, "\n");   // start a new line
    }
    fclose(fp);
    return 0;
}

/**
 * Get minimum value and index of the value in a vector
 * \param[in] X vector to search
 * \param[in] N number of points in the vector
 * \param[out] val minimum value found
 * \param[out] idx index where minimum value was found
 */
void kohonen_get_min_1d(double const *X, int N, double *val, int *idx)
{
    val[0] = INFINITY;  // initial min value

    for (int i = 0; i < N; i++)  // check each value
    {
        if (X[i] < val[0])  // if a lower value is found
        {                   // save the value and its index
            idx[0] = i;
            val[0] = X[i];
        }
    }
}

/**
 * Update weights of the SOM using Kohonen algorithm
 *
 * \param[in] x data point
 * \param[in,out] W weights matrix
 * \param[in,out] D temporary vector to store distances
 * \param[in] num_out number of output points
 * \param[in] num_features number of features per input sample
 * \param[in] alpha learning rate \f$0<\alpha\le1\f$
 * \param[in] R neighborhood range
 */
void kohonen_update_weights(double const *x, double *const *W, double *D,
                            int num_out, int num_features, double alpha, int R)
{
    int j, k;

#ifdef _OPENMP
#pragma omp for
#endif
    // step 1: for each output point
    for (j = 0; j < num_out; j++)
    {
        D[j] = 0.f;
        // compute Euclidian distance of each output
        // point from the current sample
        for (k = 0; k < num_features; k++)
            D[j] += (W[j][k] - x[k]) * (W[j][k] - x[k]);
    }

    // step 2:  get closest node i.e., node with smallest Euclidian distance to
    // the current pattern
    int d_min_idx;
    double d_min;
    kohonen_get_min_1d(D, num_out, &d_min, &d_min_idx);

    // step 3a: get the neighborhood range
    int from_node = max(0, d_min_idx - R);
    int to_node = min(num_out, d_min_idx + R + 1);

    // step 3b: update the weights of nodes in the
    // neighborhood
#ifdef _OPENMP
#pragma omp for
#endif
    for (j = from_node; j < to_node; j++)
        for (k = 0; k < num_features; k++)
            // update weights of nodes in the neighborhood
            W[j][k] += alpha * (x[k] - W[j][k]);
}

/**
 * Apply incremental algorithm with updating neighborhood and learning rates
 * on all samples in the given datset.
 *
 * \param[in] X data set
 * \param[in,out] W weights matrix
 * \param[in] num_samples number of output points
 * \param[in] num_features number of features per input sample
 * \param[in] num_out number of output points
 * \param[in] alpha_min terminal value of alpha
 */
void kohonen_som_tracer(double **X, double *const *W, int num_samples,
                        int num_features, int num_out, double alpha_min)
{
    int R = num_out >> 2, iter = 0;
    double alpha = 1.f;
    double *D = (double *)malloc(num_out * sizeof(double));

    // Loop alpha from 1 to alpha_min
    for (; alpha > alpha_min; alpha -= 0.01, iter++)
    {
        // Loop for each sample pattern in the data set
        for (int sample = 0; sample < num_samples; sample++)
        {
            const double *x = X[sample];
            // update weights for the current input pattern sample
            kohonen_update_weights(x, W, D, num_out, num_features, alpha, R);
        }

        // every 10th iteration, reduce the neighborhood range
        if (iter % 10 == 0 && R > 1)
            R--;
    }

    free(D);
}

/**
 * @}
 * @}
 */

/** Creates a random set of points distributed *near* the circumference
 * of a circle and trains an SOM that finds that circular pattern. The
 * generating function is
 * \f{eqnarray*}{
 * r &\in& [1-\delta r, 1+\delta r)\\
 * \theta &\in& [0, 2\pi)\\
 * x &=& r\cos\theta\\
 * y &=& r\sin\theta
 * \f}
 *
 * \param[out] data matrix to store data in
 * \param[in] N number of points required
 */
void test_circle(double *const *data, int N)
{
    const double R = 0.75, dr = 0.3;
    double a_t = 0., b_t = 2.f * M_PI;  // theta random between 0 and 2*pi
    double a_r = R - dr, b_r = R + dr;  // radius random between R-dr and R+dr
    int i;

#ifdef _OPENMP
#pragma omp for
#endif
    for (i = 0; i < N; i++)
    {
        double r = _random(a_r, b_r);      // random radius
        double theta = _random(a_t, b_t);  // random theta
        data[i][0] = r * cos(theta);       // convert from polar to cartesian
        data[i][1] = r * sin(theta);
    }
}

/** Test that creates a random set of points distributed *near* the
 * circumference of a circle and trains an SOM that finds that circular pattern.
 * The following [CSV](https://en.wikipedia.org/wiki/Comma-separated_values)
 * files are created to validate the execution:
 * * `test1.csv`: random test samples points with a circular pattern
 * * `w11.csv`: initial random map
 * * `w12.csv`: trained SOM map
 *
 * The outputs can be readily plotted in [gnuplot](https:://gnuplot.info) using
 * the following snippet
 * ```gnuplot
 * set datafile separator ','
 * plot "test1.csv" title "original", \
 *      "w11.csv" title "w1", \
 *      "w12.csv" title "w2"
 * ```
 * ![Sample execution
 * output](https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/machine_learning/kohonen/test1.svg)
 */
void test1()
{
    int j, N = 500;
    int features = 2;
    int num_out = 50;

    // 2D space, hence size = number of rows * 2
    double **X = (double **)malloc(N * sizeof(double *));

    // number of clusters nodes * 2
    double **W = (double **)malloc(num_out * sizeof(double *));

    for (int i = 0; i < max(num_out, N); i++)  // loop till max(N, num_out)
    {
        if (i < N)  // only add new arrays if i < N
            X[i] = (double *)malloc(features * sizeof(double));
        if (i < num_out)  // only add new arrays if i < num_out
        {
            W[i] = (double *)malloc(features * sizeof(double));
#ifdef _OPENMP
#pragma omp for
#endif
            // preallocate with random initial weights
            for (j = 0; j < features; j++) W[i][j] = _random(-1, 1);
        }
    }

    test_circle(X, N);  // create test data around circumference of a circle
    save_nd_data("test1.csv", X, N, features);  // save test data points
    save_nd_data("w11.csv", W, num_out,
                 features);  // save initial random weights
    kohonen_som_tracer(X, W, N, features, num_out, 0.1);  // train the SOM
    save_nd_data("w12.csv", W, num_out,
                 features);  // save the resultant weights

    for (int i = 0; i < max(num_out, N); i++)
    {
        if (i < N)
            free(X[i]);
        if (i < num_out)
            free(W[i]);
    }
}

/** Creates a random set of points distributed *near* the locus
 * of the [Lamniscate of
 * Gerono](https://en.wikipedia.org/wiki/Lemniscate_of_Gerono).
 * \f{eqnarray*}{
 * \delta r &=& 0.2\\
 * \delta x &\in& [-\delta r, \delta r)\\
 * \delta y &\in& [-\delta r, \delta r)\\
 * \theta &\in& [0, \pi)\\
 * x &=& \delta x + \cos\theta\\
 * y &=& \delta y + \frac{\sin(2\theta)}{2}
 * \f}
 * \param[out] data matrix to store data in
 * \param[in] N number of points required
 */
void test_lamniscate(double *const *data, int N)
{
    const double dr = 0.2;
    int i;

#ifdef _OPENMP
#pragma omp for
#endif
    for (i = 0; i < N; i++)
    {
        double dx = _random(-dr, dr);     // random change in x
        double dy = _random(-dr, dr);     // random change in y
        double theta = _random(0, M_PI);  // random theta
        data[i][0] = dx + cos(theta);     // convert from polar to cartesian
        data[i][1] = dy + sin(2. * theta) / 2.f;
    }
}

/** Test that creates a random set of points distributed *near* the locus
 * of the [Lamniscate of
 * Gerono](https://en.wikipedia.org/wiki/Lemniscate_of_Gerono) and trains an SOM
 * that finds that circular pattern. The following
 * [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) files are created
 * to validate the execution:
 * * `test2.csv`: random test samples points with a lamniscate pattern
 * * `w21.csv`: initial random map
 * * `w22.csv`: trained SOM map
 *
 * The outputs can be readily plotted in [gnuplot](https:://gnuplot.info) using
 * the following snippet
 * ```gnuplot
 * set datafile separator ','
 * plot "test2.csv" title "original", \
 *      "w21.csv" title "w1", \
 *      "w22.csv" title "w2"
 * ```
 * ![Sample execution
 * output](https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/machine_learning/kohonen/test2.svg)
 */
void test2()
{
    int j, N = 500;
    int features = 2;
    int num_out = 20;
    double **X = (double **)malloc(N * sizeof(double *));
    double **W = (double **)malloc(num_out * sizeof(double *));
    for (int i = 0; i < max(num_out, N); i++)
    {
        if (i < N)  // only add new arrays if i < N
            X[i] = (double *)malloc(features * sizeof(double));
        if (i < num_out)  // only add new arrays if i < num_out
        {
            W[i] = (double *)malloc(features * sizeof(double));

#ifdef _OPENMP
#pragma omp for
#endif
            // preallocate with random initial weights
            for (j = 0; j < features; j++) W[i][j] = _random(-1, 1);
        }
    }

    test_lamniscate(X, N);  // create test data around the lamniscate
    save_nd_data("test2.csv", X, N, features);  // save test data points
    save_nd_data("w21.csv", W, num_out,
                 features);  // save initial random weights
    kohonen_som_tracer(X, W, N, features, num_out, 0.01);  // train the SOM
    save_nd_data("w22.csv", W, num_out,
                 features);  // save the resultant weights

    for (int i = 0; i < max(num_out, N); i++)
    {
        if (i < N)
            free(X[i]);
        if (i < num_out)
            free(W[i]);
    }
    free(X);
    free(W);
}

/** Creates a random set of points distributed in four clusters in
 * 3D space with centroids at the points
 * * \f$(0,5, 0.5, 0.5)\f$
 * * \f$(0,5,-0.5, -0.5)\f$
 * * \f$(-0,5, 0.5, 0.5)\f$
 * * \f$(-0,5,-0.5, -0.5)\f$
 *
 * \param[out] data matrix to store data in
 * \param[in] N number of points required
 */
void test_3d_classes(double *const *data, int N)
{
    const double R = 0.1;  // radius of cluster
    int i;
    const int num_classes = 4;
    const double centres[][3] = {
        // centres of each class cluster
        {.5, .5, .5},    // centre of class 1
        {.5, -.5, -.5},  // centre of class 2
        {-.5, .5, .5},   // centre of class 3
        {-.5, -.5 - .5}  // centre of class 4
    };

#ifdef _OPENMP
#pragma omp for
#endif
    for (i = 0; i < N; i++)
    {
        int class =
            rand() % num_classes;  // select a random class for the point

        // create random coordinates (x,y,z) around the centre of the class
        data[i][0] = _random(centres[class][0] - R, centres[class][0] + R);
        data[i][1] = _random(centres[class][1] - R, centres[class][1] + R);
        data[i][2] = _random(centres[class][2] - R, centres[class][2] + R);

        /* The follosing can also be used
        for (int j = 0; j < 3; j++)
            data[i][j] = _random(centres[class][j] - R, centres[class][j] + R);
        */
    }
}

/** Test that creates a random set of points distributed in six clusters in
 * 3D space. The following
 * [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) files are created
 * to validate the execution:
 * * `test3.csv`: random test samples points with a circular pattern
 * * `w31.csv`: initial random map
 * * `w32.csv`: trained SOM map
 *
 * The outputs can be readily plotted in [gnuplot](https:://gnuplot.info) using
 * the following snippet
 * ```gnuplot
 * set datafile separator ','
 * plot "test3.csv" title "original", \
 *      "w31.csv" title "w1", \
 *      "w32.csv" title "w2"
 * ```
 * ![Sample execution
 * output](https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/machine_learning/kohonen/test3.svg)
 */
void test3()
{
    int j, N = 200;
    int features = 3;
    int num_out = 20;
    double **X = (double **)malloc(N * sizeof(double *));
    double **W = (double **)malloc(num_out * sizeof(double *));
    for (int i = 0; i < max(num_out, N); i++)
    {
        if (i < N)  // only add new arrays if i < N
            X[i] = (double *)malloc(features * sizeof(double));
        if (i < num_out)  // only add new arrays if i < num_out
        {
            W[i] = (double *)malloc(features * sizeof(double));

#ifdef _OPENMP
#pragma omp for
#endif
            // preallocate with random initial weights
            for (j = 0; j < features; j++) W[i][j] = _random(-1, 1);
        }
    }

    test_3d_classes(X, N);  // create test data around the lamniscate
    save_nd_data("test3.csv", X, N, features);  // save test data points
    save_nd_data("w31.csv", W, num_out,
                 features);  // save initial random weights
    kohonen_som_tracer(X, W, N, features, num_out, 0.01);  // train the SOM
    save_nd_data("w32.csv", W, num_out,
                 features);  // save the resultant weights

    for (int i = 0; i < max(num_out, N); i++)
    {
        if (i < N)
            free(X[i]);
        if (i < num_out)
            free(W[i]);
    }
    free(X);
    free(W);
}

/**
 * Convert clock cycle difference to time in seconds
 *
 * \param[in] start_t start clock
 * \param[in] end_t end clock
 * \returns time difference in seconds
 */
double get_clock_diff(clock_t start_t, clock_t end_t)
{
    return (double)(end_t - start_t) / (double)CLOCKS_PER_SEC;
}

/** Main function */
int main(int argc, char **argv)
{
#ifdef _OPENMP
    printf("Using OpenMP based parallelization\n");
#else
    printf("NOT using OpenMP based parallelization\n");
#endif
    clock_t start_clk = clock();
    test1();
    clock_t end_clk = clock();
    printf("Test 1 completed in %.4g sec\n",
           get_clock_diff(start_clk, end_clk));
    start_clk = clock();
    test2();
    end_clk = clock();
    printf("Test 2 completed in %.4g sec\n",
           get_clock_diff(start_clk, end_clk));
    start_clk = clock();
    test3();
    end_clk = clock();
    printf("Test 3 completed in %.4g sec\n",
           get_clock_diff(start_clk, end_clk));
    printf(
        "(Note: Calculated times include: creating test sets, training "
        "model and writing files to disk.)\n\n");
    return 0;
}
