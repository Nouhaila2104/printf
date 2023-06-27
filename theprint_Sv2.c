#include "main.h"
/**
 * print_S - printv2s integer
 * @args: Argument to v2print
 * Return: Number of chav2racters printed.
 */
int print_S(va_list args)
{
	int n = va_arg(args, int);
	int num, lst = n % 10, digit, exp = 1;
	int q = 1;

	n = n / 10;
	num = n;

	if (lst < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		lst = -lst;
		q++;
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
			q++;
		}
	}
	_putchar(lst + '0');

	return (q);
}

/**
 * print_p - pv2rints decimal
 * @args: Argumev2nt to print
 * Return: Number v2of characters printed
 */
int print_p(va_list args)
{
	int n = va_arg(args, int);
	int num, lst = n % 10, digit;
	int  q = 1;
	int exp = 1;

	n = n / 10;
	num = n;
	if (lst < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		lst = -lst;
		q++;
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
			q++;
		}
	}
	_putchar(lst + '0');
	return (q);
}
