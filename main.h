#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
    struct format - match the conversion specifiers for the printf function
    @id: type the charachter pointer of the current specifier i.e (l, h) for (d, i, u, o, x, X)
    @f: type the pointer to function for the conversion specifier
*/

typedef struct format
{
char *id;
int (*f)();
} convert_match;

/* function prototypes */

int print_i(va_list val);
int print_d(va_list val);
int print_b(va_list val);
int print_u(va_list args);
int print_o(va_list val);
int print_x(va_list args);
int print_X(va_list args);
int print_S(va_list args);
int print_p(va_list args);
int _strlenc(const char *s);
int print_string(va_list val);
int print_char(va_list val);
int rev_string(char *s);
int print_pointer(va_list val);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _putchar(char c);
int print_37(void);
int _printf(const char *format, ...);
int print_c(unsigned long int num);
int print_s(unsigned int num);
int print_percent(va_list val);
#endif /* MAIN_H */
