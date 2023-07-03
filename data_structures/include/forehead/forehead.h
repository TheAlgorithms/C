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
 * @author danielhu19 (https://github.com/danielhu19)
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* @deprecated: use Macro functions below to debug */
// #define STATUS int
// #define SUCCESS 1
// #define ERROR 0
// #define INFEASIBLE -1
// #define OVERFLOW -2

/* The following three macros are originated from NJU-ICS:2020 for debugging. */
// https://stackoverflow.com/questions/26053959/what-does-va-args-in-a-macro-mean
#define _LOG(...)            \
    do                       \
    {                        \
        printf(__VA_ARGS__); \
    } while (0);

// https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
/**
 * Log() is an enhanced version of printf(), specifically designed for
 * outputting debugging information, while also including the source file, line
 * number, and function where the Log() is used. This is particularly useful for
 * identifying the relevant location in the code when there is a large amount of
 * debug information being output.
 */
#define LOG(format, ...)                                                    \
    _LOG("\33[1;34m[%s,%d,%s] " format "\33[0m\n", __FILE_NAME__, __LINE__, \
         __func__, ##__VA_ARGS__)

/**
 * Assert() is an upgraded version of assert() that allows for outputting
 * additional information before the assertion failure when the test condition
 * is false.
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
 * The panic() function is used to output information and terminate the program,
 * effectively functioning as an unconditional assertion failure.
 */
#define panic(...) Assert(0, __VA_ARGS__)

#endif
