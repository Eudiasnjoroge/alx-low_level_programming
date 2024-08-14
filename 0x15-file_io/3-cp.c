#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Prints error message to stderr.
 * @message: The error message to print.
 * @filename: The file name related to the error.
 * @exit_code: The exit code to use.
 */
void print_error(const char *message, const char *filename, int exit_code)
{
	if (filename)
		dprintf(STDERR_FILENO, message, filename);
	else
		dprintf(STDERR_FILENO, "%s", message);
	exit(exit_code);
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to\n", NULL, 97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		print_error("Error: Can't read from file %s\n", argv[1], 98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error("Error: Can't write to %s\n", argv[2], 99);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			print_error("Error: Can't write to %s\n", argv[2], 99);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error("Error: Can't read from file %s\n", argv[1], 98);
	}

	if (close(fd_from) == -1)
	{
		print_error("Error: Can't close fd %d\n", argv[1], 100);
	}
	if (close(fd_to) == -1)
	{
		print_error("Error: Can't close fd %d\n", argv[2], 100);
	}

	return (0);
}

