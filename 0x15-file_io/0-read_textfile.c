#include "main.h"
#include <stdlib.h>
/**
* read_textfile- Read text file print for STDOUT.
* @fn:  file will being read
* @l: number of letters will be read
* Return: w- exact number of bytes read and printed
* 0 when functions fail or filename is NULL.
*/
ssize_t read_textfile(const char *fn, size_t l)
{
char *b;
ssize_t filed;
ssize_t a;
ssize_t x;
filed = open(fn, O_RDONLY);
if (filed == -1)
return (0);
b = malloc(sizeof(char) * l);
x = read(filed, b, l);
a = write(STDOUT_FILENO, b, x);
free(b);
close(filed);
return (a);
}
