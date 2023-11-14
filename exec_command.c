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

	perror("Command not found");
	cleanup(cmd, count);
	exit(EXIT_FAILURE);
}



/**
 * exec_user_input - This function takes care of executing user input
 * @user_input: inputted command string
 *
 */

void exec_user_input(char *user_input)
{       pid_t baby_pid;
        int status, count = 0;
        char *token, **cmd = NULL;

        token = _strtok(user_input, " ");
        while (token != NULL && count < MAX_CMD_COUNT - 1)
        {       cmd = _realloc(cmd, (count + 1) * sizeof(char *));
                cmd[count] = _strdup(token);
                count++;
                token = _strtok(NULL, " "); }
        cmd = _realloc(cmd, (count + 1) * sizeof(char *));
        cmd[count] = NULL;
        if (count > 0)
        {
                if (_strcmp(cmd[0], "exit") == 0)
                {       exit_shell((count > 1) ? cmd[1] : NULL);
                        cleanup(cmd, count);
                        return; }
                else if (_strcmp(cmd[0], "cd") == 0)
                {       handle_cd((count > 1) ? cmd[1] : NULL);
                        cleanup(cmd, count);
                        return; } }
        baby_pid = fork();
        if (baby_pid == -1)
        {       perror("Fork unsuccessful");
                exit(EXIT_FAILURE); }
        else if (baby_pid == 0)
        {
                if (count > 0 && cmd[0][0] == '/')
                {       execve(cmd[0], cmd, environ);
                        perror("Execution failed");
			cleanup(cmd, count);
                        exit(EXIT_FAILURE); }
                else
                        handle_path(cmd, count); }
        else
        {       waitpid(baby_pid, &status, 0);
                cleanup(cmd, count); 
	}
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
