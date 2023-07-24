#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
/**
* _printf - print charcters and strings and integers
* @format: string of char that may contain %c or %s
* @...: variadic args
* Return: number of printed chars
*/
int _printf(const char *format, ...)
{
	char *to_print, *argu;
	int i = 0;
	int len;
	va_list args;

	to_print = "\0";
	va_start(args, format);
	to_print = _strcpy(to_print, format);
	len = _strlen(to_print);
	for (; i < len ; i++)
	{
		if (to_print[i] == '%')
		{
			if (to_print[i + 1] == 's')
			{
				argu  = va_arg(args, char *);
				to_print = insert(to_print, argu, i);
				i += _strlen(argu);
				len = _strlen(to_print);
			}
			else if (to_print[i + 1] == 'c')
			{
				argu = char_to_string(argu, va_arg(args, int));
				to_print = insert(to_print, argu, i);
				i += _strlen(argu);
				len = _strlen(to_print);
			}
			else
				return (0);
		}
	}
	va_end(args);
	len = _strlen(to_print);
	write(1, to_print, len);
	return (len);
}
/**
* _strlen - count number of chars
* @s: the string to count
* Return: int
*/
unsigned int _strlen(const char *s)
{
	unsigned int cnt = 0;

	for (; s[cnt] != '\0'; cnt++)
		;
	return (cnt);
}
/**
* _strcpy - copy string intro another
* @dest: destination
* @src: source
* Return: pointer to dest (important due to malloc that can change pointer)
*/
char *_strcpy(char *dest, const char *src)
{
	int len, i = 0;

	len = _strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	for (; i <= len; i++)
		dest[i] = src[i];
	return (dest);
}
/**
* insert - insert 'to_insert" inside dest in position n and skipin n, n+1 (%d)
* @dest: destination
* @to_insert: string to insert
* @n: position of insertion
* Return: pointer to destination
*/
char *insert(char *dest, char *to_insert, int n)
{
	unsigned int i, j = 0;
	char *temp_string;
	int len;

	len = _strlen(dest) + _strlen(to_insert);
	temp_string = malloc(len * sizeof(char));
	temp_string = _strcpy(temp_string, dest);
	for (i = 0; i < _strlen(to_insert); i++)
		temp_string[i + n] = to_insert[i];
	while (dest[n + 2 + j] != '\0')
	{
		temp_string[i + n + j] = dest[n + 2 + j];
		j++;
	}
	return (temp_string);
}
/**
* char_to_string - returns string containing the char
* @s: ptr where to store the string
* @c: character
* Return: a string
*/
char *char_to_string(char *s, char c)
{
	s = malloc(2 * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	s[0] = c;
	s[1] = '\0';
	return (s);
}
