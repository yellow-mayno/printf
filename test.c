#include "main.h"
#include <stdio.h>

int main(void)
{
	int i = _printf("123%s78%c", "456", '9');
	_printf("%s","\n");
	_printf("none\n%s", "");
	printf("%d\n", i);
	return (0);
}
