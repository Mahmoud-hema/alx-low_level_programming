#include "main.h"
/**
* print_binary - prints the binary equivalent of a decimal number
* @n: number to print in binary
*/
void print_binary(unsigned long int n)
{
int a, c = 0;
unsigned long int current;
for (a = 63; a >= 0; a--)
{
current = n >> a;
if (current & 1)
{
_putchar('1');
c++;
}
else if (c)
_putchar('0');
}
if (!c)
_putchar('0');
}
