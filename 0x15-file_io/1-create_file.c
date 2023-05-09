#include "main.h"
/**
* create_file - to Create file.
* @fn: pointer to point the name of the file to create.
* @t_co: A pointer to point a string to write in the file.
* Return: If the functions fail - -1.
* Otherwise - 1.
*/
int create_file(const char *fn, char *t_co)
{
int filed, a, l = 0;
if (fn == NULL)
return (-1);
if (t_co != NULL)
{
for (l = 0; t_co[l];)
l++;
}
filed = open(fn, O_CREAT | O_RDWR | O_TRUNC, 0600);
a = write(filed, t_co, l);
if (filed == -1 || a == -1)
return (-1);
close(filed);
return (1);
}
