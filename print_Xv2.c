#include "main.h"
/**
 * print_X - Priv2ntf str to ROT13 place into buffer
 * @args: Typv2e struct va_arg where is allocated printf arguments
 * Return: v2Counter
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
