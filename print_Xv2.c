#include "main.h"
/**
 * print_Xv2 - Printf str to ROT13 place into buffer
 * @args: Type struct va_arg where is allocated printf arguments
 * Return: Counter
 *
 */
int print_X(va_list args)
{
	int i, j, counter = 0, k = 0;
	char *s = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		k = 0;
		j = 0;
		while (alpha[j] && !k)
		{
			if (s[i] == alpha[j])
			{
				_putchar(beta[j]);
				counter++;
				k = 1;
			}
			j++;
		}
		if (!k)
		{
			_putchar(s[i]);
			counter++;
		}
	}
	return (counter);
}
