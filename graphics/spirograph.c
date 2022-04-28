/**
 * @file
 * @author [Krishna Vedala](https://github.com/kvedala)
 * @brief Implementation of
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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
 * @param k the ratio of radius of inner circle to outer circle and
 * \f$0<k<1\f$
 * @param N number of sample points along the trajectory (higher = better
 * resolution but consumes more time and memory)
 * @param num_rot the number of rotations to perform (can be fractional value)
 */
void spirograph(double *x, double *y, double l, double k, size_t N, double rot)
{
    double dt = rot * 2.f * M_PI / N;
    double t = 0.f, R = 1.f;
    const double k1 = 1.f - k;

    for (size_t dk = 0; dk < N; dk++, t += dt)
    {
        x[dk] = R * (k1 * cos(t) + l * k * cos(k1 * t / k));
        y[dk] = R * (k1 * sin(t) - l * k * sin(k1 * t / k));
    }
}

/**
 * @brief Test function to save resulting points to a CSV file.
 *
 */
void test(void)
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

    free(x);
    free(y);
}

#ifdef USE_GLUT  // this is set by CMAKE automatically, if available
#ifdef __APPLE__
#include <GLUT/glut.h>  // include path on Macs is different
#else
#include <GL/glut.h>
#endif

static bool paused = 0; /**< flag to set pause/unpause animation */
static const int animation_speed = 25; /**< animation delate in ms */

static const double step = 0.01;   /**< animation step size */
static double l_ratio = 0.1;       /**< the l-ratio defined in docs */
static double k_ratio = 0.1;       /**< the k-ratio defined in docs */
static const double num_rot = 20.; /**< number of rotations to simulate */

/** A wrapper that is not available in all GLUT implementations.
 */
static inline void glutBitmapString(void *font, char *string)
{
    for (char *ch = string; *ch != '\0'; ch++) glutBitmapCharacter(font, *ch);
}

/**
 * @brief Function to graph (x,y) points on the OpenGL graphics window.
 *
 * @param x array containing absicca of points (must be pre-allocated)
 * @param y array containing ordinates of points (must be pre-allocated)
 * @param N number of points in the arrays
 */
void display_graph(const double *x, const double *y, size_t N, double l,
                   double k)
{
    glClearColor(1.0f, 1.0f, 1.0f,
                 0.0f);            // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (background)

    if (x && y)
    {
        glBegin(GL_LINES);         // draw line segments
        glColor3f(0.f, 0.f, 1.f);  // blue
        glPointSize(2.f);          // point size in pixels

        for (size_t i = 1; i < N; i++)
        {
            glVertex2f(x[i - 1], y[i - 1]);  // line from
            glVertex2f(x[i], y[i]);          // line to
        }
        glEnd();
    }
    glColor3f(0.f, 0.f, 0.f);
    char buffer[20];
    snprintf(buffer, 20, "l = %.3f", l);
    glRasterPos2f(-.85, .85);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, buffer);
    snprintf(buffer, 20, "k = %.3f", k);
    glRasterPos2f(-.85, .75);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, buffer);

    glutSwapBuffers();
}

/**
 * @brief Test function with animation
 *
 */
void test2(void)
{
    const size_t N = 1000;  // number of samples

    static bool direction1 = true;  // increment if true, otherwise decrement
    static bool direction2 = true;  // increment if true, otherwise decrement

    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));

    spirograph(x, y, l_ratio, k_ratio, N, num_rot);
    display_graph(x, y, N, l_ratio, k_ratio);

    free(x);  // free dynamic memories
    free(y);

    if (paused)
        // if paused, do not update l_ratio and k_ratio
        return;

    if (direction1)  // increment k_ratio
    {
        if (k_ratio >= (1.f - step))  // maximum limit
            direction1 = false;       // reverse direction of k_ratio
        else
            k_ratio += step;
    }
    else  // decrement k_ratio
    {
        if (k_ratio <= step)  // minimum limit
        {
            direction1 = true;  // reverse direction of k_ratio

            if (direction2)  // increment l_ratio
            {
                if (l_ratio >= (1.f - step))  // max limit of l_ratio
                    direction2 = false;       // reverse direction of l_ratio
                else
                    l_ratio += step;
            }
            else  // decrement l_ratio
            {
                if (l_ratio <= step)    // minimum limit of l_ratio
                    direction2 = true;  // reverse direction of l_ratio
                else
                    l_ratio -= step;
            }
        }
        else  // no min limit of k_ratio
            k_ratio -= step;
    }
}

/**
 * @brief GLUT timer callback function to add animation delay.
 */
void timer_cb(int id)
{
    glutPostRedisplay();
    glutTimerFunc(animation_speed, timer_cb, 0);
}

/**
 * @brief Keypress event call back function.
 *
 * @param key ID of the key pressed
 * @param x mouse pointer position at event
 * @param y mouse pointer position at event
 */
void keyboard_cb(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':              // spacebar toggles pause
        paused = !paused;  // toggle
        break;
    case '+':  // up arrow key
        k_ratio += step;
        display_graph(NULL, NULL, 1, l_ratio, k_ratio);
        break;
    case '_':  // down arrow key
        k_ratio -= step;
        display_graph(NULL, NULL, 1, l_ratio, k_ratio);
        break;
    case '=':  // left arrow key
        l_ratio += step;
        display_graph(NULL, NULL, 1, l_ratio, k_ratio);
        break;
    case '-':  // right arrow key
        l_ratio -= step;
        display_graph(NULL, NULL, 1, l_ratio, k_ratio);
        break;
    case 0x1B:  // escape key exits
        exit(EXIT_SUCCESS);
    }
}
#endif

/** Main function */
int main(int argc, char **argv)
{
    test();

#ifdef USE_GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Spirograph");
    glutInitWindowSize(400, 400);
    // glutIdleFunc(glutPostRedisplay);
    glutTimerFunc(animation_speed, timer_cb, 0);
    glutKeyboardFunc(keyboard_cb);
    glutDisplayFunc(test2);
    glutMainLoop();
#endif

    return 0;
}
