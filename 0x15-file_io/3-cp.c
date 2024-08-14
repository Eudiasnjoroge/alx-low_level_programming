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
 * open_file - Opens a file with specified flags and mode.
 * @filename: The name of the file.
 * @flags: The flags to open the file.
 * @mode: The file permissions to use if the file is created.
 *
 * Return: File descriptor on success, -1 on failure.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
		print_error("Error: Can't open file %s\n", filename, 98);
	return (fd);
}

/**
 * copy_file - Copies content from one file to another.
 * @fd_from: File descriptor of the source file.
 * @fd_to: File descriptor of the destination file.
 *
 * Return: 1 on success, -1 on failure.
 */
int copy_file(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			print_error("Error: Can't write to %s\n", NULL, 99);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error("Error: Can't read from file %s\n", NULL, 98);
	}

	return (1);
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

	if (argc != 3)
		print_error("Usage: cp file_from file_to\n", NULL, 97);

	fd_from = open_file(argv[1], O_RDONLY, 0);
	fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (copy_file(fd_from, fd_to) == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error("Error: Can't copy file\n", NULL, 99);
	}

	if (close(fd_from) == -1)
	print_error("Error: Can't close fd %d\n", argv[1], 100);
	if (close(fd_to) == -1)
	print_error("Error: Can't close fd %d\n", argv[2], 100);

	return (0);
}
