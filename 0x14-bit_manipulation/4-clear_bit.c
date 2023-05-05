#include "main.h"
/**
* clear_bit - set the value of given bit to 0
* @m: pointer to the number to change
* @i: index of the bit to clear
* Return: 1 for success, -1 for fail
*/
int clear_bit(unsigned long int *m, unsigned int i)
{
if (i > 63)
return (-1);
*m = (~(1UL << i) & *m);
return (1);
}
