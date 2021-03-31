/**
 * @file minprintf.h
 * @brief Implementation of a function similar to printf.
 * @details
 * printf statement rewritten (as minprinf) in c without using stdio.h library.
 * Syntax of minprintf is same as printf.
 * Currently minprintf handles:
 * 	Integers, Doubles, floats, characters, strings.
 * The format specifiers and escape sequence is same as for printf.
 * User can also specify the width and precision if requires just like in the case of printf.
 * How to use it:
 * 	- First include minprintf.h in your code.
 * 	- Then type minprintf(), and pass required parameters to it.
 * 	- As already specified it is similar to prints so use it in the same way.
 * @author [Jaskarn Singh] (https://github.com/Jaskarn7)
*/

#include <stdlib.h> // For malloc and free functions.
#include <unistd.h> // For write function.
#include <stdarg.h> // For va_start and va_arg functions.

/**
 * INT_MAX_LENGTH is used as standard length of string to store integers.
 * PRECISION_FOR_FLOAT is default precision for float or double if not specified.
*/
#define INT_MAX_LENGTH 10
#define PRECISION_FOR_FLOAT 8


/**
 * buffr used to store character in certain situations.
 * bufsize is 0, if buffr is empty else 1.
*/
static char buffr;
int bufsize = 0;

/**
 * @param a The power of ten which is to be returned.
 * @return Ten to the power a. 
 */
int power_of_ten(int a)
{
	int n = 1; ///< This number will be returned as ten to power of a.
	for (int i = 1; i <= a; ++i)
		n *= 10 ;
	return n;
}

/**
 * Checks if a character is a number.
 * @param c number to be checked.
 * @return 'true'(1) if character is a number else 'false'(0)
*/
int is_number(char *c)
{
	return (*c >= '0' && *c <= '9') ? 1 : 0;
}

/**
 * Returns specific required next character.
 * @param p pointer to format string of minprintf().
 * @return character inside buffr, if bufsize is one.
 * @return character at which p is pointing, if bufsize is zero.
 */
char get_ch(char *p)
{
	if (bufsize) {
		bufsize = 0; // Since character is used, this sets bufsize to zero.
		return buffr;
	}
	return *p++;
}

/**
 * Stores character to buffr.
 * @param c Character to be stored in buffr. 
*/
void unget_ch(char *c)
{
	buffr = *c;	
	bufsize = 1; // Sets bufsize to one as new character is stored in buffr.
}


/**
 * Calculates number of digits in a number.
 * @param n number whose digits is to be counted.
 * @return number of digits in n.
*/
int get_number_of_digits(int n)
{
	int digits = 0; // Stores encountered number of digits.
	while (n > 0) {
		++digits; // Since number still contains a digit, so increment digit variable.
		n /= 10; // Removes last digit from number.
	}
	return digits;
}

/**
 * Prints one character on screen.
 * @param s character to be printed on screen.
*/
void put_char(char s)
{
	/* buf used for storing character to be printed in an array. (+1 for '\0')*/
	char *buf = (char *) malloc(sizeof(char) + 1); 
	*buf = s;
	*(buf + 1) = '\0';
	write(1, buf, 1);
	free(buf);
}

/**
 * Reverses a string using two pointer algorithm.
 * @param p pointer to string to be reversed.
*/
void reverse_str(char *p)
{
	char *l = p; // Points to first character of p.
	char *h = p; // Will be used to point to last character of p.
	char temp; // Temporarily stores a character, Used in swapping.

	while (*h != '\0') 
		++h;
	--h; // Now h point to last valid character of string. 

	/* Swap character which lower and higher are pointing until lower < higher. At that point string will be reversed.*/
	while (l < h) {
		temp = *l;
		*l = *h;
		*h = temp;
		++l; // Increment lower to next character.
		--h; // Decrement higher to previous character from current character.
	}
}

/**
 * The algorithm here is to first convert the number into 
 * string and then reverse it be passing it to reverse_str function
 * and then printing on the screen.
 * @param n Number to be printed.
 * @param width Total characters to be printed (Prints ' ' if (size < width).
 * @param precision Total character of number to be printed (prints 0 before number if size of number < precision).
 * 
*/
void print_int_value(int n, int width, int precision)
{
	char *p = (char *) malloc(INT_MAX_LENGTH * sizeof(char) + 1); /* +1 for '\0' */
	char *s = p; // Temporary pointer.
	int size = 0; //!< Used to store number of digits in number.

	while (n > 0) {
		*s++ = n % 10 + '0'; // Converts last digit of number to character and store it in p.
		++size; // Increment size variable as one more digit is occured.
		n /= 10; // Removes the last digit from the number n as we have successfully stored it in p.
	}
	*s = '\0';

	s = p; // Again point back s to starting of p.

	reverse_str(p);

	/*!
	 * The next two conditions check weather it is required to 
	 * add blanks before printing the number (ie: width)and is it specified how many
	 * zeros to be printed before the number is printed (ie: precision).
	*/
	if (width > 0 && size < width)
		for (int i = 0; i < (width - precision); ++i) 
			put_char(' ');

	if (precision > 0 && precision > size)
		for (int i = 0; i < (precision - size); ++i)
			put_char('0');

	/* Prints the number.*/
	while (*s != '\0')
		put_char(*s++);

	free(p);
}

