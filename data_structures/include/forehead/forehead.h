#ifndef fore_head_h
#define fore_head_h

/**
 * @file
 * @brief This header must be included in every sub-header file.
 * @details
 * 1. forehead.h included the necessary header files which needed by every
 * sub-header file.
 * 2. forehead.h defined some macros for debugging.
 * @note These macro functions will be heavily used in the code (in situations
 * such as exception handling, test cases, and termination functions)!
 * @author [Daniel Hu](https://github.com/danielhu19)
 */

#include <assert.h>   /// for assert
#include <limits.h>   /// for LIMIT of data types
#include <stdbool.h>  /// for bool
#include <stdio.h>    /// for IO operations
#include <stdlib.h>   /// for memory allocation and free
#include <string.h>   /// for string operations
#include <time.h>     /// for date and time functions
#include <unistd.h>   /// for POSIX API

/* @deprecated: use Macro functions below to debug */
// #define STATUS int
// #define SUCCESS 1
// #define ERROR 0
// #define INFEASIBLE -1
// #define OVERFLOW -2

/* The following three macros are originated from NJU-ICS:2020 for debugging. */

/**
 * @def Helper macro for LOG().
 */
#define _LOG(...)            \
    do                       \
    {                        \
        printf(__VA_ARGS__); \
    } while (0);

/**
 * @def Helper macro __FILE__: [__FILE__ macro shows full
 * path](https://stackoverflow.com/questions/8487986/file-macro-shows-full-path).
 */
#define __FILENAME__ \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/**
 * @def Log() is an enhanced version of printf(), specifically designed for
 * outputting debugging information in
 * [color-text-in-terminal](https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix)
 * , while also including the source file, line number, and function where the
 * Log() is used.
 * @param format The format string with color.
 *
 */
#define LOG(format, ...)                                                   \
    _LOG("\33[1;34m[%s,%d,%s] " format "\33[0m\n", __FILENAME__, __LINE__, \
         __func__, ##__VA_ARGS__)

/**
 * @def Assert() is an upgraded version of assert() that allows for outputting
 * additional information before the assertion failure when the test condition
 * is false.
 * @param cond The test condition.
 * @param ... The additional information to be output when the test condition is
 * false.
 */
#define Assert(cond, ...)                 \
    do                                    \
    {                                     \
        if (!(cond))                      \
        {                                 \
            fflush(stdout);               \
            fprintf(stderr, "\33[1;31m"); \
            fprintf(stderr, __VA_ARGS__); \
            fprintf(stderr, "\33[0m\n");  \
            assert(cond);                 \
        }                                 \
    } while (0)

/**
 * @def The panic() function is used to output information and terminate the
 * program, effectively functioning as an unconditional assertion failure.
 * @param ... The additional information to be output when the test condition is
 * false.
 */
#define panic(...) Assert(0, __VA_ARGS__)

/**
 * @def Output the details of tests if it is set to 1. Default is 0.
 */
#define DEBUG 0

#endif
