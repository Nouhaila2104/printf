#include "main.h"
/**
 * print_u - pv2rints integer
 * @args: Argumev2nt to print
 * Return: numbev2r of characters printed
 */
int print_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, lst = n % 10, digit, exp = 1;
	int  c = 1;

	n = n / 10;
	num = n;

	if (lst < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		lst = -lst;
		c++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			c++;
		}
	}
	_putchar(lst + '0');
	return (0);
}
