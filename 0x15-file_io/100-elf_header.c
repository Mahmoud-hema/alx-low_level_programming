#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
* main - displays the information contained in the ELF header at the start
* of an ELF file.
* @argc: number of arguments passed to the program
* @argv: array of arguments passed to the program
*
* Return: 0 on success, 98 on error
*/
int main(int argc, char **argv)
{
int fd;
ssize_t bytes_read;
Elf64_Ehdr header;
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]); exit(98);
}
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
exit(98);
}
bytes_read = read(fd, &header, sizeof(header));
if (bytes_read == -1)
{
close(fd);
dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
exit(98);
}
if (bytes_read != sizeof(header))
{
close(fd);
dprintf(STDERR_FILENO, "Error: File %s is too short\n", argv[1]);
exit(98);
}
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
{
close(fd);
dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
exit(98);
}
printf("Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", header.e_ident[i]); printf("\n");
printf("Class:                             ");
printf("%s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
printf("Data:                              ");
printf("%s\n", header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "2's complement, little endian");
printf("Version:                           ");
printf("%d%s\n", header.e_ident[EI_VERSION],
header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
printf("OS/ABI:                            ");
switch (header.e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V");
break;
case ELFOSABI_HPUX:
printf("HP-UX");
break;
case ELFOSABI_NETBSD:
printf("NetBSD");
break;
case ELFOSABI_LINUX:
printf("Linux");
break;
case ELFOSABI_SOLARIS:
printf("Sun Solaris");
break;
case ELFOSABI_IRIX:
printf("SGI Irix");
break;
case ELFOSABI_FREEBSD:
printf("FreeBSD");
break;
default:
printf("<unknown: %x>", header.e_ident[EI_OSABI]);
break;
}
printf("\n");
printf("ABI Version:                       ");
printf("%d\n", header.e_ident[EI_ABIVERSION]);
printf("Type:                              ");
switch (header.e_type)
{
case ET_NONE:
printf("NONE (No file type)");
break;
case ET_REL:
printf("REL (Relocatable file)");
break;
case ET_EXEC:
printf("EXEC (Executable file)");
break;
case ET_DYN:
printf("DYN (Shared object file)");
break;
case ET_CORE:
printf("CORE (Core file)");
break;
default:
printf("<unknown>: %x", header.e_type);
break;
}
printf("\n");
printf("Entry point address:               ");
printf("%#lx\n", header.e_entry);
close(fd);
return (0);
}
