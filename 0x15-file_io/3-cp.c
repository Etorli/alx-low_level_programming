#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - this allocates 1024 bytes for a buffer.
 *
 * Return: pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer = malloc(BUFFER_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_file - Closes the file descriptors.
 * @fd: the file descriptor to be closed.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close file descriptor %d\n", fd);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Copies contents of file to another file.
 * @argc: number of arguments supplied to the program.
 * @argv: array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to;
	ssize_t r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	while ((r = read(from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(to, buffer, r);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

