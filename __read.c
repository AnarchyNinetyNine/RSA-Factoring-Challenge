#include "factors.h"

/**
 * read_textfile - A function that reads a text file and prints
 *                 it to the POSIX standard output.
 * @filename: A file pointer variable.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 */

char *read_textfile(const char *filename, size_t letters)
{
	int fd;        /* File descriptor */
	char *buffer;  /* Buffer to store data to be read */
	ssize_t bytes; /* Number of letter it could be read/printed */

	if (!filename || !letters) /* HAndle missing requirements */
		return (0);

	fd = open(filename, O_RDONLY);
	buffer = malloc(sizeof(char) * letters);

	/* HAndle failure on file opening */
	if (fd == -1 || !buffer)
		return (0);

	bytes = read(fd, buffer, letters);

	close(fd); /* close the file descriptor */
	/* free(buffer);  free the malloc'ed buffer */

	return (buffer);
}
