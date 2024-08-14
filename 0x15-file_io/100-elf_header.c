#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 *  * print_error - Prints error message and exits with a status code.
 *   * @message: The error message to print.
 *    * @status_code: The exit status code.
 *     */
void print_error(const char *message, int status_code)
{
	    dprintf(STDERR_FILENO, "%s", message);
	        exit(status_code);
}

/**
 *  * display_elf_header - Displays the ELF header information.
 *   * @elf: Pointer to the ELF header structure.
 *    */
void display_elf_header(const Elf64_Ehdr *elf)
{
	    printf("Magic:   %.2x %.2x %.2x %.2x\n",
			               elf->e_ident[EI_MAG0], elf->e_ident[EI_MAG1],
				                  elf->e_ident[EI_MAG2], elf->e_ident[EI_MAG3]);

	        printf("Class:                             ");
		    switch (elf->e_ident[EI_CLASS]) {
			            case ELFCLASS32: printf("ELF32\n"); break;
						             case ELFCLASS64: printf("ELF64\n"); break;
									              default: printf("Unknown\n"); break;
											           }

		        printf("Data:                              ");
			    switch (elf->e_ident[EI_DATA]) {
				            case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
							              case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
											        default: printf("Unknown\n"); break;
													     }

			        printf("Version:                           %d\n", elf->e_ident[EI_VERSION]);

				    printf("OS/ABI:                            ");
				        switch (elf->e_ident[EI_OSABI]) {
						        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
									            case ELFOSABI_HPUX: printf("HP-UX\n"); break;
													        case ELFOSABI_LINUX: printf("Linux\n"); break;
																             case ELFOSABI_SOLARIS: printf("Solaris\n"); break;
																				            case ELFOSABI_AIX: printf("AIX\n"); break;
																							               case ELFOSABI_IRIX: printf("IRIX\n"); break;
																											           case ELFOSABI_FREEBSD: printf("FreeBSD\n"); break;
																															          case ELFOSABI_TRU64: printf("Tru64 UNIX\n"); break;
																																		               case ELFOSABI_ARM: printf("ARM\n"); break;
																																						          case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
																																										            default: printf("Unknown\n"); break;
																																												         }

					    printf("ABI Version:                       %d\n", elf->e_ident[EI_ABIVERSION]);

					        printf("Type:                              ");
						    switch (elf->e_type) {
							            case ET_NONE: printf("None\n"); break;
										          case ET_REL: printf("REL (Relocatable file)\n"); break;
												               case ET_EXEC: printf("EXEC (Executable file)\n"); break;
															             case ET_DYN: printf("DYN (Shared object file)\n"); break;
																		          case ET_CORE: printf("CORE (Core file)\n"); break;
																					        default: printf("Unknown\n"); break;
																							     }

						        printf("Entry point address:               0x%lx\n", (unsigned long)elf->e_entry);
}

/**
 *  * main - Displays ELF header information.
 *   * @argc: The number of arguments.
 *    * @argv: The array of arguments.
 *     *
 *      * Return: Always 0 on success.
 *       */
int main(int argc, char *argv[])
{
	    int fd;
	        Elf64_Ehdr elf_header;
		    ssize_t bytes_read;

		        if (argc != 2)
				        print_error("Usage: elf_header elf_filename\n", 97);

			    fd = open(argv[1], O_RDONLY);
			        if (fd == -1)
					        print_error("Error: Can't open file\n", 98);

				    bytes_read = read(fd, &elf_header, sizeof(elf_header));
				        if (bytes_read < 0)
						        print_error("Error: Can't read file\n", 98);
					    if (bytes_read < (ssize_t)sizeof(elf_header))
						            print_error("Error: File too short\n", 98);

					        if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
							        print_error("Error: Not an ELF file\n", 98);

						    display_elf_header(&elf_header);

						        if (close(fd) == -1)
								        print_error("Error: Can't close file descriptor\n", 98);

							    return 0;
}

