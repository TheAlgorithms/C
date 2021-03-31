/****************************************************************************************
 * printf statement rewritten (as minprinf)in c without using stdio.h library.
 * Using minprintf is similar to printf with most properties being same.
 * Currently minprintf handles:
 * 	Integers, Doubles, floats, characters, strings.
 * The format specifiers and escape sequence is same as for printf.
 * User can also specify the width and precision if requires just as in case of printf.
 * How to use it:
 * 	- First include minprintf.h in your code.
 * 	- Then type minprintf(), and pass required parameters to it.
 * 	- As already specified it is similar to prints so use it in the same way.
 ****************************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define INT_MAX_LENGTH 10
#define PRECISIONFORFLOAT 8

static char buffr;
int bufsize = 0;

int power(int a, int b)
{
	/*!
	 * Similar to pow() function in math.h library.
	 */
	for (int i = 1; i < b; ++i)
		a *= 10 ;
	return a;
}

int is_number(char *c)
{
	//! Checks if a character is a number.
	return (*c >= '0' && *c <= '9') ? 1 : 0;
}

char get_ch(char *p)
{
	/*!
	 * Checks if buffer has a character or not.
	 * If yes then that character is returned and 
	 * buffer size is set to 0.
	 * else the character at pointer p is returned
	 * and p is incremented.
	 */
	if (bufsize) {
		bufsize = 0;
		return buffr;
	}
	return *p++;
}

void unget_ch(char *c)
{
	//!< Stores the character to buffer.
	buffr = *c;	
	bufsize = 1;
}

int get_number_of_digits(int n)
{
	/*!
	 * Returns number of digits in a number like:
	 * 			get_number_of_digits(12543) will return 5
	 */
	int digits = 0;
	while (n > 0) {
		++digits;
		n /= 10;
	}
	return digits;
}

void put_char(char s)
{
	/*!
	 * Prints one character on screen using low revel I/O.
	 */
	char *buf = (char *) malloc(sizeof(char) + 1); /*! Used to store the character to be printed in an array;
												     * +1 for storing '\0'
													*/
	*buf = s;
	*(buf + 1) = '\0';
	write(1, buf, 1);
	free(buf);
}

void reverse_str(char *p)
{
	/*!
	 * Reverse a string using 2 pointer algorithm.
	 */
	char *l = p; /* Lower */
	char *h = p; /* Higher */
	char temp;

	while (*h != '\0') 
		++h;
	
	--h; /**< Point to last valid character of string. */ 

	// Swap character of string until lower is less than higher.
	// If lower => higher, then string is reversed.
	while (l < h) {
		temp = *l;
		*l = *h;
		*h = temp;
		++l;
		--h;
	}
}

void print_int_value(int n, int width, int precision)
{
	/*!
	 * The algorithm here is to first convert the number into 
	 * string and then reverse it be passing it to reverse_str function
	 * and then printing on the screen.
	*/
	char *p = (char *) malloc(INT_MAX_LENGTH * sizeof(char) + 1); /* +1 for '\0' */
	char *s = p;
	int size = 0; //!< Used to store number of digits in number.

	while (n > 0) {
		/*!
		 *
		*/
		*s++ = n % 10 + '0'; //!< Converts last digit of number to character and store it in p.
		++size; //!< Increment size variable as one more digit is occured.
		n /= 10; //!< Removes the last digit from the number n as we have successfully stored it in p.
	}
	*s = '\0';

	s = p;

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

	// Print the number.
	while (*s != '\0')
		put_char(*s++);

	free(p);
}

void print_double_value(double dval, int width, int precision)
{
	/*!
	 * The algorithm here is also same as print_int_value function.
	 * First the digits before decimal is printed by converting the double 
	 * to int. Then after printed a '.', the double number is subtracted with
	 * the integer value of the number, leaving us with 0 before decimal.
	 * Then we multiply the number with 10 raise to the power precision (
	 * precision means how many digits to be printed after decimal.)
	 * By default precision is 8 if it is not specified.
	 * Then the remaining number is printed on the screen.
	 */
	int ndigits = get_number_of_digits((int) dval);
	int reqd_blanks = width - (precision + 1) - ndigits;	
	
	print_int_value((int) dval, reqd_blanks, 0); /* Prints the part before decimal */

	put_char('.');

	dval = dval - (int) dval; //!< Deletes digits before decimal and make them zero.

	dval *= power(10, precision); //!< Brings the digits after decimal to before decimal.
	
	print_int_value((int) dval, 0, precision); 
}

void print_string(char *p, int width, int precision)
{
	/*!
	 * First size of string is calculated to check weather
	 * width and precision is to be taken into account or not.
	 * Then string is printed in accordingly.
	*/
	int size = 0;
	char *s = p;

	while (*s != '\0') { 
		++size;
		++s;
	}
	s = p;

	//!< Tells how many charactes of string is to be printed.
	if (precision != 0 && precision < size)
		size = precision;

	for (int i = 0; i < (width - size); ++i)
		put_char(' ');

	for (int i = 0; i < size; ++i) /* Prints the string*/
		put_char(*s++);

}

char *get_width_and_precision(char *p, int *width, int *precision)
{
	/*!
	 * For a specifier like %12.4s:
	 * width is 12 and precision is 4.
	 * Both of them are calculated here.
	 * Width is calculated by looping the string until a '.' or a non-number is not read.
	 * Precision is also calulated using loop until a non number is not read.
	 */
	if (*p == '%')
		++p;
	int n1 = 0, n2 = 0;
	
	//!< This while loop calculates the width specified.
	while (*p != '.' && is_number(p)) 
		n1 = n1 * 10 + (*p++ - '0');

	//!< A precision is always specified after a '.', so first a 
	// '.' is checked and then precision is read.
	if (*p == '.') {
		while (is_number(++p))
			n2 = n2 * 10 + (*p - '0');
		unget_ch(p); //!< The non number is stored in a buffer.
	}
	//!< Updating width and precision variables.
	*width = n1;
	*precision = n2;
	return p;
}


void minprintf(char *fmt, ...)
{
	va_list ap; /* Points to each unnamed arg in turn*/
	char *p, *sval;
	char cval;
	int ival; /* For integer values */
	double dval; /* For double or float values */
	va_start(ap, fmt); /* Makes ap points to first unnames argument */

	for (p = fmt; *p != '\0'; ++p) {
		if (*p != '%') {
			put_char(*p);
			continue;
		}
		
		int width = 0; 
		int precision = 0;

		p = get_width_and_precision(p, &width, &precision);
		
		switch (get_ch(p)) {
			case 'd':
				ival = va_arg(ap, int);
				print_int_value(ival, width, precision);
				break;
			case 'c':
				cval = va_arg(ap, int);
				put_char(cval);
				break;
			case 'f':
				dval = va_arg(ap, double);
				if (precision == 0)
					precision = PRECISIONFORFLOAT;
				print_double_value(dval, width, precision);
				break;
			case 's':
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
