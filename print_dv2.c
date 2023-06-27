#include "main.h"
/**
 * print_d - PRINTSV2 an hexgecimal number.
 * @val: Arguments.
 * Return: counter.
 */
int print_d(va_list val)
{
	int i, *array, counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	i = 0;
	while (i < counter)
	{
		array[i] = temp % 16;
		temp /= 16;
		i++;
	}
	i = counter - 1;
	while (i >= 0)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
		i--;
	}
	free(array);
	return (counter);
}
