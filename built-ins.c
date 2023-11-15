#include "shell_main.h"


/**
 * exit_shell - This function handles argument for the built-in exit ommand
 * @status: integer used to exit the shell
 *
 */

void exit_shell(const char *status)
{
	char *endptr;
	int exit_status;

	if (status != NULL)
	{
		exit_status = strtol(status, &endptr, 10);
		if (*endptr != '\0')
		{
			fprintf(stderr, "exit: Illegal number: %s\n", status);
			return;
		}
		if (exit_status < 0)
		{
			fprintf(stderr, "exit: Illegal number: %s\n", status);
			return;
		}
		exit(2);
	}
	else
		exit(0);
}


/**
 * handle_cd - This function handles argument for the built-in exit ommand
 * @dir: directory to change to
 *
 */

void handle_cd(const char *dir)
{
	char cur_dir[256];
	char *home_dir;

	if (dir == NULL)
	{
		home_dir = _getenv("HOME");
		if (home_dir == NULL)
		{
			perror("HOME environment variable not set\n");
			return; }
		dir = home_dir;
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
		{
			perror("OLDPWD environment variable not set\n");
			return; }
	}
	if (getcwd(cur_dir, sizeof(cur_dir)) == NULL)
	{
		perror("Error getting current working directory");
		return;
	}
	if (_setenv("OLDPWD", cur_dir, 1) != 0)
	{
		perror("Error setting OLDPWD environment variable");
		return;
	}
	if (chdir(dir) != 0)
	{
		perror("Error changing directory");
		return;
	}
	if (_setenv("PWD", dir, 1) != 0)
	{
		perror("Error setting PWD environment variable");
		return;
	}
}
