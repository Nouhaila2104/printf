#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - it Prints an unsigned number
 * @types: List the arguments
 * @buffer: Buffer an array to handle the  print
 * @flags:  Calculates the current active flags
 * @width: it will get width
 * @precision:it is for Precision specification
 * @size: it is for  Size specifier
 * Return: Number of chars printed is returned.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER  OCTAL  ****************/
/**
 * print_octal - Prints the unsigned number in octal 
 * @types: List the  arguments
 * @buffer: Buffer the  array to handle the print
 * @flags:  Calculates the active flags
 * @width: get the width
 * @precision: it is for Precision  specification
 * @size: it is for Size specifier
 * Return: Number of chars printed is returned
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL FORMAT **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List the arguments
 * @buffer: Buffer an array to handle the print
 * @flags:  Calculates the current active flags
 * @width: get the current width
 * @precision: it is for Precision specification
 * @size: it is for Size specifier
 * Return: Number of chars printed is returned
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL FORMAT **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal 
 * @types: List the arguments
 * @buffer: Buffer an array to handle the print
 * @flags:  Calculates the current active flags
 * @width: get the current width
 * @precision: it is for Precision specification
 * @size: it is for Size specifier
 * Return: Number of chars printed is returned
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal notation number in lower or upper
 * @map_to: Array of values to map the number to the other
 * @types: List the arguments
 * @buffer: Buffer an array to handle the print
 * @flags:  Calculates the current active flags
 * @width: get the current width
 * @precision: it is for Precision specification
 * @size: it is for Size specifier
 * Return: Number of chars printed is returned
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
