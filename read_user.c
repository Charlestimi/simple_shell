#include "shell_main.h"

/**
 * read_user_input - This function reads user input
 * @user_input: inputted string
 * @len: length of string
 *
 */

void read_user_input(char *user_input, size_t len)
{
	ssize_t read;

	read = getline(&user_input, &len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Getline unsuccessful");
			exit(EXIT_FAILURE);
		}
	}

	len = _strlen(user_input);
	if (len > 0 && user_input[len - 1] == '\n')
		user_input[len - 1] = '\0';
}
