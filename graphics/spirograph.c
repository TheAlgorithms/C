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
#define _USE_MATH_DEFINES /**< required for MSVC compiler */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef USE_GLUT  // this is set by CMAKE automatically, if available
#include <gl/glut.h>

/**
 * @brief Function to graph (x,y) points on the OpenGL graphics window.
 *
 * @param x array containing absicca of points (must be pre-allocated)
 * @param y array containing ordinates of points (must be pre-allocated)
 * @param N number of points in the the arrays
 */
void display_graph(const double *x, const double *y, size_t N)
{
    glClearColor(1.0f, 1.0f, 1.0f,
                 0.0f);            // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (background)

    glBegin(GL_LINES);         // draw line segments
    glColor3f(0.f, 0.f, 1.f);  // blue
    glPointSize(2.f);          // point size in pixels

    for (size_t i = 1; i < N; i++)
    {
        glVertex2f(x[i - 1], y[i - 1]);  // line from
        glVertex2f(x[i], y[i]);          // line to
    }
    glEnd();
    glFlush();
}
#endif

/** Generate spirograph curve into arrays `x` and `y` such that the i^th point
 * in 2D is represented by `(x[i],y[i])`. The generating function is given by:
 * \f{eqnarray*}{
 * x &=& R\left[ (1-k) \cos (t) + l\cdot k\cdot\cos \left(\frac{1-k}{k}t\right)
 * \right]\\
 * y &=& R\left[ (1-k) \sin (t) - l\cdot k\cdot\sin \left(\frac{1-k}{k}t\right)
 * \right] \f}
 * where
 * * \f$R\f$ is the scaling parameter that we will consider \f$=1\f$
 * * \f$l=\frac{\rho}{r}\f$ is the relative distance of marker from the centre
 * of inner circle and \f$0\le l\le1\f$
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
 * @param [out] x output array containing absicca of points (must be
 * pre-allocated)
 * @param [out] y output array containing ordinates of points (must be
 * pre-allocated)
 * @param l the relative distance of marker from the centre of
 * inner circle and \f$0\le l\le1\f$
 * @param k the ratio of radius of inner circle to outer circle and \f$0<k<1\f$
 * @param N number of sample points along the trajectory (higher = better
 * resolution but consumes more time and memory)
 * @param rot the number of rotations to perform (can be fractional value)
 */
void spirograph(double *x, double *y, double l, double k, size_t N, double rot)
{
    double dt = rot * M_PI / N;
    double t = 0.f, R = 1.f;
    const double k1 = 1.f - k;

    for (size_t step = 0; step < N; step++, t += dt)
    {
        x[step] = R * (k1 * cos(t) + l * k * cos(k1 * t / k));
        y[step] = R * (k1 * sin(t) - l * k * sin(k1 * t / k));
    }
}

/**
 * @brief Test function
 *
 */
void test()
{
    size_t N = 500;
    double l = 0.3, k = 0.75, rot = 10.;
    char fname[50];
    snprintf(fname, 50, "spirograph_%.2f_%.2f_%.2f.csv", l, k, rot);
    FILE *fp = fopen(fname, "wt");
    if (!fp)
    {
        perror(fname);
        exit(EXIT_FAILURE);
    }

    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));

    spirograph(x, y, l, k, N, rot);

    for (size_t i = 0; i < N; i++)
    {
        fprintf(fp, "%.5g, %.5g", x[i], y[i]);
        if (i < N - 1)
        {
            fputc('\n', fp);
        }
    }

    fclose(fp);

#ifdef USE_GLUT
    display_graph(x, y, N);
#endif

    free(x);
    free(y);
}

/** Main function */
int main(int argc, char **argv)
{
#ifdef USE_GLUT
    glutInit(&argc, argv);
    glutCreateWindow("Spirograph");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(test);
    glutMainLoop();
#else
    test();
#endif

    return 0;
}
