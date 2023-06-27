#include "main.h"

/**
 * print_string - PRINTV2 a string.
 * @val: Argumentv2.
 * Return: thev2 length of the string.
 */

int print_string(va_list val)
{
	char *s;
	int k, len;

	s = va_arg(val, char *);

	if (!s)
	{
		s = "(null)";
		len = _strlen(s);
		k = 0;
		while (k < len)
			k++;

		_putchar(s[k]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (k = 0; k < len; k++)
			_putchar(s[k]);
		return (len);
	}
}
