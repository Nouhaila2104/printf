#include "main.h"

/**
 * print_pointer - PRINTSV2 an hexgecimal number.
 * @val: Argumentsv2.
 * Return: counterv2.
 */
int print_pointer(va_list val)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int z, y;

	p = va_arg(val, void*);
	if (!p)
	{
		for (y = 0; s[y] != '\0'; y++)
		{
			_putchar(s[y]);
		}
		return (y);
	}
	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	z = printf("0x%lx", a);
	return (z + 2);
}
