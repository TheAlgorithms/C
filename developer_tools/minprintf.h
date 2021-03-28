#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define INT_MAX_LENGTH 10
#define PRECISIONFORFLOAT 8

static char buffr;
int bufsize = 0;

int power(int a, int b)
{
	/* Will return a to the power b*/

	for (int i = 1; i < b; ++i)
		a *= 10 ;
	return a;
}

int is_number(char *c)
{
	return (*c >= '0' && *c <= '9') ? 1 : 0;
}

char get_ch(char *p)
{
	if (bufsize) {
		bufsize = 0;
		return buffr;
	}
	return *p++;
}

void unget_ch(char *c)
{
	buffr = *c;	
	bufsize = 1;
}

int get_number_of_digits(int n)
{
	int digits = 0;
	while (n > 0) {
		++digits;
		n /= 10;
	}
	return digits;
}

void put_char(char s)
{
	char *buf = (char *) malloc(sizeof(char) + 1);
	*buf = s;
	*(buf + 1) = '\0';
	write(1, buf, 1);
	free(buf);
}

void reverse_str(char *p)
{
	char *l = p; /* Lower */
	char *h = p; /* Higher */
	char temp;

	while (*h != '\0') 
		++h;
	
	--h; /* Point to last valid character of string */ 

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
	char *p = (char *) malloc(INT_MAX_LENGTH * sizeof(char) + 1); /* +1 for '\0' */
	char *s = p;
	int size = 0;
	while (n > 0) {
		*s++ = n % 10 + '0'; /* Converts last character of number to char and store it in p*/
		++size;
		n /= 10;
	}
	*s = '\0';
	s = p;

	reverse_str(p);

	if (width > 0 && size < width)
		for (int i = 0; i < (width - precision); ++i) 
			put_char(' ');

	if (precision > 0 && precision > size)
		for (int i = 0; i < (precision - size); ++i)
			put_char('0');

	while (*s != '\0')
		put_char(*s++);

	free(p);
}

void print_double_value(double dval, int width, int precision)
{
	int ndigits = get_number_of_digits((int) dval);
	int reqd_blanks = width - (precision + 1) - ndigits;	
	
	print_int_value((int) dval, reqd_blanks, 0); /* Prints the part before decimal */

	put_char('.');

	dval = dval - (int) dval; 

	dval *= power(10, precision);
	
	print_int_value((int) dval, 0, precision); /* Prints characters after decimal*/
}

void print_string(char *p, int width, int precision)
{
	int size = 0;
	char *s = p;

	while (*s != '\0') { /* Calculate size of string */
		++size;
		++s;
	}
	s = p;

	if (precision != 0 && precision < size)
		size = precision;

	for (int i = 0; i < (width - size); ++i) /* Prints blank for the width */
		put_char(' ');

	for (int i = 0; i < size; ++i) /* Prints the string*/
		put_char(*s++);

}

char *get_width_and_precision(char *p, int *bd, int *ad)
{
	if (*p == '%')
		++p;
	int n1 = 0, n2 = 0;
	while (*p != '.' && is_number(p)) 
		n1 = n1 * 10 + (*p++ - '0');

	if (*p == '.') {
		while (is_number(++p))
			n2 = n2 * 10 + (*p - '0');
		unget_ch(p);
	}
	*bd = n1;
	*ad = n2;
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
		
		int width = 0; /* Before dot i.e.-> %52.4s, width = 52*/
		int precision = 0; /* After dot*/

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
