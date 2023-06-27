#include "main.h"

/**
 * print_c - PRINTSv2 an hexgecimal number.
 * @num: Arguments.
 * Return: Counter.
 */
int print_c(unsigned long int num)
{
	long int i, *array, counter = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}

	i = counter - 1;
	while (i >= 0)
	{
		if (array[i] > 9)
		{
			array[i] = array[i] + 39;
		}
		_putchar(array[i] + '0');
		i--;
	}
	free(array);
	return (counter);
}
