#include "main.h"

/**
 * _putchar - writes the char c to stdout library
 * @c: The char to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and err is set right.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
