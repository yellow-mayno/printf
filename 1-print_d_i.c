#include "main.h"
#include <unistd.h>
/**
* print_number - as the name says xDD
* @num: number to convert
* Return: string
*/
int print_number(int num)
{
	int power(int, int);
	int i = 0;
	int n = num;
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
	}
	while (num / 10)
	{
		i++;
		num = num / 10;
	}
	num = i;
	for (; i >= 0; i--)
	{
		if (n < 0)
			c = n / power(10, i) * (-1) + 48;
		else
			c = n / power(10, i) + 48;
		n = n % power(10, i);
		write(1, &c, 1);
	}
	return (num + 1);
}
/**
* power - power xD
* @num: number
* @pow: prisoner of war
* Return: n
*/
int power(int num, int pow)
{
	int i = 0;
	int cml = 1;

	for (; i < pow; i++)
		cml = cml * num;
	return (cml);
}
