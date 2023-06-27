#include "main.h"
/**
 * _strlen - it returns the lenght of a current string.
 * @s: Type the charachter pointer
 * Return: c.
 */
int _strlen(char *s)
{
	int n;

	for (n = 0; s[n] != 0; n++)
		;
	return (n);
}

/**
 * _strlenc - Strlen function but applied for constant char pointer s
 * @s: Type char pointer
 * Return: c
 */
int _strlenc(const char *s)
{
	int n;

	for (n = 0; s[n] != 0; n++)
		;
	return (n);
}
