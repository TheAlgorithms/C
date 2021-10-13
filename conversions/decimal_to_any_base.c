/**
 * @file
 * @author [jucollet972](https://github.com/jucollet972)
 * @brief [Decimal to any-base](http://codeofthedamned.com/index.php/number-base-conversion) is a C function wich convert positive decimal
 * integer to any positive ascii base with the base's alphabet given in input and return it in a dynamically allocated string(recursive way)
 */

#include <stdio.h>   /// for IO operations
#include <string.h>  /// for strchr and strlen
#include <stdint.h>  /// for CPU arch's optimized int types
#include <stdbool.h> /// for boolean types
#include <assert.h>  /// for assert
#include <stdlib.h>  /// for malloc and free

/**
 * @brief Checking if alphabet is valid
 * @param base alphabet inputed by user
 * @return int64_t as success or not
 */
bool isbad_alphabet(const char* alphabet) {
	uint64_t len = strlen(alphabet);
	
	/* Checking th lenght */	
	if (len < 2) {
		return true;
	}
	/* Browse the alphabet */
	for (int i = 0; i < len ; i++) {
		/* Searching for duplicates */ 
		if (strchr(alphabet + i + 1, alphabet[i]))
			return true;
	}
	return false;
}

/**
 * @brief Calculate the final length of the converted number
 * @param nb to convert
 * @param base calculated from alphabet
 * @return Converted nb string length 
 */
uint64_t converted_len(uint64_t nb, short base) {
	/* Counting the number of characters translated to the base*/
	if (nb > base - 1) {
		return (converted_len(nb/base, base) + 1);
	}
	return 1;
}

/**
 * @brief Convert positive decimal integer into anybase recursively
 * @param nb to convert
 * @param alphabet inputed by user used for base convertion
 * @param base calculated from alphabet
 * @param converted string filled with the convertion's result
 * @return void
 */
void convertion(uint64_t nb, const char* alphabet, short base, char* converted) {
	/* Recursive convertion */
	*(converted) = *(alphabet + nb%base);
	if (nb > base - 1) {
		convertion(nb/base, alphabet, base, --converted);
	}
}

/**
 * @brief decimal_to_anybase ensure the validity of the parameters and convert any unsigned integers into any ascii positive base
 * @param nb to convert
 * @param base's alphabet
 * @returns nb converted on success
 * @returns NULL on error
 */
char* decimal_to_anybase(uint64_t nb, const char* alphabet) {
	char* converted;

	/* Verify that alphabet is valid */
	if (isbad_alphabet(alphabet)) {
		return NULL;
	}
	/* Convertion */
	uint64_t base = strlen(alphabet);
	uint64_t final_len = converted_len(nb, base);
	converted = malloc(sizeof(char) * (final_len + 1));
	converted[final_len] = 0;
	convertion(nb, alphabet, base, converted + final_len - 1);
	return converted;
}


/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
	char* ret = NULL;
	char* reference = NULL;

	/* min dec*/
	reference = "0";
	ret = decimal_to_anybase(0, "0123456789");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	/* max dec*/
	reference = "18446744073709551615";
	ret = decimal_to_anybase(18446744073709551615, "0123456789");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	/* negative dec*/
	reference = "18446744073709551615";
	ret = decimal_to_anybase(-1, "0123456789");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}

	/* bin */
	reference = "101010";
	ret = decimal_to_anybase(42, "01");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	/* octal */
	reference = "52";
	ret = decimal_to_anybase(42, "01234567");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	
	/* hexa */
	reference = "2A";
	ret = decimal_to_anybase(42, "0123456789ABCDEF");
	for (int i = 0; i < strlen(reference) && i < strlen(ret); i++) {
		assert(ret[i] == reference[i]);
	}
	if (ret != NULL) {
		free(ret);
	}
	printf("[+] All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit 
 */
int main()
{
	test(); // run self-test implementations
	return 0;
}
