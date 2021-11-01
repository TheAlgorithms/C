/**
 * @addtogroup quaternions Library for 3D Vectors & Quaternions
 * @{
 * @file
 * @brief Generic header that provides data types for 3D vectors and quaternions
 * @author Krishna Vedala
 */

#ifndef __LIBQUAT_H_
#define __LIBQUAT_H_

/** Minimum recognizable value. Any value less than this is considered to be
 * @f$=0@f$ */
#define EPSILON 1e-9

/**
 * @addtogroup vec_3d 3D Vector operations
 * @{
 */
/** 3D vector type */
typedef struct vec_3d_
{
    float x; /**< X co-ordinate */
    float y; /**< Y co-ordinate */
    float z; /**< Z co-ordinate */
} vec_3d;
/** @} */

/**
 * @addtogroup matrix Matrix operations
 * @{
 */
/** A 3x3 Matrix type definition */
typedef struct mat_3x3_
{
    union
    { /**< 3 element row 1 */
        float row1[3];
        vec_3d vec1;
    };
    union
    { /**< 3 element row 2 */
        float row2[3];
        vec_3d vec2;
    };
    union
    { /**< 3 element row 3 */
        float row3[3];
        vec_3d vec3;
    };
} mat_3x3;
/** @} */

/** @addtogroup quats 3D Quaternion operations
 * @{
 */
/** a Quaternion type represented using a scalar \f$w\f$ or \f$q_0\f$ and a
 * 3D vector \f$\left(q_1,q_2,q_3\right)\f$
 */
typedef struct quaternion_
{
    union
    {
        float w;  /**< real part of quaternion */
        float q0; /**< real part of quaternion */
    };
    /**< dual part of quaternion */
    union
    {
        vec_3d dual; /**< can be a 3D vector */
        /** or individual values */
        struct
        {
            float q1, q2, q3;
        };
    };
} quaternion;

/** 3D Euler or Tait-Bryan angles (in radian) */
typedef struct euler_
{
    union
    {
        float roll; /**< or bank \f$\phi\f$ = rotation about X axis */
        float bank; /**< or roll \f$\phi\f$ = rotation about X axis */
    };
    union
    {
        float pitch; /**< or elevation \f$\theta\f$ = rotation about Y axis */
        float elevation; /**< or pitch \f$\theta\f$ = rotation about Y axis */
    };
    union
    {
        float yaw;     /**< or heading \f$\psi\f$ = rotation about Z axis */
        float heading; /**< or yaw \f$\psi\f$ = rotation about Z axis */
    };
} euler;

/** @} */

/** @addtogroup dual_quats 3D Dual-Quaternion operations
 * @{
 */
/** a dual quaternion type */
typedef struct dual_quat_
{
    quaternion real; /**< real part of dual quaternion */
    quaternion dual; /**< dual part of dual quaternion */
} dual_quat;

/** @} */

#endif  // __LIBQUAT_H_

/** @} */
