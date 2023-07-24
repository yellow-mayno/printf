#include "main.h"
#include <stdio.h>

int main(void)
{
	int n1, n2;

	n1 = printf("%s\n%c%%\n", "test", 'x');
	n2 = _printf("%s\n%c%%\n", "test", 'x');
	printf("%d %d\n", n1, n2);
	return (0);
}
