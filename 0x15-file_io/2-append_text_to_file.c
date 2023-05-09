#include "main.h"
/**
* append_text_to_file - Append text to the end of the file.
* @fn: A pointer to point the name of the file.
* @t_co: string to add to the end of the file.
* Return: If the functions fail or filename is NULL - -1.
* If the file does not exist the user will write permission -1.
* Otherwise - 1.
*/
int append_text_to_file(const char *fn, char *t_co)
{
int x, a, l = 0;
if (fn == NULL)
return (-1);
if (t_co != NULL)
{
for (l = 0; t_co[l];)
l++;
}
x = open(fn, O_WRONLY | O_APPEND);
a = write(x, t_co, l);
if (x == -1 || a == -1)
return (-1);
close(x);
return (1);
}
