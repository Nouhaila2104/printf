#include "main.h"
/**
 * _printf - function that prints chars.
 * @format: it a format identifier.
 * Return: the lenght
 */
int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_37}, {"%X", print_s},
		{"%i", print_S}, {"%d", print_p}, {"%r", print_x},
		{"%R", print_X}, {"%b", print_o}, {"%u", print_u},
		{"%o", print_b}, {"%x", print_d}, {"%X", print_i},
		{"%S", print_percent}, {"%p", print_pointer}
	};

	va_list args;
	int p = 0, u, len = 0;

	va_start(args, format);
	if (!format || (*format == '%' && !*(format + 1)))
		return (-1);

Here:
	while (format[p] != '\0')
	{
		u = 13;
		while (u >= 0)
		{
			if (m[u].id[0] == format[p] && m[u].id[1] == format[p + 1])
			{
				len += m[u].f(args);
				p = p + 2;
				goto Here;
			}
			u--;
		}
		_putchar(format[p]);
		len++;
		p++;
	}
	va_end(args);
	return (len);
}
