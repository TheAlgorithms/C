/**
 * \file
 * \authors [Krishna Vedala](https://github.com/kvedala)
 * \brief Solve a multivariable first order [ordinary differential equation
 * (ODEs)](https://en.wikipedia.org/wiki/Ordinary_differential_equation) using
 * [midpoint Euler
 * method](https://en.wikipedia.org/wiki/Midpoint_method)
 *
 * \details
 * The ODE being solved is:
 * \f{eqnarray*}{
 * \dot{u} &=& v\\
 * \dot{v} &=& -\omega^2 u\\
 * \omega &=& 1\\
 * [x_0, u_0, v_0] &=& [0,1,0]\qquad\ldots\text{(initial values)}
 * \f}
 * The exact solution for the above problem is:
 * \f{eqnarray*}{
 * u(x) &=& \cos(x)\\
 * v(x) &=& -\sin(x)\\
 * \f}
 * The computation results are stored to a text file `midpoint_euler.csv` and
 * the exact soltuion results in `exact.csv` for comparison. <img
 * src="https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/numerical_methods/ode_midpoint_euler.svg"
 * alt="Implementation solution"/>
 *
 * To implement [Van der Pol
 * oscillator](https://en.wikipedia.org/wiki/Van_der_Pol_oscillator), change the
 * ::problem function to:
 * ```cpp
 * const double mu = 2.0;
 * dy[0] = y[1];
 * dy[1] = mu * (1.f - y[0] * y[0]) * y[1] - y[0];
 * ```
 * \see ode_forward_euler.c, ode_semi_implicit_euler.c
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define order 2 /**< number of dependent variables in ::problem */

/**
 * @brief Problem statement for a system with first-order differential
 * equations. Updates the system differential variables.
 * \note This function can be updated to and ode of any order.
 *
 * @param[in] 		x 		independent variable(s)
 * @param[in,out]	y		dependent variable(s)
 * @param[in,out]	dy	    first-derivative of dependent variable(s)
 */
void problem(const double *x, double *y, double *dy)
{
    const double omega = 1.F;       // some const for the problem
    dy[0] = y[1];                   // x dot
    dy[1] = -omega * omega * y[0];  // y dot
}

/**
 * @brief Exact solution of the problem. Used for solution comparison.
 *
 * @param[in] 		x 		independent variable
 * @param[in,out]	y		dependent variable
 */
void exact_solution(const double *x, double *y)
{
    y[0] = cos(x[0]);
    y[1] = -sin(x[0]);
}

/**
 * @brief Compute next step approximation using the midpoint-Euler
 * method.
 * @f[y_{n+1} = y_n + dx\, f\left(x_n+\frac{1}{2}dx,
 * y_n + \frac{1}{2}dx\,f\left(x_n,y_n\right)\right)@f]
 * @param[in] 		dx	step size
 * @param[in,out] 	x	take @f$x_n@f$ and compute @f$x_{n+1}@f$
 * @param[in,out] 	y	take @f$y_n@f$ and compute @f$y_{n+1}@f$
 * @param[in,out]	dy	compute @f$y_n+\frac{1}{2}dx\,f\left(x_n,y_n\right)@f$
 */
void midpoint_euler_step(double dx, double *x, double *y, double *dy)
{
    problem(x, y, dy);
    double tmp_x = (*x) + 0.5 * dx;
    double tmp_y[order];
    int o;
    for (o = 0; o < order; o++) tmp_y[o] = y[o] + 0.5 * dx * dy[o];

    problem(&tmp_x, tmp_y, dy);

    for (o = 0; o < order; o++) y[o] += dx * dy[o];
}

/**
 * @brief Compute approximation using the midpoint-Euler
 * method in the given limits.
 * @param[in] 		dx  	step size
 * @param[in]   	x0  	initial value of independent variable
 * @param[in] 	    x_max	final value of independent variable
 * @param[in,out] 	y	    take \f$y_n\f$ and compute \f$y_{n+1}\f$
 * @param[in] save_to_file	flag to save results to a CSV file (1) or not (0)
 * @returns time taken for computation in seconds
 */
double midpoint_euler(double dx, double x0, double x_max, double *y,
                      char save_to_file)
{
    double dy[order];

    FILE *fp = NULL;
    if (save_to_file)
    {
        fp = fopen("midpoint_euler.csv", "w+");
        if (fp == NULL)
        {
            perror("Error! ");
            return -1;
        }
    }

    /* start integration */
    clock_t t1 = clock();
    double x = x0;
    do  // iterate for each step of independent variable
    {
        if (save_to_file && fp)
            fprintf(fp, "%.4g,%.4g,%.4g\n", x, y[0], y[1]);  // write to file
        midpoint_euler_step(dx, &x, y, dy);  // perform integration
        x += dx;                             // update step
    } while (x <= x_max);  // till upper limit of independent variable
    /* end of integration */
    clock_t t2 = clock();

    if (save_to_file && fp)
        fclose(fp);

    return (double)(t2 - t1) / CLOCKS_PER_SEC;
}

/**
    Main Function
*/
int main(int argc, char *argv[])
{
    double X0 = 0.f;          /* initial value of x0 */
    double X_MAX = 10.F;      /* upper limit of integration */
    double Y0[] = {1.f, 0.f}; /* initial value Y = y(x = x_0) */
    double step_size;

    if (argc == 1)
    {
        printf("\nEnter the step size: ");
        scanf("%lg", &step_size);
    }
    else
        // use commandline argument as independent variable step size
        step_size = atof(argv[1]);

    // get approximate solution
    double total_time = midpoint_euler(step_size, X0, X_MAX, Y0, 1);
    printf("\tTime = %.6g ms\n", total_time);

    /* compute exact solution for comparion */
    FILE *fp = fopen("exact.csv", "w+");
    if (fp == NULL)
    {
        perror("Error! ");
        return -1;
    }
    double x = X0;
    double *y = &(Y0[0]);
    printf("Finding exact solution\n");
    clock_t t1 = clock();

    do
    {
        fprintf(fp, "%.4g,%.4g,%.4g\n", x, y[0], y[1]);  // write to file
        exact_solution(&x, y);
        x += step_size;
    } while (x <= X_MAX);

    clock_t t2 = clock();
    total_time = (t2 - t1) / CLOCKS_PER_SEC;
    printf("\tTime = %.6g ms\n", total_time);
    fclose(fp);

    return 0;
}
