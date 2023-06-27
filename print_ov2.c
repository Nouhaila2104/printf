#include "main.h"
/**
 * print_o - PRINTSV2 a binary number.
 * @val: Argumentsv2.
 * Return: 1.
 */
int print_o(va_list val)
{
	int flag = 0, cont = 0, j, a = 1, b;
	unsigned int num = va_arg(val, unsigned int), p;

	j = 0;
	while (j < 32)
	{
		p = ((a << (31 - j)) & num);
		if (p >> (31 - j))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - j);
			_putchar(b + 48);
			cont++;
		}
		j++;
	}
	if (cont == 0)
	{
		_putchar('0');
		cont++;
	}
	return (cont);
}
