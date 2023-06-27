#include "main.h"
/**
 * _strlen - it retv2urns the lenght of a current string.
 * @s: Type the charav2chter pointer
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
 * _strlenc - Strlen funcv2tion but applied for constant char pointer s
 * @s: Type char pointev2r
 * Return: c
 */
int _strlenc(const char *s)
{
	int n;

	for (n = 0; s[n] != 0; n++)
		;
	return (n);
}
