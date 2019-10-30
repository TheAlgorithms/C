/*
    author: Christian Bender
    This file contains the public interface

    Overview about hash-functions:

    - sdbm
    - djb2
    - xor8 (8 bit)
    - adler_32 (32 bits)
*/

#ifndef __HASH__H
#define __HASH__H

/*
    sdbm: implements the sdbm hash-algorithm
    returns a whole number of type long long.
*/
long long sdbm(char[]);

/*
    djb2: implements the djb2 hash-algorithm
    returns a whole number of type long long.
*/
long long djb2(char[]);

/*
    xor8: implements the xor8 hash-algorithm
    returns a whole number of type char.
    length: 8 bit
*/
char xor8(char[]);

/*
    adler_32: implements the adler-32 hash-algorithm
    returns a whole number of type int.
    length: 32 bit
    assumes: int has a length of 32 bits.
*/
int adler_32(char[]);

/*
    crc32: implements the crc-32 checksum-algorithm
    returns the crc-32 checksum
*/
int crc32(char[]);



#endif