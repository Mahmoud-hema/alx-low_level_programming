#include "main.h"
/**
* binary_to_unit - converts a binary number to unsigned int
* @b: string containing the binary number
* Return: the converted number
*/
unsigned int binary_to_unit(const char *b)
{
int x;
unsigned int decimalvalue = 0;
if (!b)
return (0);
for (x = 0; b[x]; x++)
{
if (b[x] < '0' || b[x] > '1')
return (0);
decimalvalue = 2 * decimalvalue + (b[x] - '0');
}
return (decimalvalue);
}
