#include "shell_main.h"


/**
 * _getline - custom get line function
 * @lineptr: pointer to memory
 * @n: line buffer size
 * @stream: the file stream the line is gotten from
 *
 * Return: number of characters read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char c;
	size_t num = 0;
	static char buff[BUFFER_SIZE];
	static size_t idx, B_read;

	(void)stream;
	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*lineptr == NULL || *n == 0)
		init_lineptr(lineptr, n);

	for (;;)
	{
		if (idx == B_read)
			fill_buff(buff, &idx, &B_read);

		while (idx < B_read)
		{
			c = buff[idx++];
			if (handle_char(c, lineptr, n, &num))
				return (num);
		}
	}
	return (num);
}


/**
 * init_lineptr - helper function
 * @lineptr: pointer to memory
 * @n: line buffer size
 *
 */

void init_lineptr(char **lineptr, size_t *n)
{
	*n = BUFFER_SIZE;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
}


/**
 * fill_buff - helper function to fill buff
 * @buff: pointer to memory
 * @idx: buffer index
 * @B_read: bytes read
 *
 */

void fill_buff(char *buff, size_t *idx, size_t *B_read)
{
	*B_read = read(STDIN_FILENO, buff, BUFFER_SIZE);
	if (*B_read <= 0)
	{
		if (*idx == 0)
			exit(-1);
	}
	*idx = 0;
}


/**
 * handle_chare - helper function to handle characters
 * @c: character to handle
 * @lineptr: pointer to memory
 * @n: line buffer size
 * @num: integer
 *
 * Return: 0 on success
 */

int handle_char(char c, char **lineptr, size_t *n, size_t *num)
{
	if (c == '\n')
	{
		(*lineptr)[*num] = '\0'; /* Null-terminate the string */
		return (1);
	}

	if (*num + 1 >= *n)
		realloc_lineptr(lineptr, n);

	(*lineptr)[*num++] = c;
	return (0);
}


/**
 * realloc_lineptr  - helper function to reallocate lineptr
 * @lineptr: pointer to memory
 * @n: line buffer size
 *
 */

void realloc_lineptr(char **lineptr, size_t *n)
{
	*n += BUFFER_SIZE;
	*lineptr = realloc(*lineptr, *n);
	if (*lineptr == NULL)
	{
		perror("Memory reallocation failed");
		exit(EXIT_FAILURE);
	}
}

