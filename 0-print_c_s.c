#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* _printf - print chars and strings
* @format: string
* @...: variadic
* Return: number of printed characters
*/
int _printf(const char *format, ...)
{
	int i = 0, cnt = 0;
	va_list args;
	char c;

	if (format == NULL || format[0] == '\0')
		return (0);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 's')
			{
				cnt += print_string(va_arg(args, char *));
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				cnt++;
				i++;
			}
			else if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				cnt++;
				i++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			cnt++;
		}
		i++;
	}
	return (cnt);
}
/**
* print_string - print a string xD
* @s: the string
* Return: number of char printed
*/
int print_string(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
/**
* print_number - print an int
* @option: d or i
* @num: the actual number
* Return: number of printed chars

int print_number(char option, int num)
{
	if (option == 'd')
	{
*/