/**
 * The algorithm here is also same as print_int_value function.
 * First the digits before decimal is printed by converting the double 
 * to int. Then after printed a '.', the double number is subtracted with
 * the integer value of the number, leaving us with 0 before decimal.
 * Then we multiply the number with 10 raise to the power precision (
 * precision means how many digits to be printed after decimal.)
 * By default precision is 8 if it is not specified.
 * Then the remaining number is printed on the screen.
 * @param dval double number to be printed.
 * @param width Similar to width parameter of print_int_value().
 * @param precision Tells number of digits to be printed after decimal (By default it is 8). 
 */
void print_double_value(double dval, int width, int precision)
{
	int ndigits = get_number_of_digits((int) dval); // Store number of digits before decimal in dval.
	int reqd_blanks = width - (precision + 1) - ndigits; // Blanks to be printed before printing dval, just to cover the width.
	
	print_int_value((int) dval, reqd_blanks, 0); // Prints the part before decimal.

	put_char('.'); // Print decimal.

	/*Deletes digits before decimal and makes them zero. For example:
		if dval = 1923.79022, them this will make dval = 0.79022.
	*/
	dval = dval - (int) dval;

	dval *= power_of_ten(precision); // Brings precision number of digits after decimal to before decimal.
	
	print_int_value((int) dval, 0, precision); // Prints the remaining number.
}

/**
 * First size of string is calculated to check weather
 * width and precision is to be taken into account or not.
 * Then string is printed in accordingly.
 * @param p pointer to string to be printed.
 * @param width if (width > sizeof string) then blanks will be printed before sting to cover up width.
 * @param precision Total charanters of string to be printed (Prints whole string if 0 or greater than size of string).
*/
void print_string(char *p, int width, int precision)
{
	int size = 0; // Stores number of character in string.
	char *s = p; // Temporary pointer.

	/* Calculates size of string p*/
	while (*s != '\0') { 
		++size;
		++s;
	}

	s = p; // Point s to starting of p.

	/* Checks how many characters to be printed.
		if precision is defined then size variable is changed to precision so that only precision
		number of characters were printed.
	*/
	if (precision != 0 && precision < size)
		size = precision;

	/* Prints blanks to cover the width if required.*/
	for (int i = 0; i < (width - size); ++i)
		put_char(' ');

	/* Print the string.*/
	for (int i = 0; i < size; ++i)
		put_char(*s++);

}

/**
 * Takes width and precision specified from format of string.
 * @param p pointer of format string.
 * @param width variable in which width will be stored.
 * @param precision variable in which precision will be stored.
 * @return character pointer to the current pointer of string p. (Used to update vaue of p)
*/
char *get_width_and_precision(char *p, int *width, int *precision)
{
	/* Skip % if p is pointing to it.*/
	if (*p == '%')
		++p;
	
	/* Calculates the width specified. */
	while (*p != '.' && is_number(p)) 
		*width = *width * 10 + (*p++ - '0');

	/* Calculates the precision specified.*/
	if (*p == '.' /* Since a precision is always specified after a '.'. */) { 
		while (is_number(++p))
			*precision = *precision * 10 + (*p - '0'); 
		unget_ch(p); // The non number is stored in a buffer.
	}
	return p;
}

/**
 * minprintf is the main function.
 * @param fmt format of string
 * @param ... arguments.
*/
void minprintf(char *fmt, ...)
{
	va_list ap; // Points to each unnamed arg in turn.
	char *p, *sval; // p will be used to point to fmt and sval will store string value.
	char cval; // Stores character value.
	int ival; // For integer values.
	double dval; // For double or float values.
	va_start(ap, fmt); // Makes ap points to first unnames argument.

	for (p = fmt; *p != '\0'; ++p) {
		
		/* If p != '%' then the character is printed to screen. */
		if (*p != '%') {
			put_char(*p);
			continue;
		}
		
		int width = 0; // Stores width specified.
		int precision = 0; // Stores precision specified.

		/* Updates values of width, precision and p. */
		p = get_width_and_precision(p, &width, &precision); 
		
		/* Checks format of next argument.*/
		switch (get_ch(p)) {
			case 'd': // Integer.
				ival = va_arg(ap, int);
				print_int_value(ival, width, precision);
				break;
			case 'c': // Character.
				cval = va_arg(ap, int);
				put_char(cval);
				break;
			case 'f': // Float or Double.
				dval = va_arg(ap, double);

				// If precision is not specified then default value is applied.
				if (precision == 0)
					precision = PRECISION_FOR_FLOAT;
				print_double_value(dval, width, precision);
				break;
			case 's': // String pointer.
				sval = va_arg(ap, char *);
				print_string(sval, width, precision);
				break;
			default:
				put_char(*p);
				break;
		}
	}
	va_end(ap);
}
