#include "main.h"

/**
 * print_b - PRINTS an octal number.
 * @val: ARGuments.
 * Return: COUNter.
 */
int print_b(va_list val)
{
	int i, *array, counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	for (counter = 0; num / 8 != 0; counter++)
	{
		num /= 8;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	i = 0;
	while (i < counter)
	{
		array[i] = temp % 8;
		temp /= 8;
		i++;
	}
	i = counter - 1;
	while (i >= 0)
	{
		_putchar(array[i] + '0');
		i--;
	}
	free(array);
	return (counter);
}
