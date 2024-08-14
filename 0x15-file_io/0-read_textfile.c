#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "main.h"
#include <sys/stat.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters (bytes) it should and print
 *
 * Return: The actual number of letters it could read and print,
 *         or 0 if the file cannot be opened or read, if filename is NULL,
 *         or if write fails or does not write the expected number of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	close(fd);
	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);
	if (bytes_read != bytes_written)
		return (0);

	return (bytes_written);
}