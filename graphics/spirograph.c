/**
 * @file
 * @author [Krishna Vedala](https://github.com/kvedala)
 * @brief Program to generate plots from
 * [Spirograph](https://en.wikipedia.org/wiki/Spirograph)
 *
 * @details
 * Implementation of the program is based on the geometry shown in the figure
 * below:
 *
 * <a
 * href="https://commons.wikimedia.org/wiki/File:Resonance_Cascade.svg"><img
 * src="https://upload.wikimedia.org/wikipedia/commons/3/39/Resonance_Cascade.svg"
 * alt="Spirograph geometry from Wikipedia" style="width: 250px"/></a>
 */
#define _USE_MATH_DEFINES
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/** Generate spirograph curve into arrays `x` and `y` such that the i^th point
 * in 2D is represented by `(x[i],y[i])`. The generating function is given by:
 * \f{eqnarray*}{
 * x &=& R\left[ (1-k)* \cos t + lk\cos \frac{1-k}{k}t \right]\\
 * y &=& R\left[ (1-k)* \sin t - lk\sin \frac{1-k}{k}t \right]
 * \f}
 * where
 * * \f$R\f$ is the scaling parameter that we will consider \f$=1\f$
 * * \f$l\frac{\rho}{r}\f$ is the relative distance of marker from the centre of
 * inner circle and \f$0\le l\le1\f$
 * * \f$\rho\f$ is physical distance of marker from centre of inner circle
 * * \f$r\f$ is the radius of inner circle
 * * \f$k=\frac{r}{R}\f$ is the ratio of radius of inner circle to outer circle
 * and \f$0<k<1\f$
 * * \f$R\f$ is the radius of outer circle
 * * \f$t\f$ is the angle of rotation of the point i.e., represents the time
 * parameter
 *
 * Since we are considering ratios, the actual values of \f$r\f$ and
 * \f$R\f$ are immaterial.
 *
 * @param [out] x output array containing absicca of points
 * @param [out] y output array containing ordinates of points
 * @param l the relative distance of marker from the centre of
 * inner circle and \f$0\le l\le1\f$
 * @param k the ratio of radius of inner circle to outer circle and \f$0<k<1\f$
 * @param N number of sample points along the trajectory (higher = better
 * resolution but consumes more time and memory)
 * @param rot the number of rotations to perform
 */
void spirograph(double *x, double *y, double l, double k, double N, double rot)
{
    double dt = rot * M_PI / N;
    double t, R = 1.f;
    const double k1 = 1.f - k;

    for (int step = 0; step < N; step++, t += dt)
    {
        x[step] = R * (k1 * cos(t) + l * k * cos(k1 * t / k));
        y[step] = R * (k1 * sin(t) - l * k * sin(k1 * t / k));
    }
}

void test() {}

/** Main function */
int main(int argc, char **argv)
{
    test();

    return 0;
}
