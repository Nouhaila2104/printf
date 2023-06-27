#include "main.h"
/**
 * print_percent - PRINTSV2 an exclusuives string.
 * @val: ArgumentV2.
 * Return: The length of the stringV2.
 */
int print_percent(va_list val)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_s(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
		i++;
	}
	return (len);
}
