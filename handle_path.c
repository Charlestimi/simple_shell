#include "shell_main.h"

#define MAX_CMD_COUNT 64

/**
 * cleanup - This helper function is used to free memomry
 * @cmd: string to free
 * @count: string count
 *
 */

void cleanup(char **cmd, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(cmd[i]);
	}
	free(cmd);
}



/**
 * handle_path - This function takes care of the PATH
 * @cmd: array to the path
 * @count: string count
 *
 */

void handle_path(char **cmd, int count)
{
	char *cmd_path = NULL;
	char *path = _getenv("PATH");
	char *path_tok = _strtok(path, ":");

	while (path_tok != NULL)
	{
		if (path_tok == NULL)
			break;
		cmd_path = (char *)malloc(_strlen(path_tok) + _strlen(cmd[0]) + 2);
		_strcpy(cmd_path, path_tok);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd[0]);

		if (access(cmd_path, X_OK) == 0)
		{
			execve(cmd_path, cmd, environ);
			perror("Execution failed");
			free(cmd_path);
			cleanup(cmd, count);
			exit(EXIT_FAILURE);
		}
		free(cmd_path);
		path_tok = _strtok(NULL, ":");
	}
	perror("./hsh");
	cleanup(cmd, count);
	exit(EXIT_FAILURE);
}



/**
 * main - entry point
 * @argc: argument count
 * @argv: array of argument
 *
 * Return: 0 Always
 */


int main(int argc, char **argv)
{
	char user_input[256];

	(void)argc, (void)argv;

	for (;;)
	{
		blinking_prompt();
		read_user_input(user_input, sizeof(user_input));
		exec_user_input(user_input);
	}

	return (0);
}
