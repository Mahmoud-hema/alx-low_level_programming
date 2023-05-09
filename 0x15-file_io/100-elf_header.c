#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void ch_e(unsigned char *e_id);
void pr_m(unsigned char *e_id);
void pr_c(unsigned char *e_id);
void pr_d(unsigned char *e_id);
void pr_v(unsigned char *e_id);
void pr_abi(unsigned char *e_id);
void pr_osabi(unsigned char *e_id);
void pr_t(unsigned int e_t, unsigned char *e_id);
void pr_e(unsigned long int e_e, unsigned char *e_id);
void cl_e(int e);
/**
* ch_e - Checks if a file is an ELF file.
* @e_id: A pointer to an array containing the ELF magic numbers.
* Description: If the file is not an ELF file - exit code 98.
*/
void ch_e(unsigned char *e_id)
{
int in;
for (in = 0; in < 4; in++)
{
if (e_id[in] != 127 && e_id[in] != 'E' &&
e_id[in] != 'L' && e_id[in] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}
/**
* pr_m - Prints the magic numbers of an ELF header.
* @e_id: A pointer to an array containing the ELF magic numbers.
* Description: Magic numbers are separated by spaces.
*/
void pr_m(unsigned char *e_id)
{
int in;
printf(" Magic: ");
for (in = 0; in < EI_NIDENT; in++)
{
printf("%02x", e_id[in]);
if (in == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}
/**
* pr_c - Prints the class of an ELF header.
* @e_id: A pointer to an array containing the ELF class.
*/
void pr_c(unsigned char *e_id)
{
printf(" Class: ");
switch (e_id[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("unknown: %x \n", e_id[EI_CLASS]);
}
}
/**
* pr_d - Prints the data of an ELF header.
* @e_id: A pointer to an array containing the ELF class.
*/
void pr_d(unsigned char *e_id)
{
printf(" Data: ");
switch (e_id[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("unknown: %x \n", e_id[EI_CLASS]);
}
}
/**
* pr_v - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void pr_v(unsigned char *e_id)
{
printf(" Version: %d", e_id[EI_VERSION]);
switch (e_id[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}
/**
* pr_osabi - Prints the OS/ABI of an ELF header.
* @e_id: A pointer to an array containing the ELF version.
*/
void pr_osabi(unsigned char *e_id)
{
printf(" OS/ABI: ");
switch (e_id[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("unknown: %x \n", e_id[EI_OSABI]);
}
}
/**
* pr_abi - Prints the ABI version of an ELF header.
* @e_id: A pointer to an array containing the ELF ABI version.
*/
void pr_abi(unsigned char *e_id)
{
printf(" ABI Version: %d\n", e_id[EI_ABIVERSION]);
}
/**
* pr_t - Prints the type of an ELF header.
* @e_t: The ELF type.
* @e_id: A pointer to an array containing the ELF class.
*/
void pr_t(unsigned int e_t, unsigned char *e_id)
{
if (e_id[EI_DATA] == ELFDATA2MSB)
e_t >>= 8;
printf(" Type: ");
switch (e_t)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("unknown: %x \n", e_t);
}
}
/**
* pr_e - Prints the entry point of an ELF header.
* @e_e: The address of the ELF entry point.
* @e_id: A pointer to an array containing the ELF class.
*/
void pr_e(unsigned long int e_e, unsigned char *e_id)
{
printf(" Entry point address: ");
if (e_id[EI_DATA] == ELFDATA2MSB)
{
e_e = ((e_e << 8) & 0xFF00FF00) |
((e_e >> 8) & 0xFF00FF);
e_e = (e_e << 16) | (e_e >> 16);
}
if (e_id[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_e);
else
printf("%#lx\n", e_e);
}
/**
* cl_e - Closes an ELF file.
* @e: The file descriptor of the ELF file.
* Description: If the file cannot be closed - exit code 98.
*/
void cl_e(int e)
{
if (close(e) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", e);
exit(98);
}
}
/**
* main - Displays the information contained in the
* ELF header at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
* Return: 0 on success.
* Description: If the file is not an ELF File or
* the function fails - exit code 98.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int a, x;
a = open(argv[1], O_RDONLY);
if (a == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
cl_e(a);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
x = read(a, header, sizeof(Elf64_Ehdr));
if (x == -1)
{
free(header);
cl_e(a);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}
ch_e(header->e_ident);
printf("ELF Header:\n");
pr_m(header->e_ident);
pr_c(header->e_ident);
pr_d(header->e_ident);
pr_v(header->e_ident);
pr_osabi(header->e_ident);
pr_abi(header->e_ident);
pr_t(header->e_type, header->e_ident);
pr_e(header->e_entry, header->e_ident);
free(header);
cl_e(a);
return (0);
}
