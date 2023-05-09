#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buffer(char *f);
void cl_f(int filed);
/**
* create_buffer - Allocates 1024 bytes for a buffer.
* @f: The name of the file buffer is storing chars for.
* Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(char *f)
{
char *b;
b = malloc(sizeof(char) * 1024);
if (b == NULL)
{
dprintf(STDERR_FILENO,
"Error: Cannot write to the %s\n", f);
exit(99);
}
return (b);
}
/**
* cl_f - Closes file descriptors.
* @filed: The file descriptor to be closed.
*/
void cl_f(int filed)
{
int cl;
cl = close(filed);
if (cl == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot close filed %d\n", filed);
exit(100);
}
}
/**
* mainc - Copy the content of any file to another file.
* @argc: The number of arguments found to the program.
* @argv: An array of pointers pointed to the arguments.
* Return: 1 when success.
* Description:exit code If the argument count is incorrect - 97.
* Exit code if file_from is invalid or unable to be read - exit code 98.
* Exit code If file_to cannot be created or written to - exit code 99.
* Exit code If file_to or file_from cannot be closed - exit code 100.
*/
int mainc(int argc, char *argv[])
{
int fr, t, a, x;
char *y;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
y = create_buffer(argv[2]);
fr = open(argv[1], O_RDONLY);
a = read(fr, y, 1024);
t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (fr == -1 || a == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(y);
exit(98);
}
x = write(t, y, a);
if (t == -1 || x == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(y);
exit(99);
}
a = read(fr, y, 1024);
t = open(argv[2], O_WRONLY | O_APPEND);
} while (a > 0);
free(y);
cl_f(fr);
cl_f(t);
return (0);
}
