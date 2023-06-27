#include "main.h"

/************************* PRINT CHARACHTER *************************/

/**
 * print_char - Prints a charachter
 * @types: List some arguments
 * @buffer: Buffer array to handle the  print function
 * @flags:  Calculates the  active flags
 * @width: Width identifier
 * @precision: Precision specification identifier
 * @size: Size specifier for variables
 * Return: Number of chararachters printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char t = va_arg(types, int);

	return (handle_write_char(t, buffer, flags, width, precision, size));
}
/************************* PRINT  STRING *************************/
/**
 * print_string - Prints a string
 * @types: List the arguments
 * @buffer: Buffer the array to handle print function
 * @flags:  Calculates the current active flags 
 * @width: get width of the var.
 * @precision: Precision specification of the var
 * @size: Size specifier for the var
 * Return: Number of chars printed is returned
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, o;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (o = width - len; o > 0; o--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (o = width - len; o > 0; o--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints the percent sign like the original 
 * @types: List the arguments
 * @buffer: Buffer the array to handle the print function
 * @flags:  it Calculates the active flags
 * @width: get width of the var.
 * @precision: Precision specification of the var
 * @size: Size specifier of var
 * Return: Number of chars printed is returned
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print an integer
 * @types: List the arguments
 * @buffer: Buffer an array to handle print function
 * @flags:  Calculates the current active flags
 * @width: get the current width.
 * @precision: Precision specification of the var
 * @size: Size specifier of the size
 * Return: Number of chars printed is returned
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int isNegative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		isNegative = 1;
	}

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_number(isNegative, j, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int l, r, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	l = va_arg(types, unsigned int);
	r = 2147483648; /* (2 ^ 31) */
	a[0] = l / r;
	for (j = 1; j < 32; j++)
	{
		r /= 2;
		a[j] = (l / r) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
