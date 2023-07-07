#include "main.h"
/**
* flip_bits - counts the number of bits to change
* to get from one number to another
* @n: first number
* @m: second number
* Return: number of bits to change
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int x, c = 0;
unsigned long int cu;
unsigned long int ex = n ^ m;
for (x = 63; x >= 0; x--)
{
cu = ex >> x;
if (cu & 1)
c++;
}
return (c);
}
