#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
* main - Determines if a number is positive, negative or zero.
*
* Return: Always 0 (Success)
*/
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
if (n > 0)
{
printf(n,"%d is positive\n");
}
else if (n == 0)
{
printf(n,"%d is zero\n");
}
else
{
printf(n,"%d is negative\n");
}
return (0);
}
