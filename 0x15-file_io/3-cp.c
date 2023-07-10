#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024
#define USAGE "Usage: cp file_from file_to\n"
#define READ_ERROR "Error: Can't read from file %s\n"
#define WRITE_ERROR "Error: Can't write to %s\n"
#define CLOSE_ERROR "Error: Can't close fd %d\n"
/**
* main - Entry point
* @argc: Number of arguments
* @argv: Arguments
*
* Return: 0 on success, exit with code on failure
*/
int main(int argc, char **argv)
{
int from_fd, to_fd, read_count, write_count;
char buffer[BUFFER_SIZE];
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
if (argc != 3)
{
dprintf(STDERR_FILENO, USAGE); exit(97);
}
from_fd = open(argv[1], O_RDONLY);
if (from_fd == -1)
{
dprintf(STDERR_FILENO, READ_ERROR, argv[1]); exit(98);
}
to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (to_fd == -1)
{
dprintf(STDERR_FILENO, WRITE_ERROR, argv[2]); close(from_fd);
exit(99);
}
while ((read_count = read(from_fd, buffer, BUFFER_SIZE)) > 0)
{
write_count = write(to_fd, buffer, read_count);
if (write_count != read_count)
{
dprintf(STDERR_FILENO, WRITE_ERROR, argv[2]); close(from_fd);
close(to_fd); exit(99);
}
}
if (read_count == -1)
{
dprintf(STDERR_FILENO, READ_ERROR, argv[1]); close(from_fd);
close(to_fd); exit(98);
}
if (close(from_fd) == -1)
{
dprintf(STDERR_FILENO, CLOSE_ERROR, from_fd); close(to_fd);
exit(100);
}
if (close(to_fd) == -1)
{
dprintf(STDERR_FILENO, CLOSE_ERROR, to_fd); exit(100);
}
return (0);
}
