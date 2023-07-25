#include "main.h"
#include <unistd.h>
/**
* print_number - as the name says xDD
* @num: number to convert
* Return: string
*/
int print_number(int num)
{
	int i = 0, cnt = 0;
	int n = num;
	char c;

	if (n < 0)
	{
		c = '-';
		cnt += write(1, &c, 1);
	}
	while (num / 10)
	{
		i++;
		num = num / 10;
	}
	for (; i >= 0; i--)
	{
		if (n < 0)
			c = n / (int) power(10, i) * (-1) + 48;
		else
			c = n / (int) power(10, i) + 48;
		n = n % power(10, i);
		cnt += write(1, &c, 1);
	}
	return (cnt);
}
/**
* power - power xD
* @num: number
* @pow: prisoner of war
* Return: n
*/
unsigned int power(unsigned int num, int pow)
{
	int i = 0;
	unsigned int cml = 1;

	for (; i < pow; i++)
		cml = cml * num;
	return (cml);
}
/**
* print_number_binary - as the name says xDD
* @num: number to convert
* Return: string
*/
int print_number_binary(unsigned int num)
{
	int i = 0, cnt = 0;
	unsigned int n = num;
	char c;

	while (num / 2)
	{
		i++;
		num = num / 2;
	}
	num = i;
	for (; i >= 0; i--)
	{
		c = n / power(2, i) + 48;
		n = n % power(2, i);
		cnt += write(1, &c, 1);
	}
	return (num + 1);
}
