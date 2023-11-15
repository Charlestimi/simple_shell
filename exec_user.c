#include "shell_main.h"

/**
 * exec_user_input - This function takes care of executing user input
 * @user_input: inputted command string
 *
 */

void exec_user_input(char *user_input)
{       pid_t baby_pid;
	int status, count = 0;
	char *token, **cmd = NULL;

	(void)user_input;

	token = _strtok(user_input, " ");
	while (token != NULL && count < MAX_CMD_COUNT - 1)
	{       cmd = _realloc(cmd, (count + 1) * sizeof(char *));
		cmd[count] = _strdup(token);
		count++;
		token = _strtok(NULL, " "); }
	cmd = _realloc(cmd, (count + 1) * sizeof(char *));
	cmd[count] = NULL;
	if (count > 0 && _strcmp(cmd[0], "exit") == 0)
	{
		if (count > 1)
			exit_shell(cmd[1]);
		else
			exit_shell(NULL);
		cleanup(cmd, count);
		return; }
	else if (count > 0 && _strcmp(cmd[0], "cd") == 0)
	{	handle_cd((count > 1) ? cmd[1] : NULL);
		cleanup(cmd, count);
		return; }
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
		cleanup(cmd, count); }
}
