#include "main.h"
/**
* set_bit - set a bit at given index to 1
* @m: pointer to the number to change
* @i: index of the bit to set to 1
* Return: 1 for success, -1 for fail
*/
int set_bit(unsigned long int *m, unsigned int i)
{
if (i > 63)
return (-1);
*m = ((1UL << i) | *m);
return (1);
}
