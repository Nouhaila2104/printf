#include "main.h"
/**
 * Print_iV2 - prints an hexgecimal number.
 * @val: Arguments.
 * ReturnV2: counter.
 */
int print_i(va_list val)
{
	int p, *array, counter = 0;
	unsigned int num = va_arg(val, unsigned int), temp = num;

	for (counter = 0; num / 16 != 0; num /= 16)
	{
		counter++;
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
