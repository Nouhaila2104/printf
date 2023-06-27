#include "main.h"

/**
 * print_s - prv2ints an hexgecimal number.
 * @num: Number tv2o print.
 * Return: countev2r.
 */
int print_s(unsigned int num)
{
	int p, *array, counter = 0;
	unsigned int temp = num;

	for (counter = 1; num / 16 != 0; counter++)
	{
		num /= 16;
	}
	counter++;

	array = malloc(counter * sizeof(int));
	p = 0;
	while (p < counter)
	{
		array[p] = temp % 16;
		temp /= 16;
		p++;
	}
	p = counter - 1;
	while (p >= 0)
	{
		if (array[p] > 9)
			array[p] = array[p] + 7;
		_putchar(array[p] + '0');
		p--;
	}
	free(array);
	return (counter);
}
