/**
 * @file
 * @brief Functions related to 3D vector operations.
 * @author Krishna Vedala
 */

#include <stdio.h>
#ifdef __arm__  // if compiling for ARM-Cortex processors
#define LIBQUAT_ARM
#include <arm_math.h>
#else
#include <math.h>
#endif
#include <assert.h>

#include "geometry_datatypes.h"

/**
 * @addtogroup vec_3d 3D Vector operations
 * @{
 */

/**
 * Subtract one vector from another. @f[
 * \vec{c}=\vec{a}-\vec{b}=\left(a_x-b_x\right)\hat{i}+
 * \left(a_y-b_y\right)\hat{j}+\left(a_z-b_z\right)\hat{k}@f]
 * @param[in] a vector to subtract from
 * @param[in] b vector to subtract
 * @returns resultant vector
 */
vec_3d vector_sub(const vec_3d *a, const vec_3d *b)
{
    vec_3d out;
#ifdef LIBQUAT_ARM
    arm_sub_f32((float *)a, (float *)b, (float *)&out);
#else
    out.x = a->x - b->x;
    out.y = a->y - b->y;
    out.z = a->z - b->z;
#endif

    return out;
}

/**
 * Add one vector to another. @f[
 * \vec{c}=\vec{a}+\vec{b}=\left(a_x+b_x\right)\hat{i}+
 * \left(a_y+b_y\right)\hat{j}+\left(a_z+b_z\right)\hat{k}@f]
 * @param[in] a vector to add to
 * @param[in] b vector to add
 * @returns resultant vector
 */
vec_3d vector_add(const vec_3d *a, const vec_3d *b)
{
    vec_3d out;
#ifdef LIBQUAT_ARM
    arm_add_f32((float *)a, (float *)b, (float *)&out);
#else
    out.x = a->x + b->x;
    out.y = a->y + b->y;
    out.z = a->z + b->z;
#endif

    return out;
}

/**
 * Obtain the dot product of two 3D vectors.
 * @f[
 * \vec{a}\cdot\vec{b}=a_xb_x + a_yb_y + a_zb_z
 * @f]
 * @param[in] a first vector
 * @param[in] b second vector
 * @returns resulting dot product
 */
float dot_prod(const vec_3d *a, const vec_3d *b)
{
    float dot;
#ifdef LIBQUAT_ARM
    arm_dot_prod_f32((float *)a, (float *)b, &dot);
#else
    dot = a->x * b->x;
    dot += a->y * b->y;
    dot += a->z * b->z;
#endif

    return dot;
}

/**
 * Compute the vector product of two 3d vectors.
 * @f[\begin{align*}
 * \vec{a}\times\vec{b} &= \begin{vmatrix}
 *  \hat{i} & \hat{j} & \hat{k}\\
 *  a_x & a_y & a_z\\
 *  b_x & b_y & b_z
 *  \end{vmatrix}\\
 *  &= \left(a_yb_z-b_ya_z\right)\hat{i} - \left(a_xb_z-b_xa_z\right)\hat{j}
 * + \left(a_xb_y-b_xa_y\right)\hat{k} \end{align*}
 * @f]
 * @param[in] a first vector @f$\vec{a}@f$
 * @param[in] b second vector @f$\vec{b}@f$
 * @returns resultant vector @f$\vec{o}=\vec{a}\times\vec{b}@f$
 */
vec_3d vector_prod(const vec_3d *a, const vec_3d *b)
{
    vec_3d out;  // better this way to avoid copying results to input
                 // vectors themselves
    out.x = a->y * b->z - a->z * b->y;
    out.y = -a->x * b->z + a->z * b->x;
    out.z = a->x * b->y - a->y * b->x;

    return out;
}

/**
 * Print formatted vector on stdout.
 * @param[in] a vector to print
 * @param[in] name  name of the vector
 * @returns string representation of vector
 */
const char *print_vector(const vec_3d *a, const char *name)
{
    static char vec_str[100];  // static to ensure the string life extends the
                               // life of function

    snprintf(vec_str, 99, "vec(%s) = (%.3g)i + (%.3g)j + (%.3g)k\n", name, a->x,
             a->y, a->z);
    return vec_str;
}

