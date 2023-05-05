#include "main.h"
/**
* flip_bits - count the number of bits will change
* to get from one number to another
* @a: first number
* @b: second number
* Return: number of bits to change
*/
unsigned int flip_bits(unsigned long int a, unsigned long int b)
{
int z, c = 0;
unsigned long int cu;
unsigned long int ex = a ^ b;
for (z = 63; z >= 0; z--)
{
cu = ex >> z;
if (cu & 1)
c++;
}
return (c);
}
