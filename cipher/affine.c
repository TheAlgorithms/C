/**
 * @file
 * @brief An [affine cipher](https://en.wikipedia.org/wiki/Affine_cipher) is a
 * letter substitution cipher that uses a linear transformation to substitute
 * letters in a message.
 * @details Given an alphabet of length M with characters with numeric values
 * 0-(M-1), an arbitrary character x can be transformed with the expression (ax
 * + b) % M into our ciphertext character. The only caveat is that a must be
 * relatively prime with M in order for this transformation to be invertible,
 * i.e., gcd(a, M) = 1.
 * @author [Daniel Murrow](https://github.com/dsmurrow)
 */

#include <assert.h>  /// for assertions
#include <stdio.h>   /// for IO
#include <stdlib.h>  /// for div function and div_t struct as well as malloc and free
#include <string.h>  /// for strlen, strcpy, and strcmp

/**
 * @brief number of characters in our alphabet (printable ASCII characters)
 */
#define ALPHABET_SIZE 95

/**
 * @brief a structure representing an affine cipher key
 */
typedef struct
{
    int a;  ///< what the character is being multiplied by
    int b;  ///< what is being added after the multiplication with a
} affine_key_t;

/**
 * @brief finds the value x such that (a * x) % m = 1
 *
 * @param a number we are finding the inverse for
 * @param m the modulus the inversion is based on
 *
 * @returns the modular multiplicative inverse of a mod m
 */
int modular_multiplicative_inverse(int a, int m)
{
    int x[2] = {1, 0};
    int previous_remainder;
    div_t div_result;

    assert(a > 0 && m > 0);
    a %= m;

    div_result.rem = a;

    while (div_result.rem > 0)
    {
        div_result = div(m, a);

        previous_remainder = a;

        m = a;
        a = div_result.rem;

        // Calculate value of x for this iteration
        int next = x[1] - (x[0] * div_result.quot);

        x[1] = x[0];
        x[0] = next;
    }

    assert(previous_remainder == 1);

    return x[1];
}

/**
 * @brief Given a valid affine cipher key, this function will produce the
 * inverse key.
 *
 * @param key They key to be inverted
 *
 * @returns inverse of key
 */
affine_key_t inverse_key(affine_key_t key)
{
    affine_key_t inverse;

    inverse.a = modular_multiplicative_inverse(key.a, ALPHABET_SIZE);

    // Turn negative results positive
    inverse.a += ALPHABET_SIZE;
    inverse.a %= ALPHABET_SIZE;

    inverse.b = -(key.b % ALPHABET_SIZE) + ALPHABET_SIZE;

    return inverse;
}

/**
 * Encrypts character string s with key
 *
 * @param s string to be encrypted
 * @param key affine key used for encryption
 *
 * @returns void
 */
void affine_encrypt(char *s, affine_key_t key)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        int c = (int)s[i] - ' ';

        c *= key.a;
        c += key.b;
        c %= ALPHABET_SIZE;

        s[i] = (char)(c + ' ');
    }
}

/**
 * @brief Decrypts an affine ciphertext
 *
 * @param s string to be decrypted
 * @param key Key used when s was encrypted
 *
 * @returns void
 */
void affine_decrypt(char *s, affine_key_t key)
{
    affine_key_t inverse = inverse_key(key);

    for (int i = 0; s[i] != '\0'; i++)
    {
        int c = (int)s[i] - ' ';

        c += inverse.b;
        c *= inverse.a;
        c %= ALPHABET_SIZE;

        s[i] = (char)(c + ' ');
    }
}

/**
 * @brief Tests a given string
 *
 * @param s string to be tested
 * @param a value of key.a
 * @param b value of key.b
 *
 * @returns void
 */
void test_string(char *s, int a, int b)
{
    char *copy = malloc((strlen(s) + 1) * sizeof(char));
    strcpy(copy, s);

    affine_key_t key = {a, b};

    affine_encrypt(copy, key);
    assert(strcmp(copy, s) != 0);  // assert that the encryption worked

    affine_decrypt(copy, key);
    assert(strcmp(copy, s) ==
           0);  // assert that we got the same string we started with

    free(copy);
}

/**
 * @brief Test multiple strings
 *
 * @returns void
 */
void tests()
{
    test_string("Hello!", 7, 11);
    test_string("TheAlgorithms/C", 67, 67);
    test_string("0123456789", 91, 88);
    test_string("7W@;cdeRT9uL", 77, 76);
    test_string("~Qr%^-+++$leM", 8, 90);
    test_string("The quick brown fox jumps over the lazy dog", 94, 0);
    test_string(
        "One-1, Two-2, Three-3, Four-4, Five-5, Six-6, Seven-7, Eight-8, "
        "Nine-9, Ten-10",
        51, 18);

    printf("all tests have successfully passed!\n");
}

/**
 * @brief main function
 *
 * @returns 0 upon successful program exit
 */
int main()
{
    tests();
    return 0;
}