/**
 * Compute the norm a vector.
 * @f[\lVert\vec{a}\rVert = \sqrt{\vec{a}\cdot\vec{a}} @f]
 * @param[in] a input vector
 * @returns norm of the given vector
 */
float vector_norm(const vec_3d *a)
{
    float n = dot_prod(a, a);
#ifdef LIBQUAT_ARM
    arm_sqrt_f32(*n, n);
#else
    n = sqrtf(n);
#endif

    return n;
}

/**
 * Obtain unit vector in the same direction as given vector.
 * @f[\hat{a}=\frac{\vec{a}}{\lVert\vec{a}\rVert}@f]
 * @param[in] a input vector
 * @returns n unit vector in the direction of @f$\vec{a}@f$
 */
vec_3d unit_vec(const vec_3d *a)
{
    vec_3d n = {0};

    float norm = vector_norm(a);
    if (fabsf(norm) < EPSILON)
    {  // detect possible divide by 0
        return n;
    }

    if (norm != 1.F)  // perform division only if needed
    {
        n.x = a->x / norm;
        n.y = a->y / norm;
        n.z = a->z / norm;
    }
    return n;
}

/**
 * The cross product of vectors can be represented as a matrix
 * multiplication operation. This function obtains the `3x3` matrix
 * of the cross-product operator from the first vector.
 * @f[\begin{align*}
 * \left(\vec{a}\times\right)\vec{b} &= \tilde{A}_a\vec{b}\\
 * \tilde{A}_a &=
 * \begin{bmatrix}0&-a_z&a_y\\a_z&0&-a_x\\-a_y&a_x&0\end{bmatrix}
 * \end{align*}@f]
 * @param[in] a input vector
 * @returns the `3x3` matrix for the cross product operator
 * @f$\left(\vec{a}\times\right)@f$
 */
mat_3x3 get_cross_matrix(const vec_3d *a)
{
    mat_3x3 A = {0., -a->z, a->y, a->z, 0., -a->x, -a->y, a->x, 0.};
    return A;
}

/**
 * Obtain the angle between two given vectors.
 * @f[\alpha=acos\left(\frac{\vec{a} \cdot \vec{b}}{\lVert\vec{a}\rVert \cdot \lVert\vec{b}\rVert}\right)@f]
 * @param[in] a first input vector
 * @param[in] b second input vector
 * @returns angle between @f$\vec{a}@f$ and @f$\vec{b}@f$ in radians
 */

double get_angle(const vec_3d *a, const vec_3d *b)
{
    double alpha, cos_alpha;
    float norm_a = vector_norm(a); ///< The norm of vector a
    float norm_b = vector_norm(b); ///< The norm of vector b
    if (fabsf(norm_a) < EPSILON || fabsf(norm_b) < EPSILON) /// detect possible division by 0 - the angle is not defined in this case
    {  
        return NAN; 
    }

    cos_alpha = dot_prod(a, b) / (norm_a * norm_b);
    alpha = acos(cos_alpha); // delivers the radian
    return alpha; // in range from -1 to 1
}

/** @} */

/**
 * @brief Testing function
 * @returns `void`
 */
static void test()
{
    vec_3d a = {1., 2., 3.};
    vec_3d b = {1., 1., 1.};
    float d;

    // printf("%s", print_vector(&a, "a"));
    // printf("%s", print_vector(&b, "b"));

    d = vector_norm(&a);
    // printf("|a| = %.4g\n", d);
    assert(fabsf(d - 3.742f) < 0.01);
    d = vector_norm(&b);
    // printf("|b| = %.4g\n", d);
    assert(fabsf(d - 1.732f) < 0.01);

    d = dot_prod(&a, &b);
    // printf("Dot product: %f\n", d);
    assert(fabsf(d - 6.f) < 0.01);

    vec_3d c = vector_prod(&a, &b);
    // printf("Vector product ");
    // printf("%s", print_vector(&c, "c"));
    assert(fabsf(c.x - (-1.f)) < 0.01);
    assert(fabsf(c.y - (2.f)) < 0.01);
    assert(fabsf(c.z - (-1.f)) < 0.01);

    double alpha = get_angle(&a, &b);
    // printf("The angle is %f\n", alpha);
    assert(fabsf(alpha - 0.387597) < 0.01);
}

/**
 * @brief Main function
 *
 * @return 0 on exit
 */
int main(void)
{
    test();

    return 0;
}
